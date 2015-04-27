#ifndef CARD_H
#define CARD_H

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

private:
};

#endif // CARD_H
