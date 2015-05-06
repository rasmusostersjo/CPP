#ifndef DEFAULT_VALUES_H
#define DEFAULT_VALUES_H

///////////////////////////// Deck /////////////////////////////////////////////

#define DEFAULT_DECK_SIZE 52    // [Ace-King] in all four colors
#define DEFAULT_LV        26    // Let 26 cards be the default lv

///////////////////////////// CardChallenge ////////////////////////////////////

#define TIME_PRECISION 4        // Use 4-digit precision to print time used

///////////////////////////// Helper ///////////////////////////////////////////

#define INVALID_CHOICE 0
#define VALID_CHOICE   1
#define FIRST_OPTION   1
#define LAST_OPTION    5

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

#define S_LOWER_YES 'y'
#define S_UPPER_YES 'Y'
#define S_LOWER_NO  'n'
#define S_UPPER_NO  'N'

///////////////////////////// ScoreBoard ///////////////////////////////////////

#define DEFAULT_SCORE_FILE "highScore.txt" // File containing high scores
#define DEFAULT_NICK       "???"           // High score nick if none is provied
#define DEFAULT_SCORE      0               // Signal no score
#define DEFAULT_HS_SIZE    10              // Dfl. amt. of high scores per board

#define TAB_WIDTH   4           // Tab the entire score table
#define NICK_WIDTH  16          // Amount of space for nick name field
#define SCORE_WIDTH 8           // Amount of space for score/level field
#define LEVEL_WIDTH 8           // Amount of space for score/level field
#define TIME_WIDTH  16          // Amount of space for time field


///////////////////////////// Exception ////////////////////////////////////////

#define READ_ERROR  ""          // Default to empty string
#define WRITE_ERROR ""          // Default to empty string


#endif // DEFAULT_VALUES_H
