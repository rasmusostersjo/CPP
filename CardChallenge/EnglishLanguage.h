#ifndef ENGLISH_LANGUAGE
#define ENGLISH_LANGUAGE

///////////////////////////// Driver ///////////////////////////////////////////

#define S_NEW_HIGH_SCORE    "\t!!! New high score !!!"
#define S_ENTER_NICK        "Enter a nick name: "
#define S_ENTER_NEW_NICK    "Enter new nick name: "
#define S_ENTER_LEVEL       "Enter new level: "
#define S_LEVEL_SET_SUCCESS "Level was successfully set!"
#define S_LEVEL_SET_FAIL    "Error: Invalid level."
#define S_EXIT_MSG          "Thanks for playing the card challenge!"

///////////////////////////// Helper ///////////////////////////////////////////

#define S_STARS          "\t*****************************"
#define S_OPTION_1       "\t*    1. Play                *"
#define S_OPTION_2       "\t*    2. View high scores    *"
#define S_OPTION_3       "\t*    3. Change level        *"
#define S_OPTION_4       "\t*    4. Change nick name    *"
#define S_OPTION_5       "\t*    5. Exit                *"
#define S_ENTER_CHOICE   "Enter choice: "
#define S_INVALID_CHOICE "Error: Invalid choice."

//////////////////////////// Card //////////////////////////////////////////////

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

///////////////////////////// CardChallenge ////////////////////////////////////

#define S_READ_WRITE_ERROR         "Error: Invalid high score file"
#define S_STATE_CARD                "State card "
#define S_START                     "Press enter to start."
#define S_RESTATE_CARD_INDEX        "Enter which card to restate: "
#define S_INVALID_CARD_INDEX        "Invalid card index."
#define S_YOUR_SCORE                "\tYour score:  "
#define S_LEVEL_SCORE_SEP           "/"
#define S_YOUR_TIME                 "\tYour time:   "
#define S_TIME_UNIT                 "s"
#define S_NO_SCORE "There is no score associated with the current settings."
#define S_INVALID_HS_FILE "Error: Invalid high score file - no changes applied."
#define S_READ_ERROR_WRITE_SUCCESS \
    "The high score file was created successfully!"

#define Q_ANY_RESTATES           "Do you want to restate any card? (y/n) "
#define Q_RESTATE_ANY_OTHER_CARD "Do you want to restate any other card? (y/n) "
#define Q_REVEAL_SOLUTION \
    "Do you want to reveal the entire solution? (y/n) "

///////////////////////////// ScoreBoard ///////////////////////////////////////

#define TIME_UNIT   "s"
#define PLAYER      "nickname:"
#define _PLAYER_    "---------"
#define SCORE       "score:"
#define _SCORE_     "------"
#define LEVEL       "level:"
#define _LEVEL_     "------"
#define TIME        "time(s):"
#define _TIME_      "--------"

#endif // ENGLISH_LANGUAGE
