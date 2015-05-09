#ifndef DRIVER_H
#define DRIVER_H

// Libraries
#include "CardChallenge.h"

// Constants
#define INVALID_CHOICE 0    // Returned by getChoice() if invalid entry
#define FIRST_OPTION   1    // First valid menu choice
#define LAST_OPTION    5    // Last valid menu choice

namespace driver {

    /** play
     * Invokes the play() routine to let the user play another round of the card
     * challenge.
     *
     * @param c     A reference to a CardChallenge object.
     */
    void play(CardChallenge& c);
     
    /** viewScoreboard
     * Prints the scoreboard associated with the specified CardChallenge object.
     *
     * @param c     A reference to a CardChallenge object.
     */
    void viewScoreboard(CardChallenge& c);

    /** changeLevel
     * Lets the user set a new card challenge level.
     *
     * @param c     A reference to a CardChallenge object.
     */
    void changeLevel(CardChallenge& c);

    /** changeNickname
     * Lets the user set a new nickname.
     * 
     * @param c     A reference to a CardChallenge object.
     */
    void changeNickname(CardChallenge& c);

    /** menu
     * Prints the user menu.
     */
    void menu(void);

    /** getChoice
     * Lets the user choose one option from the menu.
     *
     * @return      An integer value in the interval [FIRST_VALUE, LAST_VALUE];
     *              INVALID_CHOICE if the users choice was invalid.
     */
    int getChoice(void);

    /** exitCardChallenge
     * Prints an exit message to the user.
     */
    void exitCardChallenge(void);

} // driver

#endif // DRIVER_H
