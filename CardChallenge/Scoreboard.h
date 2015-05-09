#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

// Libraries
#include <string>           // string, getline
#include <vector>           // vector
#include <cstddef>          // size_t
#include <ostream>          // ostream
#include <chrono>           // to store used time
#include "Constants.h"

class Score {
public:
    
    /** Default constructor
     * Initializes this score to default values (DEFAULT_SCORE, DEFAULT_NICK)
     * to signal that no score was set yet.
     */
    Score(void);
    
    /** Constructor
     * Initializes this score with the specified nickname, level, score and the
     * time used viewing the entire deck.
     *
     * @param lv            The game level used.
     * @param s             The user's score.
     * @param t             The time used viewing the entire deck.
     * @param nick          The highscore holder's nickname.
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

    /** Larger than operator
     * Returns true if this score is higher than s by comparing:
     *      a) score
     *      b) time if scores were equal
     *
     * @return              A bolean value; true or false.
     */
    bool operator>(const Score& s) const noexcept;

    /** update
     * Updates the this score according to the parameter s.
     *
     * @param s             The new score to assign to this score.
     * @return              A reference to this object.
     */
    Score& update(const Score& s) noexcept;

    /** getLevel
     *
     * @return              The level of the this score.
     */
    size_t getLevel(void) const noexcept;

    /** getScore
     *
     * @return              The amount of cards that was correctly restated.
     */
    size_t getScore(void) const noexcept;

    /** getTime
     *
     * @return              The time used to view the entire the deck.
     */
    const std::chrono::duration<double>& getTime(void) const noexcept;

    /** getNick
     *
     * @return              The nickname associated with this score.
     */
    const std::string& getNick(void) const noexcept;

    /** Overload the << operator
     * Prints nickname, score, level and time on a single line formatted using
     * the width-constants NICK_WIDTH, SCORE_WIDTH, LEVEL_WIDTH and TIME_WIDTH.
     *
     * Note that this overload does not provide any terminating new line.
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

class Scoreboard {
public:

    /** (Default) constructor
     * Invokes the default constructor for each score, i.e. all scores will
     * initially be unset.
     *
     * @param hsf       The name of a text file to use for storing highscores.
     * @param hss       The size of the highscore list.
     */
    Scoreboard(const  std::string& hsf = DEFAULT_SCORE_FILE,
               size_t hss              = DEFAULT_HS_SIZE);

    /** Use the compiler defaults
     */
    Scoreboard(const Scoreboard&)            = default;
    Scoreboard(Scoreboard&&)                 = default;
    ~Scoreboard(void)                        = default;
    Scoreboard& operator=(const Scoreboard&) = default;
    Scoreboard& operator=(Scoreboard&&)      = default;

    /** update
     * Updates the scoreboard if the parameter s is a new highscore.
     *
     * @param s         A score to test for new highscore.
     * @return          True if s was a new highscore; else false.
     */
    bool update(const Score& s) noexcept;

    /** save
     * Writes all highscores to the highscore file.
     *
     * @return          A constant reference to this object.
     * @write_error     Generated if the score file could not be written to.
     */
    const Scoreboard& save(void) const;

    /** load
     * Reads the highscore file and updates the highscore vector accordingly.
     *
     * If the highscore file contains less scores than the current highscore
     * vector, additional unset scores will be appended to the end of the
     * highscore vector. Furthermore, if to many highscores are provided in the
     * highscore file, only the first highscore.size() highscores will be
     * loaded.
     *
     * Excepted highscore file format:
     *      <nick><NL><score><NL><level><NL><time><NL>
     *
     * @return          A reference to this object.
     * @read_error      Generated if the score file can not be read from.
     */
    Scoreboard& load(void);

    /** rename
     * Associates the scoreboard with a new highscore file and its content.
     *
     * @return              A reference to this object.
     * @invalid_argument    Generated if the highscore file could not be opened;
     *                      then the old highscore file is not changed.
     */
    Scoreboard& rename(const std::string& newHighscoreFile);

    /** print
     * Prints the entire score board.
     *
     * @return          Constant reference to this object.
     */
    const Scoreboard& print(void) const noexcept;

private:

    std::string        highscoreFile;
    std::vector<Score> highscore;
};

#endif // SCORE_BOARD_H
