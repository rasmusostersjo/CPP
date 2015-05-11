#ifndef HELPER_H
#define HELPER_H

#include "Card.h"
#include "Deck.h"
#include "Scoreboard.h"
#include <string>       // string, getline
#include <cctype>       // isalnum
#include <chrono>       // duration

namespace helper {

    /** readENTER
     * Ignores all characters entered by the user until a new line is read.
     */
    void readENTER(void);

    /** clearScreen
     * Clears the screen by printing CLEAR_SCREEN new lines. Note that we do not
     * want to use system("clear") here, since then the user could potentially
     * do some look-up cheating in the terminal.
     */
    void clearScreen(void);

    /** yes_no
     * Reads input, one character at a time, until a 'yes' or 'no' is entered by
     * the user. Here, 'yes' has the hotkeys specified by the constants
     * S_UPPER_YES and S_LOWER_YES. Similarly, to specify 'no' the user must
     * enter any of the hotkeys S_UPPER_NO and S_LOWER_NO.
     *
     * Note that the yes_no() function ignores all characters proceeding the
     * users first answer until a new line is read.
     *
     * @return      To signal 'yes' true is returned; else false.
     */
    bool yes_no(void);

    /** transformColor
     * Tests the first character in the string c and returns the corresponding
     * card color.
     *
     * @return          If valid, the card color specified by c; else COLOR.
     */
    Color transformColor(const std::string& c);

    /** transformValue
     * Tests the first character in the string c and returns the corresponding
     * card value.
     *
     * @return          If valid, the card value specified by c; else VALUE.
     */
    Value transformValue(const std::string& c);

    /** validNick
     * Tests if n is a valid, non-empty, nickname consisting of [a-zA-Z0-9_ ].
     * Here nonempty include nicknames with only blank spaces.
     *
     * @param n         A nickname to validate.
     * @param max       The max length of a valid nickname.
     * @return          If valid, true; else false.
     */
    bool validNick(const std::string& n, size_t max);

    /** stateCard
     * Lets the user restate a card.
     *
     * @param index     The index of the card to restate (printed out).
     * @return          The card that the user restated.
     */
    Card stateCard(size_t index);

    /** computeScore
     * Derives a score object according to the parameters.
     *
     * @param pd        A constant reference to the play deck.
     * @param sd        A constant reference to the score deck.
     * @param t         A constant reference to the time used.
     * @param nick      A constant reference to the users nickname.
     * @return          The users score.
     */
    Score computeScore(const Deck& pd, const Deck& sd, 
        const std::chrono::duration<double>& t, const std::string& nick);

    /** getSize_t
     * Lets the user enter a positive integer.
     *
     * @return              A positive integer entered by the user.
     * @invalid_argument    Generated if the users input caused overflow
     *                      or contained invalid characters.
     */
    size_t getSize_t(void);

} // helper

#endif // HELPER_H
