#ifndef HELPER_H
#define HELPER_H

#include "Card.h"
#include <string>       // string

/** menu; Prints the user menu.
 */
void menu(void);

/** getChoice
 * Lets the user choose one option from the menu.
 *
 * @return      An integer value in the interval [FIRST_VALUE, LAST_VALUE].
 */
int getChoice(void);

/** readENTER; Ignores all characters until a new line is entered.
 */
void readENTER(void);

/** clearScreen; clears the screen by calling system("clear").
 */
void clearScreen(void);

/** yes_no
 * Reads input one character at a time until a y/n is entered by the user,
 * i.e. until any of the macros S_LOWER_YES, S_UPPER_YES, S_LOWER_NO or
 * S_UPPER_NO is entered.
 *
 * Prior to returning yes_no() trashes all user input until a new line is read.
 *
 * @return      true to signal "yes", false to signal "no".
 */
bool yes_no(void);

/** transformColor
 * Tests the first characters in the string c and returns the corresponding
 * card color.
 *
 * @return          If valid the card color specified by c; else COLOR.
 */
Color transformColor(const std::string& c);

/** transformValue
 * Tests the first characters in the string c and returns the corresponding
 * card value.
 *
 * @return          If valid the card value specified by c; else VALUE.
 */
Value transformValue(const std::string& c);


#endif // HELPER_H
