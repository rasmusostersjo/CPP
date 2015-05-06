#include "Main.h"

int main(int argc, char *argv[])
{
    std::string strLv, nick;
    int lv;

    // Let user choose lv and nickname
    std::cout << "Enter nickname: ";
    std::cin  >> std::ws >> nick;
    std::cout << "Enter lv: ";
    std::cin  >> std::ws >> strLv;
    if (std::cin.peek() == '\n')
        std::cin.ignore(1, '\n');
    
    // Seed, shuffle and play the card challenge
    if ((lv = atoi(strLv.c_str())) > 0) {
        srand(time(NULL));
        CardChallenge c(lv, nick);  // use the standard high score settings
        c.shuffle().play().printLatestScore().viewScoreBoard();
    }
    else
        std::cerr << "Invalid lv; the card challenge closes." << std::endl;

    return 0;
}
