#ifndef CARD_H
#define CARD_H

// Libraries
#include "Constants.h"

/** Card value data type
 * Here VALUE states the amount of different card values and may also be used
 * to signal no value.
 */
typedef enum {
    ACE,  TWO,   THREE, FOUR,  FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING,  JOKER, VALUE
} Value;

/** Card color data type
 * Here COLOR states the amount of different card colors and may also be used
 * to signal no color.
 */
typedef enum {
    HEARTS, CLUBS, SPADES, DIAMONDS, COLOR
} Color;

class Card {
public:

    /** Default constructor
     * Initializes this card with no color and a joker.
     */
    Card(void);

    /** Constructor
     * Initializes this card with a color and value.
     *
     * @param c         The color to assign to this card.
     * @param v         The value to asign to this card.
     */
    Card(const Color& c, const Value& v);

    /** Use the compiler defaults
     */
    Card(const Card&)            = default;
    Card(Card&&)                 = default;
    ~Card(void)                  = default;
    Card& operator=(const Card&) = default;
    Card& operator=(Card&&)      = default;

    /** view
     * Prints this cards color and value.
     *
     * @return          A constant reference to this object.
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
     * @param c         A color to assign to this card.
     * @return          A reference to this object.
     */
    Card& setColor(const Color& c) noexcept;

    /** setValue
     *
     * @param v         A value to assign to this card.
     * @return          A reference to this object.
     */
    Card& setValue(const Value& v) noexcept;

    /** Equal to operator
     * Here two cards are defined as equal if both value and color matches.
     *
     * @return          If this card was equal to c, true; else false.
     */
    bool operator==(const Card& c) const noexcept;
    
private:

    Color color;
    Value value;
};

#endif // CARD_H
