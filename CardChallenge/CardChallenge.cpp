#include "CardChallenge.h"
#include "Exception.h"
#include <vector>           // vector
#include <algorithm>        // for_each
#include <string>           // string
#include <iostream>         // cout, cin
#include <cstdlib>          // system, atoi
#include <iomanip>          // setprecision

////////////////////////// static helper functions /////////////////////////////

static void readENTER(void)
{
    while (std::cin.get() != '\n')
        ;
}

static void clearScreen(void)
{
    system("clear");
}

static Color transformColor(const std::string& c)
{
    switch (*c.c_str()) {
        case 'h': return HEARTS;   break;
        case 'c': return CLUBS;    break;
        case 'd': return DIAMONDS; break;
        case 's': return SPADES;   break;
    }

    return COLOR;   // invalid
}

static Value transformValue(const std::string& v)
{
    switch (*v.c_str()) {
        case 'a': return ACE;   break;
        case '2': return TWO;   break;
        case '3': return THREE; break;
        case '4': return FOUR;  break;
        case '5': return FIVE;  break;
        case '6': return SIX;   break;
        case '7': return SEVEN; break;
        case '8': return EIGHT; break;
        case '9': return NINE;  break;
        case '1': return TEN;   break;
        case 'j': return JACK;  break;
        case 'q': return QUEEN; break;
        case 'k': return KING;  break;
    }

    return JOKER; // invalid
}

/** yes_no
 * Lets the user enter yes (y, Y) or no (n, N).
 * 
 * @return          1 to signal yes; else 0.
 */
static bool yes_no(void)
{
    int c;

    while ((c = std::cin.get()) != 'y' && c != 'Y' && c != 'n' && c != 'N')
        ;
    readENTER(); 

    return (c == 'y' || c == 'Y')? 1 : 0;
}

//////////////////////////// CardChallenge ////////////////////////////////////

CardChallenge::CardChallenge(size_t lv, const std::string& n,
    const ScoreBoard& sb)
    : deck(lv), scoreDeck(COLOR, JOKER, lv), nick(n),
    currentScore(0, 0, std::chrono::duration<double>(0), n)
{
    try {
        scoreBoard.load();  // Attempt to load high scores
    }
    catch (read_error) {
        try {
            scoreBoard.save();  // create the high score file
        }
        catch (write_error) {
            std::cerr << S_READ_WRITE_ERROR << std::endl;
        }
        std::cerr << S_READ_ERROR_WRITE_SUCCESS << std::endl;
    }
}

CardChallenge& CardChallenge::shuffle(void) noexcept
{
    deck.shuffle();
    return *this;
}

const CardChallenge& CardChallenge::view(void) const noexcept
{
    for (size_t i = 0; i < deck.size(); ++i) {
        deck.print(i);
        readENTER();
        clearScreen();
    }

    return *this;
}

const CardChallenge& CardChallenge::view(size_t i) const
{
    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::view");

    deck.print(i);
    readENTER();
    clearScreen();

    return *this;
}

CardChallenge& CardChallenge::stateCard(size_t i)
{
    std::string c, v;
    Color color;
    Value value;

    if (i >= deck.size())
        throw std::range_error("Error: CardChallenge::stateCard");

    std::cout << "State card " << i + 1 << ": ";
    std::cin  >> v >> c;

    // Update scoreDeck
    color = transformColor(c);
    value = transformValue(v);
    scoreDeck.getCard(i).setColor(color).setValue(value);

    return *this;
}

size_t CardChallenge::computeScore(void) noexcept
{
    size_t s = 0;
    size_t n = deck.size() < scoreDeck.size() ? deck.size() : scoreDeck.size();

    for (size_t i = 0; i < n; ++i)
        if (deck.getCard(i) == scoreDeck.getCard(i))
            ++s;

    return s;
}

CardChallenge& CardChallenge::play(void) noexcept
{

    std::cout << S_START;
    deck.shuffle();
    readENTER();
    clearScreen();

    // Let user view all cards once and store the times used
    std::chrono::time_point<std::chrono::system_clock> t1, t2;
    t1 = std::chrono::system_clock::now();
    view();
    t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> t = t2 - t1;

    // let user re state all cards
    for (size_t i = 0; i < deck.size(); ++i)
        stateCard(i);

    // Let user re state cards by index
    std::cout << std::endl << Q_ANY_RESTATES;
    bool reState;
    do {
        std::string card_i;

        if ( (reState = yes_no()) ) {
            std::cout << S_RESTATE_CARD_INDEX;
            std::cin >> card_i;
            try {
                stateCard(atoi(card_i.c_str()) - 1);  // stateCard index from 0
            }
            catch (std::range_error) {
                std::cerr << S_INVALID_CARD_INDEX << std::endl;
            }
            std::cout << Q_RESTATE_ANY_OTHER_CARD;
        }

    } while(reState);

    // TODO: Change ret. value of update to indicate if new high score
    currentScore = Score(deck.size(), computeScore(), t, nick);
    scoreBoard.update(currentScore);
    scoreBoard.save();

    return *this;
}

const CardChallenge& CardChallenge::viewScoreBoard(void) const noexcept
{
    scoreBoard.print();
    return *this;
}

CardChallenge& CardChallenge::setLevel(size_t lv)
{
    if (lv == 0)
        throw std::range_error("CardChallenge::setLevel");

    // Resize decks and reset current score
    deck = Deck(lv);
    scoreDeck = Deck(COLOR, JOKER, lv);
    currentScore.update(Score(0, 0, std::chrono::duration<double>(0), nick));

    return *this;
}

CardChallenge& CardChallenge::setNick(const std::string& n) noexcept
{
    nick = n;
    return *this;
}

const std::string& CardChallenge::getNick(void) const noexcept
{
    return nick;
}

size_t CardChallenge::getLevel(void) const noexcept
{
    return deck.size();
}

const Score& CardChallenge::getScore(void) const noexcept
{
    return currentScore;
}

const CardChallenge& CardChallenge::printLatestScore(void) const noexcept
{
    // No score
    if (!currentScore.getScore() && !currentScore.getLevel() && 
        !currentScore.getTime().count())
        std::cout << S_NO_SCORE << std::endl;

    // Print score and reveal solution if user wants to
    else {
        std::cout << std::endl << S_YOUR_SCORE << currentScore.getScore()
                  << S_LEVEL_SCORE_SEP << currentScore.getLevel() << std::endl
                  << S_YOUR_TIME << std::setprecision(TIME_PRECISION)
                  << currentScore.getTime().count() << S_TIME_UNIT << std::endl
                  << std::endl << Q_REVEAL_SOLUTION;
        if (yes_no())
            deck.print();
    }

    return *this;
}
