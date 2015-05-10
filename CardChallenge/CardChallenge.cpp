#include "CardChallenge.h"
#include "Exception.h"
#include "LanguageSettings.h"
#include "Helper.h"
#include <stdexcept>        // invalid_argument, range_error
#include <iostream>         // cout, cin, cerr, endl
#include <cstdlib>          // atoi
#include <iomanip>          // setprecision

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv, const std::string& n,
    const Scoreboard& sb)
    : deck(lv), scoreDeck(COLOR, JOKER, lv), nick(n),
    currentScore(0, 0, std::chrono::duration<double>(0), n),
    newHighscoreFlag(false)
{
    try {
        scoreboard.load();  // Attempt to load highscores
    }

    /*
     * Generated if the highscore file could not be read from; caused by:
     *      -- The file does not exist
     *      -- The file does not have read permission
     */
    catch (read_error) {

        try {
            scoreboard.save();  // Attempt to create new highscore file
        }

        // Could not write to the highscore file
        catch (write_error) {
            std::cerr << S_READ_WRITE_ERROR << std::endl << std::endl;
        }

        // Succeeded to create a new highscore file
        std::cout << S_READ_ERROR_WRITE_SUCCESS << std::endl << std::endl;
    }

    try {
        setNick(n);         // Attempt to set nickname
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_NICKNAME << std::endl << std::endl;
        nick = DEFAULT_NICK;
    }
}

CardChallenge& CardChallenge::play(void)
{
    std::cout << S_START;
    deck.shuffle();
    helper::readENTER();
    helper::clearScreen();

    // Let user view all cards once and clock the entire view process
    std::chrono::time_point<std::chrono::system_clock> t1, t2;
    t1 = std::chrono::system_clock::now();
    view();
    t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> t = t2 - t1;

    // Let user restate all cards
    for (size_t i = 0; i < deck.size(); ++i)
        stateCard(i);

    // Let user restate cards by index
    std::cout << std::endl << Q_ANY_RESTATES;
    bool restate;
    do {
        std::string card_i;

        if ( (restate = helper::yes_no()) ) {
            std::cout << S_RESTATE_CARD_INDEX;
            std::cin >> card_i;
            try {
                // stateCard indexes its first element by 0 and not 1; hence -1
                stateCard(atoi(card_i.c_str()) - 1);
            }
            catch (std::range_error) {
                std::cerr << S_INVALID_CARD_INDEX << std::endl;
            }
            std::cout << Q_RESTATE_ANY_OTHER_CARD;
        }

    } while(restate);

    // Update score
    currentScore = Score(deck.size(), computeScore(), t, nick);
    if (scoreboard.update(currentScore))
        newHighscoreFlag = true;
    scoreboard.save();

    return *this;
}

const CardChallenge& CardChallenge::viewScoreboard(void) const noexcept
{
    scoreboard.print();
    return *this;
}

const CardChallenge& CardChallenge::printLatestScore(void) const noexcept
{
    // No score
    if (!currentScore.getScore() && !currentScore.getLevel() && 
        !currentScore.getTime().count())
        std::cout << S_NO_SCORE << std::endl;

    else {
        // Print results
        std::cout << std::endl << S_YOUR_SCORE << currentScore.getScore()
                  << S_LEVEL_SCORE_SEP << currentScore.getLevel() << std::endl
                  << S_YOUR_TIME << std::setprecision(TIME_PRECISION)
                  << currentScore.getTime().count() << S_TIME_UNIT << std::endl
                  << std::endl << Q_REVEAL_SOLUTION;

        // Reveal the entire solution
        if (helper::yes_no()) {
            std::cout << std::endl;
            deck.print();
        }
        std::cout << std::endl;
    }

    return *this;
}

bool CardChallenge::newHighscore(void) const noexcept
{
    return newHighscoreFlag;
}

CardChallenge& CardChallenge::shuffle(void) noexcept
{
    deck.shuffle();
    return *this;
}

CardChallenge& CardChallenge::setLevel(size_t lv)
{
    if (lv == 0)
        throw std::range_error("CardChallenge::setLevel");

    // Resize decks, reset currentScore and newHighscore
    deck = Deck(lv);
    scoreDeck = Deck(COLOR, JOKER, lv);
    currentScore.update(Score(0, 0, std::chrono::duration<double>(0), nick));
    newHighscoreFlag = false;

    return *this;
}

CardChallenge& CardChallenge::setNick(const std::string& n)
{
    if (!n.size() || n.size() > NICK_WIDTH - 1 || !helper::validNick(n))
        throw std::invalid_argument("CardChallenge::setNick");

    nick = n;
    return *this;
}

CardChallenge& CardChallenge::setHighscoreFile(const std::string& hsf)
{
    scoreboard.rename(hsf);
    return *this;
} 

size_t CardChallenge::getLevel(void) const noexcept
{
    return deck.size();
}

const std::string& CardChallenge::getNick(void) const noexcept
{
    return nick;
}

const Score& CardChallenge::getScore(void) const noexcept
{
    return currentScore;
}

const CardChallenge& CardChallenge::view(void) const noexcept
{
    for (size_t i = 0; i < deck.size(); ++i) {
        deck.print(i);
        helper::readENTER();
        helper::clearScreen();
    }

    return *this;
}

const CardChallenge& CardChallenge::view(size_t i) const
{
    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::view");

    deck.print(i);
    helper::readENTER();
    helper::clearScreen();

    return *this;
}

CardChallenge& CardChallenge::stateCard(size_t i)
{
    std::string c, v;
    Color color;
    Value value;

    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::stateCard");

    std::cout << S_STATE_CARD << i + 1 << ": ";

#ifdef USE_ENGLISH

    std::cin  >> v >> c;

#else /* USE_SWEDISH */

    std::cin >> c >> v;

#endif

    // Update scoreDeck
    color = helper::transformColor(c);
    value = helper::transformValue(v);
    scoreDeck.getCard(i).setColor(color).setValue(value);

    return *this;
}

size_t CardChallenge::computeScore(void) noexcept
{
    size_t s = 0;
    size_t n = deck.size() < scoreDeck.size() ? deck.size() : scoreDeck.size();

    for (size_t i = 0; i < n; ++i)
        if (deck.getCard(i) == scoreDeck.getCard(i))
            ++s;

    return s;
}
