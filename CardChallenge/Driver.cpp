#include "Driver.h"
#include "Exception.h"
#include "LanguageSettings.h"
#include "Helper.h"
#include <iostream>             // cout, endl, cout, cerr
#include <string>               // string, getline
#include <stdexcept>            // range_error
#include <cstdlib>              // atoi
#include <climits>              // numeric_limits

///////////////////////////// Driver ///////////////////////////////////////////

void driver::play(CardChallenge& c)
{
    try {
        if (c.play().newHighscore())
            std::cout << std::endl << S_NEW_HIGHSCORE << std::endl;
        c.printLatestScore();
    }
    catch (write_error) {
        std::cout << S_SAVE_ERROR << std::endl << std::endl;
    }
}

void driver::viewScoreboard(CardChallenge& c)
{
    std::cout << std::endl;
    c.viewScoreboard();
    std::cout << std::endl << std::endl;
}

void driver::viewCurrentSettings(const CardChallenge& c)
{
    std::cout << "Nickname:       " << c.getNick()          << std::endl
              << "Level:          " << c.getLevel()         << std::endl
              << "Highscore file: " << c.getHighscoreFile() << std::endl
              << std::endl;
}

void driver::changeLevel(CardChallenge& c)
{
    std::cout << S_ENTER_LEVEL;
    try {
        c.setLevel(helper::getSize_t());
        std::cout << S_LEVEL_SET_SUCCESS << std::endl << std::endl;
    }
    catch (std::range_error) {
        std::cerr << S_LEVEL_SET_FAIL << std::endl << std::endl;
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_SIZE_T << std::endl << std::endl;
    }
}

void driver::changeNickname(CardChallenge& c)
{
    std::string nick;

    std::cout << S_ENTER_NICK;
    std::getline(std::cin, nick);
    std::cout << std::endl;
    
    try {
        c.setNick(nick);
    }
    catch (std::invalid_argument) {
        std::cerr << S_INVALID_NICKNAME << std::endl << std::endl;
    }
}

void driver::changeHighscoreFile(CardChallenge& c)
{
    std::string hsf;

    std::cout << S_ENTER_HSF;
    std::getline(std::cin, hsf);

    try {
        c.setHighscoreFile(hsf);
        std::cout << S_VALID_HSF << std::endl << std::endl;
    }
    catch (std::invalid_argument) {
        std::cout << S_INVALID_HSF << std::endl << std::endl;
    }
}

void driver::menu(void)
{
    std::cout << S_STARS    << std::endl
              << S_OPTION_1 << std::endl
              << S_OPTION_2 << std::endl
              << S_OPTION_3 << std::endl
              << S_OPTION_4 << std::endl
              << S_OPTION_5 << std::endl
              << S_OPTION_6 << std::endl
              << S_OPTION_7 << std::endl
              << S_STARS    << std::endl;
}

int driver::getChoice(void)
{
    std::string c;

    // Let user choose a menu option
    std::cout << S_ENTER_CHOICE;
    std::getline(std::cin, c);

    int choice = *c.c_str() - '0';
    if (choice < FIRST_OPTION || choice > LAST_OPTION) {
        std::cerr << S_INVALID_CHOICE << std::endl;
        return INVALID_CHOICE;
    }

    return choice;
}

void driver::exitCardChallenge(void)
{
    std::cout << std::endl << S_EXIT_MSG << std::endl << std::endl;
}
