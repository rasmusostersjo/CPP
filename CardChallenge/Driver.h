#ifndef DRIVER_H
#define DRIVER_H

// Libraries
#include "CardChallenge.h"

// Constants
#define INVALID_CHOICE 0    // Returned by getChoice if invalid
#define FIRST_OPTION   1    // First valid choice
#define LAST_OPTION    5    // Last valid choice

namespace driver {

    /** play
     * Plays a new round of the card challenge and prints the users result.
     *
     * @param c     Reference to a CardChallenge object.
     */
    void play(CardChallenge& c);
     
    /** viewScoreBoard
     * Prints the scoreboard associated with the CardChallenge object.
     *
     * @param c     Reference to a CardChallenge object.
     */
    void viewScoreBoard(CardChallenge& c);

    /** changeLevel
     * Lets the user set a new card challenge level.
     *
     * @param c     Reference to a CardChallenge object.
     */
    void changeLevel(CardChallenge& c);

    /** changeNickName
     * Lets the user set a new nick name.
     * 
     * @param c     Reference to a CardChallenge object.
     */
    void changeNickName(CardChallenge& c);

    /** exitCardChallenge
     * Prints an exit message to the user.
     */
    void exitCardChallenge(void);

    /** menu; Prints the user menu.
     */
    void menu(void);

    /** getChoice
     * Lets the user choose one option from the menu.
     *
     * @return      An integer value in the interval [FIRST_VALUE, LAST_VALUE].
     */
    int getChoice(void);

} // driver

#endif // DRIVER_H
