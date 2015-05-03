#include "ScoreBoard.h"
#include <algorithm>        // for_each
#include <iomanip>          // setw

///////////////////////////// Score ////////////////////////////////////////////

Score::Score(void)
    : level(DEFAULT_SCORE), score(DEFAULT_SCORE), time(DEFAULT_SCORE),
      nick(DEFAULT_NICK)
{
}

Score::Score(size_t lv, size_t s, size_t t, const std::string& n)
    : level(lv), score(s), time(t), nick(n)
{
}

Score& Score::update(size_t lv, size_t s, size_t t, const std::string& n)
    noexcept
{
    level = lv;
    score = s;
    time  = t;
    nick  = n;

    return *this;
}

bool Score::operator>(const Score& s) const noexcept
{
    return score == s.score? time < s.time : score > s.score;
}

std::ostream& operator<<(std::ostream& os, const Score& obj) noexcept
{
    os << std::setw(NICK_WIDTH)  << obj.nick
       << std::setw(SCORE_WIDTH) << obj.score << "/" << obj.level
       << std::setw(TIME_WIDTH)  << obj.time << TIME_UNIT;

    return os;
}


///////////////////////////// ScoreBoard ///////////////////////////////////////

ScoreBoard::ScoreBoard(const std::string& hsf, size_t hss)
    : highScoreFile(hsf), highScore(hss)
{
}

/** TODO: Test/confirm no off-by-errors
 */
ScoreBoard& ScoreBoard::update(const Score& sc) noexcept
{
    // Decide where (if) to insert the new high score
    auto rit = --highScore.rbegin();
    std::for_each(highScore.rbegin(), highScore.rend(), [&](const Score& s) {
        if (sc > s) ++rit; } );

    // Insert new highscore and remove the previously last high score
    if (rit != highScore.rbegin() - 1) {
        highScore.insert((rit + 1).base(), sc);
        highScore.pop_back();
    }

    return *this;
}

const ScoreBoard& ScoreBoard::print(void) const noexcept
{
    return *this;
}
