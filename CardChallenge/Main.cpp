#include "Main.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    CardChallenge c(6);
    c.play();

    return 0;
}
