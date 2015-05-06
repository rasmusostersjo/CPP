#include "Driver.h"
#include "EnglishLanguage.h"
#include <iostream>             // cout, endl, cout
#include <string>               // string
#include <stdexcept>            // range_error
#include <cstdlib>              // atoi

void play(CardChallenge& c)
{
    if (c.play().newHighScore())
        std::cout << std::endl << S_NEW_HIGH_SCORE << std::endl;
    c.printLatestScore();
}

void viewScoreBoard(CardChallenge& c)
{
    std::cout << std::endl;
    c.viewScoreBoard();
    std::cout << std::endl << std::endl;
}

void changeLevel(CardChallenge& c)
{
    std::string level;

    std::cout << S_ENTER_LEVEL;
    std::cin  >> level;
    std::cin.clear();

    try {
        c.setLevel(atoi(level.c_str()));
        std::cout << S_LEVEL_SET_SUCCESS << std::endl << std::endl;
    }
    catch (std::range_error) {
        std::cerr << S_LEVEL_SET_FAIL << std::endl << std::endl;
    }
}

// TODO: Implement testing for nick name length
void changeNickName(CardChallenge& c)
{
    std::string nick;

    std::cout << S_ENTER_NICK << std::endl;
    std::cin  >> nick;
    std::cin.clear();
    std::cout << std::endl;

    c.setNick(nick);
}

void exitCardChallenge(void)
{
    std::cout << S_EXIT_MSG << std::endl;
}
