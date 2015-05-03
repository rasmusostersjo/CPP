#include "Card.h"
#include <iostream>     // cout

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
    std::cout << colorTable[color] << " " << valueTable[value] << std::endl;
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

Card& Card::setColor(const Color& c) noexcept
{
    color = c;
    return *this;
}

Card& Card::setValue(const Value& v) noexcept
{
    value = v;
    return *this;
}

bool Card::operator==(const Card& c)
{
    return color == c.color && value == c.value;
}
