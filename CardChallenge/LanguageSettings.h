#ifndef LANGUAGE_SETTINGS
#define LANGUAGE_SETTINGS

//#define USE_ENGLISH
#define USE_SWEDISH

///////////////////////////// Driver ///////////////////////////////////////////

#ifdef USE_ENGLISH

#define S_NEW_HIGH_SCORE    "\t!!! New high score !!!"
#define S_ENTER_NICK        "Enter a nick name: "
#define S_ENTER_NEW_NICK    "Enter new nick name: "
#define S_ENTER_LEVEL       "Enter new level: "
#define S_LEVEL_SET_SUCCESS "Level was successfully set!"
#define S_LEVEL_SET_FAIL    "Error: Invalid level."
#define S_EXIT_MSG          "gg wp!"

#else

#define S_NEW_HIGH_SCORE    "\t!!! Nytt rekord !!!"
#define S_ENTER_NICK        "Ange användarnamn: "
#define S_ENTER_NEW_NICK    "Ange ett nytt användarnamn: "
#define S_ENTER_LEVEL       "Ange ny svårighetsgrad: "
#define S_LEVEL_SET_SUCCESS "Spelnivån har nu uppdaterats!"
#define S_LEVEL_SET_FAIL    "Error: Ogiltig nivå."
#define S_EXIT_MSG          "gg wp!"

#endif

///////////////////////////// Helper ///////////////////////////////////////////

#ifdef USE_ENGLISH 

#define S_STARS          "\t*****************************"
#define S_OPTION_1       "\t*    1. Play                *"
#define S_OPTION_2       "\t*    2. View high scores    *"
#define S_OPTION_3       "\t*    3. Change level        *"
#define S_OPTION_4       "\t*    4. Change nick name    *"
#define S_OPTION_5       "\t*    5. Exit                *"
#define S_ENTER_CHOICE   "Enter choice: "
#define S_INVALID_CHOICE "Error: Invalid choice."

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

#else

#define S_STARS          "\t*********************************"
#define S_OPTION_1       "\t*    1. Spela                   *"
#define S_OPTION_2       "\t*    2. Visa highscore          *"
#define S_OPTION_3       "\t*    3. Ändra svårighetsgrad    *"
#define S_OPTION_4       "\t*    4. Ändra användarnamn      *"
#define S_OPTION_5       "\t*    5. Avsluta                 *"
#define S_ENTER_CHOICE   "Ange ditt val: "
#define S_INVALID_CHOICE "Error: Ogiltigt val."

#define RESTATE_ACE   'e'
#define RESTATE_TWO   '2'
#define RESTATE_THREE '3'
#define RESTATE_FOUR  '4'
#define RESTATE_FIVE  '5'
#define RESTATE_SIX   '6'
#define RESTATE_SEVEN '7'
#define RESTATE_EIGHT '8'
#define RESTATE_NINE  '9'
#define RESTATE_TEN   '1'
#define RESTATE_JACK  'n'       // !!
#define RESTATE_QUEEN 'd'
#define RESTATE_KING  'k'
#define RESTATE_JOKER 'j'

#define RESTATE_HEARTS   'H'    // Restate swedish colors by capital letter
#define RESTATE_CLUBS    'R'
#define RESTATE_DIAMONDS 'K'
#define RESTATE_SPADES   'S'

#define S_LOWER_YES 'j'
#define S_UPPER_YES 'J'
#define S_LOWER_NO  'n'
#define S_UPPER_NO  'N'

#endif

//////////////////////////// Card //////////////////////////////////////////////

#ifdef USE_ENGLISH

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

#else

#define VALUE_ACE      "Ess"
#define VALUE_TWO      "Två"
#define VALUE_THREE    "Tre"
#define VALUE_FOUR     "Fyra"
#define VALUE_FIVE     "Fem"
#define VALUE_SIX      "Sex"
#define VALUE_SEVEN    "Sju"
#define VALUE_EIGHT    "Åtta"
#define VALUE_NINE     "Nio"
#define VALUE_TEN      "Tio"
#define VALUE_JACK     "Knäckt"
#define VALUE_QUEEN    "Dam"
#define VALUE_KING     "Kung"
#define VALUE_JOKER    "Joker"
#define VALUE_NO_VALUE ""

#define COLOR_HEARTS   "Hjärter"
#define COLOR_CLUBS    "Ruter"
#define COLOR_SPADES   "Spader"
#define COLOR_DIAMONDS "Klöver"
#define COLOR_NO_COLOR ""

#define COLOR_VALUE_SEPARATE " "

#endif

///////////////////////////// CardChallenge ////////////////////////////////////

#ifdef USE_ENGLISH

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
#define S_INVALID_NICK_NAME \
    "Error: Invalid nick name (overflowing the nick name field)."

#define Q_ANY_RESTATES           "Do you want to restate any card? (y/n) "
#define Q_RESTATE_ANY_OTHER_CARD "Do you want to restate any other card? (y/n) "
#define Q_REVEAL_SOLUTION \
    "Do you want to reveal the entire solution? (y/n) "

#else

#define S_READ_WRITE_ERROR          "Error: Ogiltig highscorefil."
#define S_STATE_CARD                "Ange kort "
#define S_START                     "Tryck enter när du är redo."
#define S_RESTATE_CARD_INDEX        "Ange vilket kort du vill ändra: "
#define S_INVALID_CARD_INDEX        "Ogiltigt kortindex."
#define S_YOUR_SCORE                "\tDitt resultat: "
#define S_LEVEL_SCORE_SEP           "/"
#define S_YOUR_TIME                 "\tAnvänd tid:    "
#define S_TIME_UNIT                 "s"
#define S_NO_SCORE \
    "Det finns inte något resultat associerad med nuvarande inställningar."
#define S_INVALID_HS_FILE \
     "Error: Ogiltig highscorefil - inga ändringar sparades."
#define S_READ_ERROR_WRITE_SUCCESS \
    "Skapade highscorefilen!"
#define S_INVALID_NICK_NAME \
    "Error: Ogiltigt användarnamn (för många tecken)."

#define Q_ANY_RESTATES           "Vill du återange något kort? (j/n) "
#define Q_RESTATE_ANY_OTHER_CARD "Vill du återge något mer kort? (j/n) "
#define Q_REVEAL_SOLUTION        "Vill du visa den korrekta lösningen? (j/n) "

#endif

///////////////////////////// ScoreBoard ///////////////////////////////////////

#ifdef USE_ENGLISH

#define TIME_UNIT   "s"
#define PLAYER      "nickname:"
#define _PLAYER_    "---------"
#define SCORE       "score:"
#define _SCORE_     "------"
#define LEVEL       "level:"
#define _LEVEL_     "------"
#define TIME        "time(s):"
#define _TIME_      "--------"

#else

#define TIME_UNIT   "s"
#define PLAYER      "Användarnamn:"
#define _PLAYER_    "-------------"
#define SCORE       "Resultat:"
#define _SCORE_     "------"
#define LEVEL       "Nivå:"
#define _LEVEL_     "------"
#define TIME        "Tid(s):"
#define _TIME_      "-------"

#endif

#endif // LANGUAGE_SETTINGS
