#include "Deck.h"
#include <algorithm>    // for_each, shuffle
#include <stdexcept>    // range_error

Deck::Deck(size_t n)
    : deck(n)
{
    Value v = ACE;
    Color c = HEARTS;

    std::for_each(deck.begin(), deck.end(), [&v, &c](Card& k) {
        k.setColor(c).setValue(v);

        // Increment value and color in cycles; dont assign jokers
        if ( (v = Value((v + 1) % (VALUE - 1))) == 0 )
            c = Color( (c + 1) % COLOR );
    } );
}

Deck::Deck(const Color& c, const Value& v, size_t n)
    : deck(n)
{
    std::fill(deck.begin(), deck.end(), Card(c, v));
}

Deck& Deck::operator=(const Deck& d)
{
    deck.assign(d.deck.begin(), d.deck.end());
    return *this;
}

const Deck& Deck::print(void) const noexcept
{
    std::for_each(deck.begin(), deck.end(), [](const Card &k) { k.view(); } );
    return *this;
}

const Deck& Deck::print(size_t index) const
{
    if (index >= deck.size())
        throw std::range_error("Error: Deck::print");

    deck[index].view();
    return *this;
}

Card& Deck::getCard(size_t index)
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
