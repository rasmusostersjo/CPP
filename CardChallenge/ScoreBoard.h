#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

// Libraries
#include <string>           // string
#include <vector>           // vector
#include <cstddef>          // size_t
#include "Exception.h"      // write_error, read_error
#include "DefaultValues.h"

class Score {
public:
    
    /** Default constructor
     * Initializes this score to default values (DEFAULT_SCORE, DEFAULT_NICK)
     * to signal no score was set yet.
     */
    Score(void);
    
    /** Constructor
     * Initialized the score with the specified nickname, lv, score and time
     * used viewing the entire deck.
     *
     * @param lv            The game level (difficulty) used.
     * @param s             The users score.
     * @param t             The time used viewing the entire deck.
     * @param nick          Nickname of the high score holder.
     */
    Score(size_t lv, size_t s, size_t t, const std::string& n);

    /** Use the compiler defaults
     */
    Score(const Score&)            = default;
    Score(Score&&)                 = default;
    ~Score(void)                   = default;
    Score& operator=(const Score&) = default;
    Score& operator=(Score&&)      = default;

    /** update; updates the score to the specified values.
     *
     * @param lv            The game level (difficulty) used.
     * @param s             The users score.
     * @param t             The time used viewing the entire deck.
     * @param nick          Nickname of the high score holder.
     * @return              Reference to this object.
     * @invalid_argument    Generated if any argument is invalid.
     */
    Score& update(size_t lv, size_t s, size_t t, const std::string& n) noexcept;

    /** Larger than operator
     * Returns true if this score is higher than s by comparing:
     *      a) score
     *      b) time if scores were equal
     *
     * @return              true/false.
     */
    bool operator>(const Score& s) const noexcept;

    /** TODO: Overload the << operator for printing
     */

private:

    size_t level;
    size_t score;
    size_t time;
    std::string nick;
};

class ScoreBoard {
public:

    /** (Default) constructor
     * Invokes the default constructor for each score, i.e. all scores are set
     * to be unset until load is called manually.
     *
     * @param hsf       Name of a text file to save/load high scores.
     * @param hss       Size of the high score list.
     */
    ScoreBoard(const  std::string& hsf = DEFAULT_SCORE_FILE,
               size_t hss              = DEFAULT_HS_SIZE);

    /** Use the compiler defaults
     */
    ScoreBoard(const ScoreBoard&)            = default;
    ScoreBoard(ScoreBoard&&)                 = default;
    ~ScoreBoard(void)                        = default;
    ScoreBoard& operator=(const ScoreBoard&) = default;
    ScoreBoard& operator=(ScoreBoard&&)      = default;

    /** update
     * Updates the score board if s is a new high score.
     *
     * @param s         Score to test for new high score.
     * @return          Constant reference to this object.
     */
    ScoreBoard& update(const Score& s) noexcept;

    /** save
     * Writes current high scores to the high score file.
     *
     * @return          Constant reference to this object.
     * @write_error     Generated if the score file can not be written to.
     */
    const ScoreBoard& save(void) const;

    /** load
     * Reads the high score file and updates the high score vector accordingly.
     *
     * @return          Reference to this object.
     * @read_error      Generated if the score file can not be read from.
     */
    ScoreBoard& read(void);

    /** rename
     * Changes which high score file to save and load to. Note that the old
     * high score file is not removed.
     *
     * @return          Reference to this object.
     */
    ScoreBoard& rename(const std::string& newHighScoreFile) noexcept;

    /** print
     * Prints the entire score board.
     *
     * @return          Constant reference to this object.
     */
    const ScoreBoard& print(void) const noexcept;

    /** print
     * Prints the first n entries in the score board.
     *
     * @param n         Amount of entries to print.
     * @return          Constant reference to this object.
     * @out_of_range    Generated if n is larger the size of the high score
     *                  vector.
     */
    const ScoreBoard& print(size_t n) const;

private:

    std::string        highScoreFile;
    std::vector<Score> highScore;
};

#endif // SCORE_BOARD_H
