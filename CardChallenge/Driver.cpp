#include "Driver.h"
#include "EnglishLanguage.h"
#include <iostream>             // cout, endl, cout, cerr
#include <string>               // string
#include <stdexcept>            // range_error
#include <cstdlib>              // atoi, system

void driver::menu(void)
{
    std::cout << S_STARS    << std::endl
              << S_OPTION_1 << std::endl
              << S_OPTION_2 << std::endl
              << S_OPTION_3 << std::endl
              << S_OPTION_4 << std::endl
              << S_OPTION_5 << std::endl
              << S_STARS    << std::endl;
}

int driver::getChoice(void)
{
    std::string c;

    // Let user choose a menu option
    std::cout << S_ENTER_CHOICE;
    std::cin  >> c;
    std::cin.clear();

    int choice = *c.c_str() - '0';
    if (choice < FIRST_OPTION || choice > LAST_OPTION) {
        std::cerr << S_INVALID_CHOICE << std::endl;
        return INVALID_CHOICE;
    }

    return choice;
}

void driver::play(CardChallenge& c)
{
    if (c.play().newHighScore())
        std::cout << std::endl << S_NEW_HIGH_SCORE << std::endl;
    c.printLatestScore();
}

void driver::viewScoreBoard(CardChallenge& c)
{
    std::cout << std::endl;
    c.viewScoreBoard();
    std::cout << std::endl << std::endl;
}

void driver::changeLevel(CardChallenge& c)
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
void driver::changeNickName(CardChallenge& c)
{
    std::string nick;

    std::cout << S_ENTER_NICK << std::endl;
    std::cin  >> nick;
    std::cin.clear();
    std::cout << std::endl;

    c.setNick(nick);
}

void driver::exitCardChallenge(void)
{
    std::cout << S_EXIT_MSG << std::endl;
}
