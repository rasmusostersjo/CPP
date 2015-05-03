#ifndef CARD_H
#define CARD_H

// Libraries
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
    Card& setColor(const Color& c) noexcept;

    /** setValue
     *
     * @param v         Value to assign to this card.
     * @return          Constant reference to this object.
     */
    Card& setValue(const Value& v) noexcept;

    /** Equal to operator
     */
    bool operator==(const Card& c);
    
private:

    Color color;
    Value value;
};

#endif // CARD_H
