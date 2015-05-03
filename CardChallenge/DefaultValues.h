#ifndef DEFAULT_VALUES_H
#define DEFAULT_VALUES_H

// Deck constants
#define DEFAULT_DECK_SIZE 52    // [Ace-King] in all four colors
#define DEFAULT_LV        26    // Let 26 cards be the default lv

// CardChallenge constants
#define TIME_PRECISION 4        // Use 4-digit precision to print time used

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
