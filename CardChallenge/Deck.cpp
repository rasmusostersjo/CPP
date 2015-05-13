#include "Deck.h"
#include <algorithm>    // for_each, shuffle, fill
#include <stdexcept>    // range_error

// Functor to initialize a deck of cards in cycles
class DeckInit {
public:

    DeckInit(void)
        : color(HEARTS), value(ACE)
    {
    }

    void operator()(Card& card)
    {
        card = Card(color, value);
        if ( (value = Value((value + 1) % (VALUE - 1))) == 0 )
            color = Color( (color + 1) % COLOR );
    }

private:
    Color color;
    Value value;
};

///////////////////////////// Deck /////////////////////////////////////////////

Deck::Deck(size_t n)
    : deck(n)
{
    std::for_each(deck.begin(), deck.end(), DeckInit());
}

Deck::Deck(const Color& c, const Value& v, size_t n)
    : deck(n)
{
    std::fill(deck.begin(), deck.end(), Card(c, v));
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

Deck& Deck::removeCard(size_t index)
{
    if (index >= deck.size())
        throw std::range_error("Error: Deck::removeCard");

    deck.erase(deck.begin() + index);
    return *this;
}

Deck& Deck::insertCard(size_t index, const Card& c)
{
    if (index > deck.size())
        throw std::range_error("Error: Deck::insertCard");

    deck.insert(deck.begin() + index, c);
    return *this;
}

Deck& Deck::clear(void) noexcept
{
    deck.clear();
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
