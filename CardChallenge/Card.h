#ifndef CARD_H
#define CARD_H

/** Data type for a cards value
 */
enum Value{
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
};

/** Data type for a cards color
 */
enum Color{
    HEARTS,
    CLUBS,
    SPADES,
    DIAMONDS,
    COLOR
};

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
    
private:

    Color color;
    Value value;
};

#endif // CARD_H
