#ifndef DRIVER_H
#define DRIVER_H

// Libraries
#include "CardChallenge.h"

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

#endif // DRIVER_H
