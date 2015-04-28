#include "Card.h"
#include <iostream>     // cout
#include <algorithm>    // foreach, shuffle
#include <stdexcept>    // range_error

/** Table to print card colors
 */
static const char* colorTable[COLOR + 1] {
    "Hearts",
    "Clubs",
    "Spades",
    "Diamonds",
    "" /* No color */
};

/** Table ot print card values
 */
static const char* valueTable[VALUE + 1] {
    "Ace",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "Jack",
    "Queen",
    "King",
    "Joker",
    "" /* No value */
};

///////////////////////////// Card /////////////////////////////////////////////

Card::Card(void)
    : color(COLOR), value(JOKER)
{
}

Card::Card(const Color& c, const Value& v)
    : color(c), value(v)
{
}

const Card& Card::view(void) const noexcept
{
    std::cout << valueTable[value] << " " << colorTable[color] << std::endl;
    return *this;
}

const Color& Card::getColor(void) const noexcept
{
    return color;
}

const Value& Card::getValue(void) const noexcept
{
    return value;
}

const Card& Card::setColor(const Color& c) noexcept
{
    color = c;
    return *this;
}

const Card& Card::setValue(const Value& v) noexcept
{
    value = v;
    return *this;
}

///////////////////////////// Deck /////////////////////////////////////////////

Deck::Deck(size_t n)
    : deck(n)
{
    Value v = ACE;
    Color c = HEARTS;

    std::for_each(deck.begin(), deck.end(), [&v, &c](Card& k) {

        // Initialize card
        k.setValue(v);
        k.setColor(c);

        // Increment value and color in cycles; dont assign jokers
        if ( (v = Value((v + 1) % (VALUE - 1))) == 0 )
            c = Color( (c + 1) % COLOR );
    });
}

const Deck& Deck::print(void) const noexcept
{
    std::for_each(deck.begin(), deck.end(), [](Card k) { k.view(); });
    return *this;
}

const Deck& Deck::print(size_t index) const
{
    if (index >= deck.size())
        throw std::range_error("Error: Deck::print");

    deck[index].view();
    return *this;
}

const Card& Deck::getCard(size_t index) const
{
    if (index >= deck.size())
        throw std::range_error("Error: Deck::getCard");

    return deck[index];
}

Deck& Deck::shuffle(void) noexcept
{
    std::random_shuffle(deck.begin(), deck.end());
    return *this;
}

size_t Deck::size(void) const noexcept
{
    return deck.size();
}
