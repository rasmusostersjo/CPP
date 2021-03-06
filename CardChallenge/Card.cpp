#include "Card.h"
#include "LanguageSettings.h"
#include <iostream>             // cout, endl

/** Table to print card colors
 */
static const char* colorTable[COLOR + 1] {
    COLOR_HEARTS, COLOR_CLUBS, COLOR_SPADES, COLOR_DIAMONDS, COLOR_NO_COLOR
};

/** Table to print card values
 */
static const char* valueTable[VALUE + 1] {
    VALUE_ACE,   VALUE_TWO,   VALUE_THREE, VALUE_FOUR, VALUE_FIVE, VALUE_SIX,
    VALUE_SEVEN, VALUE_EIGHT, VALUE_NINE,  VALUE_TEN,  VALUE_JACK, VALUE_QUEEN,
    VALUE_KING,  VALUE_JOKER, VALUE_NO_VALUE
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
#ifdef USE_ENGLISH

    // Print value, then color (if any)
    std::cout << valueTable[value];
    if (color != COLOR)
        std::cout << COLOR_VALUE_SEPARATE << colorTable[color];
    std::cout << std::endl;

#else /* USE_SWEDISH */

    // Print color (if any), then value
    if (color != COLOR)
        std::cout << colorTable[color] << COLOR_VALUE_SEPARATE;
    std::cout << valueTable[value] << std::endl;

#endif
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

bool Card::operator==(const Card& c) const noexcept
{
    return color == c.color && value == c.value;
}
