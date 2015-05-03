#include "ScoreBoard.h"

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

/** TODO: Overload the << operator for pritning
 */

