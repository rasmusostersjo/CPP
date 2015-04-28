#ifndef CARD_CHALLENGE_H
#define CARD_CHALLENGE_H

#include "Card.h"
#include <cstddef>       // size_t

class CardChallenge
{
public:

    /** (Default) constructor
     * The lv-parameter chooses the card challenge difficulty, but may be
     * omitted if default settings is to be used.
     *
     * @param lv        Initialized the lv of the card challenge.
     */
    CardChallenge(size_t lv = DEFAULT_LV);

    /** play
     * Starts the card challenge.
     *
     * @return          Constant reference to this object.
     */
    const CardChallenge& play(void) const noexcept;

private:
    Deck deck;
};

#endif // CARD_CHALLENGE
