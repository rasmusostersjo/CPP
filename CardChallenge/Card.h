#ifndef CARD_H
#define CARD_H

// Libraries
#include <cstddef>          // size_t
#include <vector>           // vector
#include <iterator>         // vector::iterator
#include "DefaultValues.h"

/** Data type for a cards value
 */
typedef enum {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    JOKER,
    VALUE
} Value;

/** Data type for a cards color
 */
typedef enum {
    HEARTS,
    CLUBS,
    SPADES,
    DIAMONDS,
    COLOR
} Color;

class Card {
public:
    
    /** Default constructor; intializes the card with a Joker
     */
    Card(void);

    /** Constructur; initializes the card according to value and color
     */
    Card(const Color& c, const Value& v);

    /** Use the compiler defaults
     */
    Card(const Card&)            = default;
    Card(Card&&)                 = default;
    ~Card(void)                  = default;
    Card& operator=(const Card&) = default;
    Card& operator=(Card&&)      = default;

    /** view; Prints card information to stdin
     *
     * @return          Constant reference to this object.
     */
    const Card& view(void) const noexcept;

    /** getColor
     *
     * @return          The color of this card.
     */
    const Color& getColor(void) const noexcept;

    /** getValue
     *
     * @return          The value of this card.
     */
    const Value& getValue(void) const noexcept;
    
    /** setColor
     *
     * @param c         Color to assign to this card.
     * @return          Constant reference to this object.
     */
    const Card& setColor(const Color& c) noexcept;

    /** setValue
     *
     * @param v         Value to assign to this card.
     * @return          Constant reference to this object.
     */
    const Card& setValue(const Value& v) noexcept;
    
private:

    Color color;
    Value value;
};

class Deck
{
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

    /** Use the compiler defaults
     */
    Deck(const Deck&)            = default;
    Deck(Deck&&)                 = default;
    ~Deck(void)                  = default;
    Deck& operator=(const Deck&) = default;
    Deck& operator=(Deck&&)      = default;

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
    const Card& getCard(size_t i) const;

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

#endif // CARD_H
