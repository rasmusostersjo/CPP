#include "Main.h"

int main(int argc, char *argv[])
{
    std::string nick;
    int choice;

    helper::clearScreen();
    std::cout << S_ENTER_NICK;
    std::cin  >> nick;

    // Create a card challenge object and seed shuffle
    CardChallenge cardChallenge(GAME_LEVEL, nick);
    srand(time(0));
    driver::menu();
    do {
        choice = driver::getChoice();

        switch (choice) {
            case 1: driver::play(cardChallenge);           break;
            case 2: driver::viewScoreBoard(cardChallenge); break;
            case 3: driver::changeLevel(cardChallenge);    break;
            case 4: driver::changeNickName(cardChallenge); break;
            case 5: driver::exitCardChallenge();
            default: continue;                             break;
        }
        driver::menu();
    } while (choice != LAST_OPTION);

    return 0;
}


