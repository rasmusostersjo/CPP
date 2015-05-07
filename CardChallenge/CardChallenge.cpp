#include "CardChallenge.h"
#include "Exception.h"
#include "LanguageSettings.h"
#include "Helper.h"
#include <stdexcept>        // invalid_argument
#include <iostream>         // cout, cin, cerr, endl
#include <cstdlib>          // atoi
#include <iomanip>          // setprecision

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv, const std::string& n,
    const ScoreBoard& sb)
    : deck(lv), scoreDeck(COLOR, JOKER, lv), nick(n),
    currentScore(0, 0, std::chrono::duration<double>(0), n),
    newHighScoreFlag(false)
{
    try {
        setNick(n);         // Attempt to set nick name
        scoreBoard.load();  // Attempt to load high scores
    }
    catch (read_error) {
        try {
            scoreBoard.save();  // create the high score file
        }
        catch (write_error) {
            std::cerr << std::endl << S_READ_WRITE_ERROR << std::endl
                      << std::endl;
        }
        std::cout << std::endl << S_READ_ERROR_WRITE_SUCCESS << std::endl
                  << std::endl;
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_NICK_NAME << std::endl << std::endl;
    }
}

CardChallenge& CardChallenge::shuffle(void) noexcept
{
    deck.shuffle();
    return *this;
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

CardChallenge& CardChallenge::play(void) noexcept
{
    std::cout << S_START;
    deck.shuffle();
    helper::readENTER();
    helper::clearScreen();

    // Let user view all cards once and store the times used
    std::chrono::time_point<std::chrono::system_clock> t1, t2;
    t1 = std::chrono::system_clock::now();
    view();
    t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> t = t2 - t1;

    // let user re state all cards
    for (size_t i = 0; i < deck.size(); ++i)
        stateCard(i);

    // Let user re state cards by index
    std::cout << std::endl << Q_ANY_RESTATES;
    bool reState;
    do {
        std::string card_i;

        if ( (reState = helper::yes_no()) ) {
            std::cout << S_RESTATE_CARD_INDEX;
            std::cin >> card_i;
            try {
                stateCard(atoi(card_i.c_str()) - 1);  // stateCard index from 0
            }
            catch (std::range_error) {
                std::cerr << S_INVALID_CARD_INDEX << std::endl;
            }
            std::cout << Q_RESTATE_ANY_OTHER_CARD;
        }

    } while(reState);

    // Update score
    currentScore = Score(deck.size(), computeScore(), t, nick);
    if (scoreBoard.update(currentScore))
        newHighScoreFlag = true;
    scoreBoard.save();

    return *this;
}

const CardChallenge& CardChallenge::viewScoreBoard(void) const noexcept
{
    scoreBoard.print();
    return *this;
}

CardChallenge& CardChallenge::setLevel(size_t lv)
{
    if (lv == 0)
        throw std::range_error("CardChallenge::setLevel");

    // Resize decks and reset current score
    deck = Deck(lv);
    scoreDeck = Deck(COLOR, JOKER, lv);
    currentScore.update(Score(0, 0, std::chrono::duration<double>(0), nick));
    newHighScoreFlag = false;

    return *this;
}

CardChallenge& CardChallenge::setNick(const std::string& n)
{
    if (n.size() > NICK_WIDTH - 1)
        throw std::invalid_argument("CardChallenge::setNick");

    nick = n;
    return *this;
}

const std::string& CardChallenge::getNick(void) const noexcept
{
    return nick;
}

size_t CardChallenge::getLevel(void) const noexcept
{
    return deck.size();
}

const Score& CardChallenge::getScore(void) const noexcept
{
    return currentScore;
}

const CardChallenge& CardChallenge::printLatestScore(void) const noexcept
{
    // No score
    if (!currentScore.getScore() && !currentScore.getLevel() && 
        !currentScore.getTime().count())
        std::cout << S_NO_SCORE << std::endl;

    // Print score and reveal solution if user wants to
    else {
        std::cout << std::endl << S_YOUR_SCORE << currentScore.getScore()
                  << S_LEVEL_SCORE_SEP << currentScore.getLevel() << std::endl
                  << S_YOUR_TIME << std::setprecision(TIME_PRECISION)
                  << currentScore.getTime().count() << S_TIME_UNIT << std::endl
                  << std::endl << Q_REVEAL_SOLUTION;
        if (helper::yes_no()) {
            std::cout << std::endl;
            deck.print();
        }
        std::cout << std::endl;
    }

    return *this;
}

bool CardChallenge::newHighScore(void) const noexcept
{
    return newHighScoreFlag;
}

CardChallenge& CardChallenge::setHighScoreFile(const std::string& hsf)
{
    try {
        scoreBoard.rename(hsf);
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_HS_FILE << std::endl;
    }

    return *this;
} 
