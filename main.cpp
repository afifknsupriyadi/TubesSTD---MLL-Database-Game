#include "devgame.h"
#include "devgame.cpp"
int main()
{
    listDev LD;
    listGame LG;
    createListDev(LD);
    createListGame(LG);

    menu(LD, LG);

    return 0;
}
