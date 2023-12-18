#include "devgame.h"
#include "devgame.cpp"
int main()
{
    listDev LD;
    listGame LG;
    createListDev(LD);
    createListGame(LG);
    adrDev Pdev, prevDev;
    adrGame Pgame, prevGame;
    infotypeDev xDev;
    infotypeGame xGame;

    cout << "-----Input LIST DEVELOPER-----" << endl;
    int n;
    // cout<<"Banyak Developer: ";
    // cin>>n;
    for (int i = 0; i < 7; i++)
    {
        cin >> xDev.ID_Studio >> xDev.nama >> xDev.thnBerdiri >> xDev.alamat >> xDev.revenue;
        Pdev = createElmDev(xDev);
        insertLastDev(LD, Pdev);
    }
    cout << endl;
    // Show List
    cout << "-----show LIST DEVELOPER-----" << endl;
    printDev(LD);
    // Search List
    cout << endl;
    cout << "-----search LIST DEVELOPER-----" << endl;
    string xId;
    // cout<<"Masukkan ID Developer: ";
    // cin>> xId;
    Pdev = searchDev(LD, prevDev, "11");
    if (Pdev != NULL)
    {
        cout << "***Developer Ditemukan***" << endl;
        cout << "ID: " << info(Pdev).ID_Studio << endl;
        cout << "Nama: " << info(Pdev).nama << endl;
        cout << "ThnBerdiri: " << info(Pdev).thnBerdiri << endl;
        cout << "Alamat: " << info(Pdev).alamat << endl;
        cout << "Revenue: " << info(Pdev).revenue << endl;
    }
    else
    {
        cout << "***Developer Tidak Ditemukan***" << endl;
    }

    cout << endl;
    cout << "-----Input LIST GAME-----" << endl;
    // cout<<"Banyak GAME: ";
    // cin>>n;
    for (int i = 0; i < 10; i++)
    {
        cin >> xGame.ID_Game >> xGame.nama >> xGame.rating >> xGame.genre >> xGame.platform >> xGame.harga >> xGame.jmlPemain;
        Pgame = createElmGame(xGame);
        insertLastGame(LG, Pgame);
    }
    cout << endl;

    cout << "-----show LIST GAME-----" << endl;
    printGame(LG);

    cout << endl;
    cout << "-----connect LIST DEV AND LIST GAME-----" << endl;
    connectGameinDev(LD, LG, "11", "001");
    connectGameinDev(LD, LG, "11", "003");
    connectGameinDev(LD, LG, "11", "005");

    connectGameinDev(LD, LG, "12", "002");
    connectGameinDev(LD, LG, "12", "004");
    connectGameinDev(LD, LG, "12", "006");
    connectGameinDev(LD, LG, "12", "008");

    connectGameinDev(LD, LG, "13", "001");
    connectGameinDev(LD, LG, "13", "009");
    connectGameinDev(LD, LG, "13", "010");

    connectGameinDev(LD, LG, "14", "001");
    connectGameinDev(LD, LG, "14", "002");
    connectGameinDev(LD, LG, "14", "003");
    connectGameinDev(LD, LG, "14", "004");

    connectGameinDev(LD, LG, "15", "001");
    connectGameinDev(LD, LG, "15", "006");
    connectGameinDev(LD, LG, "15", "007");
    connectGameinDev(LD, LG, "15", "008");
    connectGameinDev(LD, LG, "15", "009");
    connectGameinDev(LD, LG, "15", "010");

    cout << endl;
    printRelasi2(LD);

    cout << "-----disconnect LIST DEV AND LIST GAME-----" << endl;
    adrRelasi P;
    P = disconnectGameinDev(LD, "11", "005");
    cout << "1 - Info(P) Game: " << info(info(P)).nama << "(" << info(info(P)).ID_Game << ")" << endl;
    P = disconnectGameinDev(LD, "12", "004");
    cout << "2 - Info(P) Game: " << info(info(P)).nama << "(" << info(info(P)).ID_Game << ")" << endl;
    P = disconnectGameinDev(LD, "13", "009");
    cout << "3 - Info(P) Game: " << info(info(P)).nama << "(" << info(info(P)).ID_Game << ")" << endl;

    cout << endl;
    printRelasi2(LD);

    cout << "-----DELETE DEVELOPER-----" << endl;
    // deleteDeveloper(LD,"13");
    cout << endl;
    // printRelasi2(LD);

    cout << "-----DELETE GAME-----" << endl;
    deleteGame(LD, LG, "001");
    cout << endl;
    printRelasi2(LD);

    cout << "-----PRINT DEVELOPER dgn GAME TERTENTU-----" << endl;
    string ID_Game;
    cout << "ID Game: ";
    cin >> ID_Game;

    Pgame = searchGame(LG, prevGame, ID_Game);
    if (Pgame != NULL)
    {
        cout << "GAME: " << info(Pgame).nama << endl;
        printDevBasedGame(LD, ID_Game);
    }
    else
    {
        cout << "**Game Tidak Ditemukan**" << endl;
    }
    cout << endl;

    cout << "-----PRINT GAME dgn DEVELOPER TERTENTU-----" << endl;
    string ID_Studio;
    cout << "ID DEVELOPER: ";
    cin >> ID_Studio;

    Pdev = searchDev(LD, prevDev, ID_Studio);
    if (Pdev != NULL)
    {
        cout << "DEVELOPER: " << info(Pdev).nama << endl;
        printGameBasedDev(LD, ID_Studio);
    }
    else
    {
        cout << "**Developer Tidak Ditemukan**" << endl;
    }
    cout << endl;

    return 0;
}
