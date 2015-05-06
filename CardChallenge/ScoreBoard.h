#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

// Libraries
#include <string>           // string
#include <vector>           // vector
#include <cstddef>          // size_t
#include <ostream>          // ostream
#include <chrono>           // to store used time
#include "Constants.h"

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
    Score(size_t lv, size_t s, const std::chrono::duration<double>& t,
        const std::string& n);

    /** Use the compiler defaults
     */
    Score(const Score&)            = default;
    Score(Score&&)                 = default;
    ~Score(void)                   = default;
    Score& operator=(const Score&) = default;
    Score& operator=(Score&&)      = default;

    /** update; updates the score to the specified values.
     *
     * @param s             The new score to assign to this score.
     * @return              Reference to this object.
     */
    Score& update(const Score& s) noexcept;

    /** Larger than operator
     * Returns true if this score is higher than s by comparing:
     *      a) score
     *      b) time if scores were equal
     *
     * @return              true/false.
     */
    bool operator>(const Score& s) const noexcept;

    /** getLevel
     *
     * @return              Level of the this score.
     */
    size_t getLevel(void) const noexcept;

    /** getScore
     *
     * @return              Amount of cards that was correctly restated.
     */
    size_t getScore(void) const noexcept;

    /** getTime
     *
     * @return              Time used to memorize the deck.
     */
    const std::chrono::duration<double>& getTime(void) const noexcept;

    /** getNick
     *
     * @return              The nick name associated with this score.
     */
    const std::string& getNick(void) const noexcept;

    /** Overload the << operator
     * Prints nickname, score/level and time, where each fields width is set
     * by the macros NICK_WIDTH, SCORE_WIDTH and TIME_WIDTH defined in
     * DefaultValues.h.
     *
     * @param o             An output stream to print to.
     * @param obj           A score object to print.
     */
    friend std::ostream& operator<<(std::ostream& o, const Score& obj) noexcept;

private:

    size_t level;
    size_t score;
    std::chrono::duration<double> time;
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
     * @return          True if s was a new high score; else false.
     */
    bool update(const Score& s) noexcept;

    /** save
     * Writes current high scores to the high score file.
     *
     * @return          Constant reference to this object.
     * @write_error     Generated if the score file can not be written to.
     */
    const ScoreBoard& save(void) const;

    /** load
     * Reads the high score file and updates the high score vector accordingly.
     * Note that if the high score file contains less scores than the current
     * high score vector, additional (zeroed) scores will be appeneded.
     * Furthermore, if to many high scores are provided only the first
     * highScore.size() results will be loaded.
     *
     * Excepted high score file format:
     *      <ws><nick><ws><score><ws><level><ws><time><NL>
     *
     * @return          Reference to this object.
     * @read_error      Generated if the score file can not be read from.
     */
    ScoreBoard& load(void);

    /** rename
     * Changes which high score file and loads its content.
     *
     * @return              Reference to this object.
     * @invalid_argument    Generated if the high score file could not be
     *                      opened; then the old high score file is not changed.
     */
    ScoreBoard& rename(const std::string& newHighScoreFile);

    /** print
     * Prints the entire score board.
     *
     * @return          Constant reference to this object.
     */
    const ScoreBoard& print(void) const noexcept;

private:

    std::string        highScoreFile;
    std::vector<Score> highScore;
};

#endif // SCORE_BOARD_H
