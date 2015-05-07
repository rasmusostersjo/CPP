#ifndef DEFAULT_VALUES_H
#define DEFAULT_VALUES_H

///////////////////////////// Deck /////////////////////////////////////////////

#define DEFAULT_DECK_SIZE 52    // [Ace-King] in all four colors
#define DEFAULT_LV        26    // Let 26 cards be the default lv

///////////////////////////// CardChallenge ////////////////////////////////////

#define TIME_PRECISION 4        // Use 4-digit precision to print time used

///////////////////////////// Helper ///////////////////////////////////////////

#define INVALID_CHOICE 0
#define FIRST_OPTION   1
#define LAST_OPTION    5

///////////////////////////// ScoreBoard ///////////////////////////////////////

#define DEFAULT_SCORE_FILE "highScore.txt" // File containing high scores
#define DEFAULT_NICK       "???"           // High score nick if none is provied
#define DEFAULT_SCORE      0               // Signal no score
#define DEFAULT_HS_SIZE    10              // Dfl. amt. of high scores per board

#define TAB_WIDTH   4           // Tab the entire score table
#define NICK_WIDTH  24          // Amount of space for nick name field
#define SCORE_WIDTH 12          // Amount of space for score/level field
#define LEVEL_WIDTH 12          // Amount of space for score/level field
#define TIME_WIDTH  16          // Amount of space for time field


///////////////////////////// Exception ////////////////////////////////////////

#define READ_ERROR  ""          // Default to empty string
#define WRITE_ERROR ""          // Default to empty string


#endif // DEFAULT_VALUES_H
