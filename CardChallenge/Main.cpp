#include "Main.h"
#include <stdexcept>

int main(int argc, char *argv[])
{
    try {
        std::string nick;
        int choice;

        helper::clearScreen();
        std::cout << S_ENTER_NICK;
        std::getline(std::cin, nick);
        std::cout << std::endl;

        // Create a card challenge object and seed shuffle
        CardChallenge cardChallenge(GAME_LEVEL, nick);
        srand(time(0));
        driver::menu();
        do {
            choice = driver::getChoice();

            switch (choice) {
                case 1: driver::play(cardChallenge);                break;
                case 2: driver::viewScoreboard(cardChallenge);      break;
                case 3: driver::viewCurrentSettings(cardChallenge); break;
                case 4: driver::changeLevel(cardChallenge);         break;
                case 5: driver::changeNickname(cardChallenge);      break;
                case 6: driver::changeHighscoreFile(cardChallenge); break;
                case 7: driver::exitCardChallenge();
                default: continue;                                  break;
            }
            driver::menu();
        } while (choice != LAST_OPTION);
    }
    catch (std::bad_alloc) {
        std::cout << S_BAD_ALLOC << std::endl;
    }
    catch (...) {
        std::cout << S_UNKOWN_ERROR << std::endl;
    }

    return 0;
}
