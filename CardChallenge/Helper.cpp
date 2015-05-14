#include "Helper.h"
#include "Constants.h"
#include "LanguageSettings.h"
#include <iostream>             // cin
#include <cctype>               // isalnum
#include <algorithm>            // find_if
#include <climits>              // std::numeric_limits

///////////////////////////// Helper ///////////////////////////////////////////

void helper::readENTER(void)
{
    while (std::cin.get() != '\n')
        ;
}

void helper::clearScreen(void)
{
    for (size_t i = 0; i < CLEAR_SCREEN; ++i)
        std::cout << std::endl;
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

size_t helper::getSize_t(void)
{
    // Read user input
    std::string input;
    std::getline(std::cin, input);

    const char* str   = input.c_str();
    size_t      ret   = 0;
    int         valid = 1;
    int         sign  = 0;

    // Handle optional sign (throw later if negative)
    if (*str == '-' || *str == '+')
        sign = *str++;
    
    // Convert to size_t
    for (; valid && *str && isdigit(*str); ++str) {
        int dig = *str - '0';
        if ( ret      <= std::numeric_limits<size_t>::max() / 10 &&
             ret * 10 <= std::numeric_limits<size_t>::max() - dig)
            ret = ret * 10 + dig;

        else /* overflow */
            valid = 0;
    }

    if (!valid || sign == '-' || *str)
        throw std::invalid_argument("helper::getSize_t");

    return ret;
}

bool helper::validNick(const std::string& n, size_t max)
{
    auto Empty = [](int c) { return c != ' '; };
    if (n.size() > max || std::find_if(n.begin(), n.end(), Empty) == n.end())
        return false;

    auto Inv = [](int c) { return !(std::isalnum(c) || c == ' ' || c == '_'); };
    return std::find_if(n.begin(), n.end(), Inv) == n.end();
}

Card helper::stateCard(size_t index)
{
    std::string c, v;
    std::cout << S_STATE_CARD << index << ": ";

#ifdef USE_ENGLISH
    std::cin >> v >> c;
#else /* USE_SWEDISH */
    std::cin >> c >> v;
#endif

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

    return Card(helper::transformColor(c), helper::transformValue(v));
}

Score helper::computeScore(const Deck& pd, const Deck& sd,
    const std::chrono::duration<double>& t, const std::string& nick)
{
    size_t s = 0;
    size_t n = pd.size() < sd.size() ? pd.size() : sd.size();

    // Compute score
    for (size_t i = 0; i < n; ++i)
        if (pd.getCard(i) == sd.getCard(i))
            ++s;

    return Score(pd.size(), s, t, nick);
}
