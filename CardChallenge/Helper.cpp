#include "Helper.h"
#include "Constants.h"
#include "EnglishLanguage.h"
#include <cstdlib>              // system
#include <iostream>             // cout, cin, cerr
#include <string>               // string

void menu(void)
{
    std::cout << S_STARS    << std::endl
              << S_OPTION_1 << std::endl
              << S_OPTION_2 << std::endl
              << S_OPTION_3 << std::endl
              << S_OPTION_4 << std::endl
              << S_OPTION_5 << std::endl
              << S_STARS    << std::endl;
}

int getChoice(void)
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

void readENTER(void)
{
    while (std::cin.get() != '\n')
        ;
}

void clearScreen(void)
{
    system("clear");
}

bool yes_no(void)
{
    int c;

    while ((c = std::cin.get()) != S_LOWER_YES && c != S_UPPER_YES &&
        c != S_LOWER_NO && c != S_UPPER_NO)
        ;
    readENTER();

    return (c == S_LOWER_YES || c == S_UPPER_YES)? true : false;
}

Color transformColor(const std::string& c)
{
    switch (*c.c_str()) {
        case RESTATE_HEARTS:   return HEARTS;   break;
        case RESTATE_CLUBS:    return CLUBS;    break;
        case RESTATE_DIAMONDS: return DIAMONDS; break;
        case RESTATE_SPADES:   return SPADES;   break;
    }

    return COLOR;   // invalid
}

Value transformValue(const std::string& v)
{
    switch (*v.c_str()) {
        case RESTATE_ACE:   return ACE;   break;
        case RESTATE_TWO:   return TWO;   break;
        case RESTATE_THREE: return THREE; break;
        case RESTATE_FOUR:  return FOUR;  break;
        case RESTATE_FIVE:  return FIVE;  break;
        case RESTATE_SIX:   return SIX;   break;
        case RESTATE_SEVEN: return SEVEN; break;
        case RESTATE_EIGHT: return EIGHT; break;
        case RESTATE_NINE:  return NINE;  break;
        case RESTATE_TEN:   return TEN;   break;
        case RESTATE_JACK:  return JACK;  break;
        case RESTATE_QUEEN: return QUEEN; break;
        case RESTATE_KING:  return KING;  break;
        case RESTATE_JOKER: return JOKER; break;
    }

    return VALUE; // invalid
}
