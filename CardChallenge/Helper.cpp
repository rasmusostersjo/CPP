#include "Helper.h"
#include "Constants.h"
#include "EnglishLanguage.h"
#include <iostream>             // cin
#include <string>               // string

void helper::readENTER(void)
{
    while (std::cin.get() != '\n')
        ;
}

void helper::clearScreen(void)
{
    system("clear");
}

bool helper::yes_no(void)
{
    int c;

    while ((c = std::cin.get()) != S_LOWER_YES && c != S_UPPER_YES &&
        c != S_LOWER_NO && c != S_UPPER_NO)
        ;
    readENTER();

    return (c == S_LOWER_YES || c == S_UPPER_YES)? true : false;
}

Color helper::transformColor(const std::string& c)
{
    switch (*c.c_str()) {
        case RESTATE_HEARTS:   return HEARTS;   break;
        case RESTATE_CLUBS:    return CLUBS;    break;
        case RESTATE_DIAMONDS: return DIAMONDS; break;
        case RESTATE_SPADES:   return SPADES;   break;
    }

    return COLOR;   // invalid
}

Value helper::transformValue(const std::string& v)
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
