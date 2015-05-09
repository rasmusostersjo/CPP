#ifndef CONSTANTS_H 
#define CONSTANTS_H

///////////////////////////// Deck /////////////////////////////////////////////

#define DEFAULT_DECK_SIZE 52    // [Ace-King] in all four colors
#define DEFAULT_LV        26    // Let 26 cards be the default lv

///////////////////////////// CardChallenge ////////////////////////////////////

#define TIME_PRECISION 4        // Use 4-digit precision to print time used

///////////////////////////// Scoreboard ///////////////////////////////////////

#define DEFAULT_SCORE_FILE "highscore.txt" // File containing highscores
#define DEFAULT_NICK       "???"           // User nickname if none is provided
#define DEFAULT_SCORE      0               // Signal no score
#define DEFAULT_HS_SIZE    10              // Dfl. amt. of highscores per board

#define TAB_WIDTH   4           // Tab the entire score table 4 blank spaces
#define NICK_WIDTH  24          // Amount of space for the nickname field
#define SCORE_WIDTH 12          // Amount of space for the score field
#define LEVEL_WIDTH 12          // Amount of space for the level field
#define TIME_WIDTH  16          // Amount of space for the time field

///////////////////////////// Exception ////////////////////////////////////////

#define READ_ERROR  ""          // Default to the empty string
#define WRITE_ERROR ""          // Default to the empty string

#endif // CONSTANTS_H
