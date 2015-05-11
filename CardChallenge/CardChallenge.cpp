#include "CardChallenge.h"
#include "Exception.h"
#include "LanguageSettings.h"
#include "Helper.h"
#include <stdexcept>        // invalid_argument, range_error
#include <iostream>         // cout, cin, cerr, endl
#include <cstdlib>          // atoi
#include <iomanip>          // setprecision
#include <fstream>          // to attempt opening file

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv, const std::string& n)
    : deck(lv), scoreDeck(0), nick(n), newHighscoreFlag(false)
{
    // Attempt to load highscore file
    try {
        scoreboard.load();
    }
    catch (read_error) {
        std::ofstream newFile(scoreboard.getHighscoreFile(),
            std::ios::out | std::ios::trunc);
        if (!newFile.is_open())
            std::cerr << S_READ_WRITE_ERROR << std::endl << std::endl;
        else
            std::cout << S_READ_ERROR_WRITE_SUCCESS << std::endl << std::endl;
    }

    // Attempt to set nick name
    try {
        setNick(n);
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_NICKNAME << std::endl << std::endl;
        nick = DEFAULT_NICK;
    }
}

CardChallenge& CardChallenge::play(void)
{
    size_t i;
    bool restate;

    std::cout << S_START;
    deck.shuffle();
    scoreDeck.clear();      // no restatements yet
    helper::readENTER();
    helper::clearScreen();

    // Let user view all cards once and clock the entire view process
    std::chrono::time_point<std::chrono::system_clock> t1, t2;
    t1 = std::chrono::system_clock::now();
    view();
    std::chrono::duration<double> t = std::chrono::system_clock::now() - t1;

    // Let user restate all cards (insertion can never throw here)
    for (i = 0; i < deck.size(); ++i)
        scoreDeck.insertCard(i, helper::stateCard(i + 1));

    // Let user restate cards by index (i.e. change restatements)
    std::cout << std::endl << Q_ANY_RESTATES;
    do {
        if ( (restate = helper::yes_no()) ) {
            std::cout << S_RESTATE_CARD_INDEX;
            try {
                if ( (i = helper::getSize_t() - 1) >= scoreDeck.size() )
                    throw std::range_error("CardChallenge::play");
                scoreDeck.insertCard(i, helper::stateCard(i + 1));
                scoreDeck.removeCard(i + 1);
            }
            catch (std::invalid_argument) {
                std::cerr << S_INVALID_SIZE_T << std::endl;
            }
            catch (std::range_error) {
                std::cerr << S_INVALID_CARD_INDEX << std::endl;
            }
            std::cout << Q_RESTATE_ANY_OTHER_CARD;
        }
    } while(restate);

    // Update score
    currentScore = helper::computeScore(deck, scoreDeck, t, nick);
    newHighscoreFlag = scoreboard.update(currentScore)? true : false;
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
    if (currentScore.isEmpty())
        std::cout << S_NO_SCORE << std::endl;

    else // print results
        std::cout << std::endl << S_YOUR_SCORE << currentScore.getScore()
                  << S_LEVEL_SCORE_SEP << currentScore.getLevel() << std::endl
                  << S_YOUR_TIME << std::setprecision(TIME_PRECISION)
                  << currentScore.getTime().count() << S_TIME_UNIT << std::endl
                  << std::endl;

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

    deck = Deck(lv);                // resize play play deck
    scoreDeck.clear();              // reset score deck
    currentScore = Score();         // reset current socre
    newHighscoreFlag = false;       // no new highscore yet

    return *this;
}

CardChallenge& CardChallenge::setNick(const std::string& n)
{
    if (!helper::validNick(n, NICK_WIDTH - 1))
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

const std::string CardChallenge::getHighscoreFile(void) const noexcept
{
    return scoreboard.getHighscoreFile();
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
