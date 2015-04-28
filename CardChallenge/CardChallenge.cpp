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

/** yes_no
 * Lets the user enter yes (y, Y) or no (n, N).
 * 
 * @return          1 to signal yes; else 0.
 */
static bool yes_no(void)
{
    int c;

    while ((c = std::cin.get()) != 'y' && c != 'Y' && c != 'n' && c != 'N')
        ;
    readENTER(); 

    return (c == 'y' || c == 'Y')? 1 : 0;
}

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv)
    : deck(lv), scoreDeck(lv)
{
    // Initialliy scoreDeck contains only jokers
    for (size_t i = 0; i < scoreDeck.size(); ++i)
        scoreDeck.getCard(i).setColor(COLOR).setValue(JOKER);
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
        readENTER();
        clearScreen();
    }

    return *this;
}

const CardChallenge& CardChallenge::view(size_t i) const
{
    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::view");

    deck.print(i);
    readENTER();
    clearScreen();

    return *this;
}

CardChallenge& CardChallenge::stateCard(size_t i)
{
    std::string c, v;
    Color color;
    Value value;

    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::stateCard");

    std::cout << "State card " << i + 1 << ": ";
    std::cin  >> c >> v;

    // Update scoreDeck
    color = transformColor(c);
    value = transformValue(v);
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
    std::cout << "Press ENTER to start.";
    readENTER();
    clearScreen();

    // Let user view all cards once
    view();

    // let user re state all cards
    for (size_t i = 0; i < deck.size(); ++i)
        stateCard(i);

    // Let user re state cards by index
    std::cout << std::endl << "Do you want to re state any card? (y/n) ";
    bool reState;
    do {
        size_t card_i;

        if ( (reState = yes_no()) ) {
            std::cout << "Enter which card to restate: ";
            std::cin >> card_i;
            try {
                stateCard(card_i - 1);  // stateCard index from 0
            }
            catch (std::range_error) {
                std::cerr << "Invalid card index." << std::endl;
            }
            std::cout << "Do you want to re state any other card? (y/n) ";
        }

    } while(reState);

    // Print results
    std::cout << std::endl << "\tYour score: " << computeScore() << "/"
              << deck.size() << std::endl << std::endl
              << "Do you want to reveal the entire solution? (y/n) ";
    if (yes_no())
        deck.print();

    return *this;
}
