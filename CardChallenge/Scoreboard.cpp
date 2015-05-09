#include "Scoreboard.h"
#include "LanguageSettings.h"
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

bool Score::operator>(const Score& s) const noexcept
{
    return score == s.score? time < s.time : score > s.score;
}

Score& Score::update(const Score& newScore) noexcept
{
    level = newScore.level;
    score = newScore.score;
    time  = newScore.time;
    nick  = newScore.nick;

    return *this;
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


///////////////////////////// Scoreboard ///////////////////////////////////////

Scoreboard::Scoreboard(const std::string& hsf, size_t hss)
    : highscoreFile(hsf), highscore(hss)
{
}

bool Scoreboard::update(const Score& sc) noexcept
{
    // Decide where (if) to insert the new highscore
    auto rit = --highscore.rbegin();
    std::for_each(highscore.rbegin(), highscore.rend(), [&](const Score& s) {
        if (sc > s) ++rit;
    } );

    // Insert new highscore
    if (rit != highscore.rbegin() - 1) {
        highscore.insert((rit + 1).base(), sc);
        highscore.pop_back();
    }

    return rit != highscore.rbegin() - 1;
}

const Scoreboard& Scoreboard::save(void) const
{
    // Attempt to open highscore file for writing
    std::ofstream writeFile(highscoreFile, std::ios::out | std::ios::trunc);
    if (!writeFile.is_open())
        throw write_error("Scoreboard::save");

    // Write all current highscores to the highscore file
    std::for_each(highscore.begin(), highscore.end(), [&](const Score& s) {
        writeFile << s.getNick()  << std::endl << s.getScore() << std::endl
                  << s.getLevel() << std::endl << s.getTime().count() 
                  << std::endl;
    } );
    writeFile.close();

    return *this;
}

Scoreboard& Scoreboard::load(void)
{
    // Attempt to open highscore file for reading
    std::ifstream readFile(highscoreFile, std::ios::in);
    if (!readFile.is_open())
        throw read_error("Scoreboard::load");

    // Read highscores (at most highscore.size() of them)
    size_t lv, s, i;
    double t;
    std::string n;

    for (i = 0; i < highscore.size(); ++i) {
        readFile >> std::ws;
        std::getline(readFile, n);
        if (!(readFile >> std::ws >> s >> std::ws >> lv >> std::ws >> t))
            break;
        highscore[i] = Score(lv, s, std::chrono::duration<double>(t), n);
    }

    // Zero out remaining highscores if any
    while (i < highscore.size())
        highscore[i++] = Score();

    return *this;
}


Scoreboard& Scoreboard::rename(const std::string& newHighscoreFile)
{
    std::string oldHighscoreFile = highscoreFile;
    try {
        highscoreFile = newHighscoreFile;
    }
    catch (read_error) {
        highscoreFile = oldHighscoreFile;
        throw std::invalid_argument("Scoreboard::rename");
    }
    
    return *this;
}

const Scoreboard& Scoreboard::print(void) const noexcept
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
    std::for_each(highscore.begin(), highscore.end(), [](const Score& s) {
        std::cout << std::left << std::setw(TAB_WIDTH) << "" << s << std::endl;
    } );

    return *this;
}
