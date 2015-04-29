#include "Main.h"

int main(int argc, char *argv[])
{
    std::string strLv;
    int lv;

    // Let user choose lv
    std::cout << "Enter lv: ";
    std::cin  >> strLv;
    
    // Seed, shuffle and play the card challenge
    if ((lv = atoi(strLv.c_str())) > 0) {
        srand(time(NULL));
        CardChallenge c(lv);
        c.shuffle().play();
    }
    else
        std::cerr << "Invalid lv; the card challenge closes." << std::endl;

    

    return 0;
}
