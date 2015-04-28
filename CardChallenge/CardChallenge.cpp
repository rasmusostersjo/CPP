#include "CardChallenge.h"
#include <vector>           // vector
#include <algorithm>        // for_each
#include <string>           // string
#include <iostream>         // cout, cin
#include <cstdlib>          // system

////////////////////////// static helper functions /////////////////////////////

static void readENTER(void)
{
    while (std::cin.get() != '\n')
        ;
}

static void clearScreen(void)
{
    system("clear");
}

static Color transformColor(const std::string& c)
{
    switch (*c.c_str()) {
        case 'h': return HEARTS;   break;
        case 'c': return CLUBS;    break;
        case 'd': return DIAMONDS; break;
        case 's': return SPADES;   break;
    }

    return COLOR;   // invalid
}

static Value transformValue(const std::string& v)
{
    switch (*v.c_str()) {
        case 'a': return ACE;   break;
        case '2': return TWO;   break;
        case '3': return THREE; break;
        case '4': return FOUR;  break;
        case '5': return FIVE;  break;
        case '6': return SIX;   break;
        case '7': return SEVEN; break;
        case '8': return EIGHT; break;
        case '9': return NINE;  break;
        case '1': return TEN;   break;
        case 'j': return JACK;  break;
        case 'q': return QUEEN; break;
        case 'k': return KING;  break;
    }

    return JOKER; // invalid
}

static bool updateScore(const Card& c, Color color, Value value)
{
    return c.getColor() == color && c.getValue() == value;
}

size_t computeScore(std::vector<bool> s)
{
    size_t score = 0;
    std::for_each(s.begin(), s.end(), [&score](bool b) { if (b) ++score; } );
    return score;
}

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv)
    : deck(lv)
{
    deck.shuffle();
}

const CardChallenge& CardChallenge::play(void) const noexcept
{
    std::vector<bool> score(deck.size());

    std::cout << "Card Challenge started; Press ENTER to continue.";
    readENTER();
    clearScreen();

    // View the entire deck
    for (size_t i = 0; i < deck.size(); ++i) {
        deck.print(i);
        readENTER();
        clearScreen();
    }
    
    std::cout << "State the cards in the right order! (<c> <v>)" << std::endl;
    for (size_t i = 0; i < deck.size(); ++i) {
        std::string c, v;
        Color color;
        Value value;

        // State next card
        std::cout << "State card " << i + 1 << ": ";
        std::cin  >> c >> v;

        // Update score
        color = transformColor(c);
        value = transformValue(v);
        score[i] = updateScore(deck.getCard(i), color, value);
    }

    // Show results
    std::string ans;
    std::cout << std::endl << "\tYour score: " << computeScore(score) << "/"
              << deck.size() << std::endl << std::endl;

    return *this;
}
