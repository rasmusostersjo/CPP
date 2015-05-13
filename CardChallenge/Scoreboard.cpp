#include "Scoreboard.h"
#include "LanguageSettings.h"
#include "Exception.h"      // write_error, read_error
#include <stdexcept>        // invalid_argument
#include <algorithm>        // for_each, fill
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

bool Score::isEmpty(void) const noexcept
{
    return !level && !score && !time.count();
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
    auto it = std::find_if(highscore.begin(), highscore.end(),
        [sc](const Score& s) { return sc > s; } );
    
    if (it != highscore.end()) {
        highscore.insert(it, sc);
        highscore.pop_back();
        return true;
    }

    return false;
}

// Functor to write highscores to file
class WriteHighscore {
public:
    
    WriteHighscore(std::ofstream& wFile)
        : writeFile(wFile)
    {
    }
    
    void operator()(const Score& s) const noexcept
    {
        writeFile << s.getNick()  << std::endl << s.getScore() << std::endl
                  << s.getLevel() << std::endl << s.getTime().count()
                  << std::endl;
    }
    
private:
    std::ofstream& writeFile;
};

const Scoreboard& Scoreboard::save(void) const
{
    // Attempt to open highscore file for writing
    std::ofstream wFile(highscoreFile, std::ios::out | std::ios::trunc);
    if (!wFile.is_open())
        throw write_error("Scoreboard::save");

    std::for_each(highscore.begin(), highscore.end(), WriteHighscore(wFile));
    return *this;
}

// Functor to read highscores
class ReadHighscore {
public:
    
    ReadHighscore(std::ifstream& rFile)
        : readFile(rFile)
    {
    }

    void operator()(Score& score)
    {
        std::getline(readFile, n);
        if (readFile >> std::ws >> s >> std::ws >> l >> std::ws >> t >> std::ws)
            score = Score(l, s, std::chrono::duration<double>(t), n);
        else
            score = Score();
    }

private:
    std::ifstream& readFile;
    std::string n;
    size_t l;
    size_t s;
    double t;
};

Scoreboard& Scoreboard::load(void)
{
    // Attempt to open highscore file for reading
    std::ifstream rFile(highscoreFile, std::ios::in);
    if (!rFile.is_open())
        throw read_error("Scoreboard::load");

    std::for_each(highscore.begin(), highscore.end(), ReadHighscore(rFile));
    return *this;
}


Scoreboard& Scoreboard::rename(const std::string& nhsf)
{
    Scoreboard backup = *this;
    try {
        highscoreFile = nhsf;
        load();
    }

    // The new highscore file could not be loaded, try to create it
    catch (read_error) {
        std::ofstream newFile(nhsf, std::ios::out | std::ios::trunc);
        if (!newFile.is_open()) {
            *this = backup; // recover the old scoreboard
            throw std::invalid_argument("Scoreboard::rename");
        }

        // Created file successfully, reset the highscore vector
        std::fill(highscore.begin(), highscore.end(), Score());
    }

    return *this;
}

const Scoreboard& Scoreboard::print(void) const noexcept
{
    // Print table frame
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

    // Print all highscores
    std::for_each(highscore.begin(), highscore.end(), [](const Score& s) {
        std::cout << std::left << std::setw(TAB_WIDTH) << "" << s << std::endl;
    } );

    return *this;
}

const std::string& Scoreboard::getHighscoreFile(void) const noexcept
{
    return highscoreFile;
}
