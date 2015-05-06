#ifndef DECK_H
#define DECK_H

// Libraries
#include "Card.h"
#include "DefaultValues.h"
#include <vector>           // vector
#include <cstddef>          // size_t
#include <iterator>         // vector::iterator

class Deck {
public:
    
    /** Default constructur
     * Intialized the deck with n cards. First Ace-King hearts are added,
     * then clubs, diamonds and spades. Thus, if less or more cards than the
     * amount of distinct cards are requested there may be missing cards or
     * multiple instances.
     *
     * @param n         Amount of cards to assign the deck.
     */
    Deck(size_t n = DEFAULT_DECK_SIZE);

    /** Constructor
     * Intialized the deck with n cards of color c and value v.
     *
     * @param c         Color to assign all cards.
     * @param v         Value to assign all cards.
     * @param n         Amount of cards to assign the deck.
     */
    Deck(const Color& c, const Value& v, size_t n = DEFAULT_DECK_SIZE);

    /** Assignment operator
     *
     * @param d         A deck to copy to this deck.
     * @return          Reference to this object.
     */
    Deck& operator=(const Deck& d);

    /** Use the compiler defaults
     */
    Deck(const Deck&)       = default;
    Deck(Deck&&)            = default;
    ~Deck(void)             = default;
    Deck& operator=(Deck&&) = default;

    /** print; prints the entire deck.
     *
     * @return          Constant reference to this object.
     */
    const Deck& print(void) const noexcept;

    /** print; prints the card specified by i.
     *
     * @param i         Index of the deck card to print.
     * @return          Constant reference to this object.
     *
     * @range_error     Generated if i is larger than the deck size.
     */
    const Deck& print(size_t i) const;

    /** getCard
     *
     * @param i         Index of a the card to get; index from 0, 1, ...
     * @return          The card indexed by i.
     */
    Card& getCard(size_t i);

    /** shuffle; shuffles the entire deck.
     *
     * @return          Reference to this object.
     */
    Deck& shuffle(void) noexcept;

    /** size
     * 
     * @param return        The size of this deck.
     */
    size_t size(void) const noexcept;

private:
    
    /** Let the deck be a vector of cards
     */
    std::vector<Card> deck;
};

#endif // DECK_H
