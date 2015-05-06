#ifndef CARD_CHALLENGE_H
#define CARD_CHALLENGE_H

// Libraries
#include "Deck.h"
#include "ScoreBoard.h"
#include "Constants.h"
#include <cstddef>       // size_t
#include <chrono>        // to measure time
#include <string.h>      // string

class CardChallenge
{
public:

// Life cycle

    /** (Default) constructor
     * The lv-parameter chooses the card challenge difficulty, but may be
     * omitted if default settings is to be used.
     *
     * @param lv        Initialized the lv of the card challenge.
     */
    CardChallenge(size_t lv = DEFAULT_LV,
        const std::string& nick = DEFAULT_NICK,
        const ScoreBoard& sb = ScoreBoard(DEFAULT_SCORE_FILE, DEFAULT_HS_SIZE));

    /** Use the compiler defaults
     */
    CardChallenge(const CardChallenge&)            = default;
    CardChallenge(CardChallenge&&)                 = default;
    ~CardChallenge(void)                           = default;
    CardChallenge& operator=(const CardChallenge&) = default;
    CardChallenge& operator=(CardChallenge&&)      = default;
    
// Member functions associated with game play and score

    /** play; starts the card challenge
     *
     * @return          Constant reference to this object.
     */
    CardChallenge& play(void) noexcept;

    /** printLatestScore;
     * Prints the last score and lets the user reveal the entire solution.
     * If the latest score is invalid (i.e. set to 0/0/0/DEFAULT_NICK) an error
     * message is printed.
     *
     * @return          Constant reference to this object.
     */
    const CardChallenge& printLatestScore(void) const noexcept;

    /** newHighScore
     * States if the current score was a new high score or not.
     *
     * @return          true/false.
     */
    bool newHighScore(void) const noexcept;

    /** shuffle; note that srand() must be seeded
     *
     * @return          Reference to this object.
     */
    CardChallenge& shuffle(void) noexcept;

    /** viewScoreBoard; prints all high scores
     *
     * @return          Constant reference to this object.
     */
    const CardChallenge& viewScoreBoard(void) const noexcept;

// Set and get member functions

    /** getScore
     *
     * @return          Current score; always set to (0, 0, 0, ...) to
     *                  signal no current score.
     */
    const Score& getScore(void) const noexcept;

    /** setLevel
     *
     * @param lv        New level to assign to the deck.
     * @return          Reference to this object.
     * @range_error     Generated if lv is less than 1.
     */
    CardChallenge& setLevel(size_t lv);

    // TODO: Add test to prevent nick names > NICK_WIDTH - 1
    /** setNick
     *
     * @param nick      New nick name to assign the player.
     * @return          Reference to this object.
     */
    CardChallenge& setNick(const std::string& n) noexcept;

    /** getNick
     *
     * @return          The nick name of the current player.
     */
    const std::string& getNick(void) const noexcept;

    /** getLevel
     *
     * @return          The current deck level.
     */
    size_t getLevel(void) const noexcept;

    /** setHighScoreFile
     *
     * @return          Reference to this object.
     */
    CardChallenge& setHighScoreFile(const std::string& hsf);

private:

    Deck deck;              // the original deck
    Deck scoreDeck;         // to keep track of restatements
    std::string nick;
    Score currentScore;
    bool newHighScoreFlag;
    ScoreBoard scoreBoard;

// Helper functions

    /** view
     * Views the entire deck one card at a time. Here the user must enter ENTER
     * to proceed to the next card.
     *
     * @return          Constant reference to this object.
     */
    const CardChallenge& view(void) const noexcept;

    /** view
     * Views one card specified by i. Here the user must enter ENTER prior to
     * the function returning.
     *
     * @return          Constant reference to this object.
     * @range_error     Generated if the index i is out of range.
     */
    const CardChallenge& view(size_t i) const;

    /** stateCard
     * Lets the user state card_i and updates scoreDeck accordingly.
     *
     * @param i         Index of the next card to state.
     * @return          Reference to this object.
     * @range_error     Genererated if i is not a valid index.
     */
    CardChallenge& stateCard(size_t i);

    /** computeScore
     * Computes the user score by comparing deck and scoreDeck.
     * 
     * @return          The user score.
     */
    size_t computeScore(void) noexcept;
};

#endif // CARD_CHALLENGE
