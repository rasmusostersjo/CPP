#ifndef DECK_H
#define DECK_H

// Libraries
#include "Card.h"
#include "Constants.h"
#include <vector>           // vector
#include <cstddef>          // size_t
#include <iterator>         // vector::iterator

class Deck {
public:
    
    /** Default constructor
     * Initializes the deck with n cards (in cycles) according to:
     *      Ace of Hearts,   Two of Hearts,   ..., King of Hearts,
     *      Ace of Clubs,    Two of Clubs,    ..., King of Clubs,
     *      Ace of Spades,   Two of Spades,   ..., King of Spaces,
     *      Ace of Diamonds, Two of Diamonds, ..., King of Diamonds.
     * Thus, for n = 13 the deck contains Ace-King of Hearts. Similarly, for
     * n = 53 the deck contains each card once and Ace of Hearts twice.
     *
     * @param n         The amount of cards to assign to this deck.
     */
    Deck(size_t n = DEFAULT_DECK_SIZE);

    /** Constructor
     * Initializes the deck with n cards of color c and value v.
     *
     * @param c         The color to assign to all cards.
     * @param v         The value to assign to all cards.
     * @param n         The amount of cards to assign to this deck.
     */
    Deck(const Color& c, const Value& v, size_t n = DEFAULT_DECK_SIZE);

    /** Assignment operator
     *
     * @param d         A deck to copy to this deck.
     * @return          A reference to this object.
     */
    Deck& operator=(const Deck& d);

    /** Use the compiler defaults
     */
    Deck(const Deck&)       = default;
    Deck(Deck&&)            = default;
    ~Deck(void)             = default;
    Deck& operator=(Deck&&) = default;

    /** print
     * Prints the entire deck.
     *
     * @return          A constant reference to this object.
     */
    const Deck& print(void) const noexcept;

    /** print
     * Prints the card at index i (deck). Note that the print() function indexes
     * in [0, n), where n is the deck size.
     *
     * @param i         The deck-index of the card to print.
     * @return          A constant reference to this object.
     * @range_error     Generated if i is larger or equal to the deck size.
     */
    const Deck& print(size_t i) const;

    /** removeCard
     * Removes a card from the deck by index.
     *
     * @param i         The index of the card to remove.
     * @return          A reference to this object.
     * @range_error     Generated if i is larger or equal to the deck size. 
     */
    Deck& removeCard(size_t i);

    /** insertCard
     * Inserts a card to the deck by index.
     *
     * @param i         The index of the card to insert.
     * @return          A reference to this object.
     * @range_error     Generated if i is larger than the deck size.
     */
    Deck& insertCard(size_t i, const Card& c);

    /** clear
     * Removes all cards from the deck.
     *
     * @return          A reference to this object.
     */
    Deck& clear(void) noexcept;

    /** getCard
     * Similarly to the Deck::print() function, the getCard() function indexes
     * in [0, n).
     *
     * Note that getCard() function allows the cards value and/or color to be
     * modified by calling Card::setColor() and/or Card::setValue().
     *
     * @param i         The deck-index of the card to grab.
     * @return          A reference to the card indexed by i.
     * @range_error     Generated if i is larger or equal to the deck size.
     */
    const Card& getCard(size_t i) const;

    /** shuffle
     * Shuffles the entire deck by using the STL-algorithm std::shuffle.
     *
     * @return          A reference to this object.
     */
    Deck& shuffle(void) noexcept;

    /** size
     * 
     * @param return    The size of this deck.
     */
    size_t size(void) const noexcept;

private:
    
    std::vector<Card> deck;
};

#endif // DECK_H
