#ifndef HELPER_H
#define HELPER_H

#include "Card.h"
#include <string>       // string

namespace helper {

    /** readENTER
     * Ignores all characters entered by the user until a new line is read.
     */
    void readENTER(void);

    // TODO: Implement new-line looping to prevent look-up cheating
    /** clearScreen
     * Clears the screen by calling system("clear").
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

} // helper

#endif // HELPER_H
