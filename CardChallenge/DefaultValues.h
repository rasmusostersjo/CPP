#ifndef DEFAULT_VALUES_H
#define DEFAULT_VALUES_H

// Card constants
#define VALUE_ACE      "Ace"
#define VALUE_TWO      "Two"
#define VALUE_THREE    "Three"
#define VALUE_FOUR     "Four"
#define VALUE_FIVE     "Five"
#define VALUE_SIX      "Six"
#define VALUE_SEVEN    "Seven"
#define VALUE_EIGHT    "Eight"
#define VALUE_NINE     "Nine"
#define VALUE_TEN      "Ten"
#define VALUE_JACK     "Jack"
#define VALUE_QUEEN    "Queen"
#define VALUE_KING     "King"
#define VALUE_JOKER    "Joker"
#define VALUE_NO_VALUE ""

#define COLOR_HEARTS   "Hearts"
#define COLOR_CLUBS    "Clubs"
#define COLOR_SPADES   "Spades"
#define COLOR_DIAMONDS "Diamonds"
#define COLOR_NO_COLOR ""

#define COLOR_VALUE_SEPARATE " of "

// Deck constants
#define DEFAULT_DECK_SIZE 52    // [Ace-King] in all four colors
#define DEFAULT_LV        26    // Let 26 cards be the default lv

// CardChallenge constants
#define TIME_PRECISION 4        // Use 4-digit precision to print time used
#define S_READ_ERROR_WRITE_SUCCESS "The high score file was created!"
#define S_READ_WRITE_ERROR         "Error: Invalid high score file"
#define S_NO_SCORE "There is no score associated with the current settings."
#define S_STATE_CARD "State card "

// CardChallenge::play constants
#define S_START                  "Press enter to start."
#define Q_ANY_RESTATES           "Do you want to restate any card? (y/n) "
#define S_RESTATE_CARD_INDEX     "Enter which card to restate: "
#define S_INVALID_CARD_INDEX     "Invalid card index."
#define Q_RESTATE_ANY_OTHER_CARD "Do you want to restate any other card? (y/n) "
#define S_YOUR_SCORE             "\tYour score:  "
#define S_LEVEL_SCORE_SEP        "/"
#define S_YOUR_TIME              "\tYour time:   "
#define S_TIME_UNIT              "s"
#define Q_REVEAL_SOLUTION "Do you want to reveal the entire solution? (y/n)"

// CardChallenge::expected restatement values
#define RESTATE_ACE   'a'
#define RESTATE_TWO   '2'
#define RESTATE_THREE '3'
#define RESTATE_FOUR  '4'
#define RESTATE_FIVE  '5'
#define RESTATE_SIX   '6'
#define RESTATE_SEVEN '7'
#define RESTATE_EIGHT '8'
#define RESTATE_NINE  '9'
#define RESTATE_TEN   '1'
#define RESTATE_JACK  'j'
#define RESTATE_QUEEN 'q'
#define RESTATE_KING  'k'
#define RESTATE_JOKER 'r'

#define RESTATE_HEARTS   'h'
#define RESTATE_CLUBS    'c'
#define RESTATE_DIAMONDS 'd'
#define RESTATE_SPADES   's'

// ScoreBoard constants
#define DEFAULT_SCORE_FILE "highScore.txt" // File containing high scores
#define DEFAULT_NICK       "Unkown"        // High score nick if none is provied
#define DEFAULT_SCORE      0               // Signal no score
#define DEFAULT_HS_SIZE    10              // Dfl. amt. of high scores per board

#define TAB_WIDTH   4           // Tab the entire score table
#define NICK_WIDTH  16          // Amount of space for nick name field
#define SCORE_WIDTH 8           // Amount of space for score/level field
#define LEVEL_WIDTH 8           // Amount of space for score/level field
#define TIME_WIDTH  16          // Amount of space for time field

#define TIME_UNIT   "s"         // Time is expressed in seconds
#define PLAYER      "nickname:" // Easy to change language of table
#define _PLAYER_    "---------" // -------------- "" ---------------
#define SCORE       "score:"    // -------------- "" ---------------
#define _SCORE_     "------"    // -------------- "" ---------------
#define LEVEL       "level:"    // -------------- "" ---------------
#define _LEVEL_     "------"    // -------------- "" ---------------
#define TIME        "time(s):"  // -------------- "" ---------------
#define _TIME_      "--------"  // -------------- "" ---------------    

// Exception constants
#define READ_ERROR  ""          // Default to empty string
#define WRITE_ERROR ""          // Default to empty string

#endif // DEFAULT_VALUES_H
