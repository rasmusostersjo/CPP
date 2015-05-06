#include "ScoreBoard.h"
#include "EnglishLanguage.h"
#include "Exception.h"      // write_error, read_error
#include <stdexcept>        // invalid_argument
#include <algorithm>        // for_each
#include <iomanip>          // setw, left
#include <iostream>         // cout, endl
#include <fstream>          // read/write file

///////////////////////////// Score ////////////////////////////////////////////

Score::Score(void)
    : level(DEFAULT_SCORE), score(DEFAULT_SCORE), time(DEFAULT_SCORE),
      nick(DEFAULT_NICK)
{
}

Score::Score(size_t lv, size_t s, const std::chrono::duration<double>& t,
    const std::string& n)
    : level(lv), score(s), time(t), nick(n)
{
}

Score& Score::update(const Score& newScore) noexcept
{
    level = newScore.level;
    score = newScore.score;
    time  = newScore.time;
    nick  = newScore.nick;

    return *this;
}

bool Score::operator>(const Score& s) const noexcept
{
    return score == s.score? time < s.time : score > s.score;
}

size_t Score::getLevel(void) const noexcept
{
    return level;
}

size_t Score::getScore(void) const noexcept
{
    return score;
}

const std::chrono::duration<double>& Score::getTime(void) const noexcept
{
    return time;
}

const std::string& Score::getNick(void) const noexcept
{
    return nick;
}

std::ostream& operator<<(std::ostream& os, const Score& obj) noexcept
{
    os << std::setw(NICK_WIDTH)  << obj.nick
       << std::setw(SCORE_WIDTH) << obj.score
       << std::setw(LEVEL_WIDTH) << obj.level
       << std::setw(TIME_WIDTH)  << obj.time.count();

    return os;
}


///////////////////////////// ScoreBoard ///////////////////////////////////////

ScoreBoard::ScoreBoard(const std::string& hsf, size_t hss)
    : highScoreFile(hsf), highScore(hss)
{
}

bool ScoreBoard::update(const Score& sc) noexcept
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

    return rit != highScore.rbegin() - 1;
}

const ScoreBoard& ScoreBoard::save(void) const
{
    // Attempt to open high score file for writing
    std::ofstream writeFile(highScoreFile, std::ios::out | std::ios::trunc);
    if (!writeFile.is_open())
        throw write_error("ScoreBoard::save");

    // Write all current high scores to the high score file
    std::for_each(highScore.begin(), highScore.end(), [&](const Score& s) {
        writeFile << s << std::endl; } );
    writeFile.close();

    return *this;
}

ScoreBoard& ScoreBoard::load(void)
{
    // Attempt to open high score file for reading
    std::ifstream readFile(highScoreFile, std::ios::in);
    if (!readFile.is_open())
        throw read_error("ScoreBoard::load");

    // Read high scores (at most highScore.size() of them)
    size_t lv, s, i;
    double t;
    std::string n;
    for (i = 0; readFile >> std::ws >> n >> std::ws >> s >> std::ws >> lv
                         >> std::ws >> t && i < highScore.size(); ++i)
        highScore[i] = Score(lv, s, std::chrono::duration<double>(t), n);
    readFile.close();

    // Zero out remaining high scores if any
    while (i < highScore.size())
        highScore[i++] = Score();

    return *this;
}

ScoreBoard& ScoreBoard::rename(const std::string& newHighScoreFile)
{
    std::string oldHighScoreFile = highScoreFile;
    try {
        highScoreFile = newHighScoreFile;
    }
    catch (read_error) {
        highScoreFile = oldHighScoreFile;
        throw std::invalid_argument("ScoreBoard::rename");
    }
    
    return *this;
}

const ScoreBoard& ScoreBoard::print(void) const noexcept
{
    // Print table frame and then all valid scores
    std::cout << std::left << std::setw(TAB_WIDTH)   << ""
              << std::left << std::setw(NICK_WIDTH)  << PLAYER
              << std::left << std::setw(SCORE_WIDTH) << SCORE
              << std::left << std::setw(LEVEL_WIDTH) << LEVEL
              << std::left << std::setw(TIME_WIDTH)  << TIME << std::endl
              << std::left << std::setw(TAB_WIDTH)   << ""
              << std::left << std::setw(NICK_WIDTH)  << _PLAYER_
              << std::left << std::setw(SCORE_WIDTH) << _SCORE_
              << std::left << std::setw(LEVEL_WIDTH) << _LEVEL_
              << std::left << std::setw(TIME_WIDTH)  << _TIME_ << std::endl;
    std::for_each(highScore.begin(), highScore.end(), [](const Score& s) {
        std::cout << std::left << std::setw(TAB_WIDTH) << "" << s << std::endl;
    } );

    return *this;
}
