#include "Main.h"

int main(int argc, char *argv[])
{
    std::string nick;
    int choice;

    clearScreen();
    std::cout << S_ENTER_NICK;
    std::cin  >> nick;

    // Create a card challenge object and seed shuffle
    CardChallenge cardChallenge(GAME_LEVEL, nick);
    srand(time(0));
    menu();
    do {
        choice = getChoice();

        switch (choice) {
            case 1: play(cardChallenge);           break;
            case 2: viewScoreBoard(cardChallenge); break;
            case 3: changeLevel(cardChallenge);    break;
            case 4: changeNickName(cardChallenge); break;
            case 5: exitCardChallenge();
            default: continue;                     break;
        }
        menu();
    } while (choice != LAST_OPTION);

    return 0;
}


