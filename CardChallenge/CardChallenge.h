#ifndef CARD_CHALLENGE_H
#define CARD_CHALLENGE_H

// Libraries
#include "Deck.h"
#include "Constants.h"
#include "Scoreboard.h"
#include <cstddef>       // size_t
#include <chrono>        // to measure time
#include <string.h>      // string

class CardChallenge
{
public:

// Life cycle

    /** (Default) constructor
     * Initializes a new cardChallenge object with an optional level, nickname
     * and scoreboard.
     *
     * @param lv        The level of this cardChallenge.
     * @param nick      The user nickname.
     * @param sb        A scoreboard associated with a highscore file.
     */
    CardChallenge(size_t lv = DEFAULT_LV,
        const std::string& nick = DEFAULT_NICK,
        const Scoreboard& sb = Scoreboard(DEFAULT_SCORE_FILE, DEFAULT_HS_SIZE));

    /** Use the compiler defaults
     */
    CardChallenge(const CardChallenge&)            = default;
    CardChallenge(CardChallenge&&)                 = default;
    ~CardChallenge(void)                           = default;
    CardChallenge& operator=(const CardChallenge&) = default;
    CardChallenge& operator=(CardChallenge&&)      = default;
    
// Member functions associated with game play and score

    /** play
     * Lets the user play one round with the current CardChallenge settings. The
     * play() function provides the following:
     *  1. Shuffles the deck prior to a new game by calling Deck::Shuffle().
     *  2. Interacts with the user at all stages of the game:
     *          a) Prior to the card challenge start, to ensure that the user is
     *             ready.
     *          b) During the card challenge, to let the user view and restate
     *             cards.
     *          c) After the card challenge, to print results and optionally
     *             view the correct solution.
     *
     * @return          A constant reference to this object.
     */
    CardChallenge& play(void) noexcept;

    /** viewScoreboard
     * Prints all highscores.
     *
     * @return          A constant reference to this object.
     */
    const CardChallenge& viewScoreboard(void) const noexcept;

    /** printLatestScore
     * Prints the latest score and lets the user reveal the entire solution.
     * If there is no latest score, i.e. it is set to (0, 0, 0, ...), an error
     * message is printed.
     *
     * @return          A constant reference to this object.
     */
    const CardChallenge& printLatestScore(void) const noexcept;

    /** newHighscore
     * States if the latest score (currentScore) was a new highscore or not.
     *
     * @return          If latest score was a new highscore true; else false.
     */
    bool newHighscore(void) const noexcept;

    /** shuffle
     * Shuffles the deck by calling Deck::shuffle(). Note that the the shuffle()
     * function does not provide any seeding.
     *
     * @return          A reference to this object.
     */
    CardChallenge& shuffle(void) noexcept;

// Set and get member functions

    /** setLevel
     *
     * @param lv        A new level to assign to this card challenge.
     * @return          A reference to this object.
     * @range_error     Generated if lv is less than 1.
     */
    CardChallenge& setLevel(size_t lv);

    /** setNick
     *
     * @param nick          A new nickname to assign the player.
     * @return              A reference to this object.
     * @invalid_argument    Generated if the new nickname would overflow the
     *                      the nickname field (NICK_WIDTH - 1).
     */
    CardChallenge& setNick(const std::string& n);

    /** setHighscoreFile
     *
     * @return              A reference to this object.
     * @invalid_argument    Generated if the highscore file was invalid (the old
     *                      highscore file then remains unchanged).
     */
    CardChallenge& setHighscoreFile(const std::string& hsf);

    /** getLevel
     *
     * @return          The current level setting.
     */
    size_t getLevel(void) const noexcept;

    /** getNick
     *
     * @return          The nickname of the current player.
     */
    const std::string& getNick(void) const noexcept;

    /** getScore
     *
     * @return          The current score.
     */
    const Score& getScore(void) const noexcept;

private:

    /** deck
     * This is the card challenge deck that the user must restate.
     */
    Deck deck;

    /** scoreDeck
     * This is the deck that the user enter their restatements to.
     */
    Deck scoreDeck;

    /** nick
     * The nickname of the current user.
     */
    std::string nick;

    /** currentScore
     * Provides information about the latest score such as level, score,
     * time used and nickname.
     *
     * Note that the currentScore variable is set to (0, 0, 0, ...) to signal
     * that no current score is available.
     */
    Score currentScore;

    /** newHighscoreFlag
     * Is set to false if the currentScore was a new highscore, else it is set
     * to true.
     */
    bool newHighscoreFlag;

    /** scoreboard
     * The scoreboard that is associated with this card challenge.
     */
    Scoreboard scoreboard;

// Helper functions

    /** view
     * Views the entire deck one card at a time. Here the user must provide an
     * ENTER every time a new card is to be viewed.
     *
     * @return          A constant reference to this object.
     */
    const CardChallenge& view(void) const noexcept;

    /** view
     * Views the card associated with index i in the card challenge deck (deck).
     * Similarly to the view() function that prints the entire deck, the user
     * must provide an ENTER prior to proceeding.
     *
     * @return          A constant reference to this object.
     * @range_error     Generated if the index i was out of range.
     */
    const CardChallenge& view(size_t i) const;

    /** stateCard
     * Lets the user restate card_i and updates the score deck (scoreDeck)
     * accordingly.
     *
     * Note that cards may be restated in various ways, depending on the current
     * language settings.
     *
     * @param i         The index of the next card to restate.
     * @return          A reference to this object.
     * @range_error     Generated if i is was out of range.
     */
    CardChallenge& stateCard(size_t i);

    /** computeScore
     * Computes the users score by comparing the card challenge deck (deck) and
     * the score deck (scoreDeck) one card at a time.
     * 
     * @return          The user score.
     */
    size_t computeScore(void) noexcept;
};

#endif // CARD_CHALLENGE
