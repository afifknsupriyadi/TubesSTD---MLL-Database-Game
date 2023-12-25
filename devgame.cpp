#include "devgame.h"

void createListDev(listDev &LD)
{
    first(LD) = NULL;
}
adrDev createElmDev(infotypeDev x)
{
    adrDev p = new elmDev;
    info(p) = x;
    next(p) = NULL;
    createListRelasi(game(p));
    return p;
}

void insertFirstDev(listDev &LD, adrDev p)
{
    if (first(LD) == NULL)
    {
        first(LD) = p;
    }
    else
    {
        next(p) = first(LD);
        first(LD) = p;
    }
}
void insertLastDev(listDev &LD, adrDev p)
{
    adrDev q;
    q = first(LD);

    if (first(LD) == NULL)
    {
        first(LD) = p;
    }
    else
    {
        while (next(q) != NULL)
        {
            q = next(q);
        }
        next(q) = p;
    }
}
void inserAfterDev(listDev &LD, adrDev p, infotypeDev x)
{
    adrDev prev;
    adrDev prec = searchDev(LD, prev, x.ID_Studio);

    if (prec != NULL)
    {
        next(p) = next(prec);
        next(prec) = p;
    }
    else
    {
        cout << endl;
        cout << "--Developer Tidak Ada Dalam List--" << endl;
    }
}
adrDev deleteFirstDev(listDev &LD)
{
    adrDev p;
    if (first(LD) == NULL)
    { // jika list kosong
        cout << endl;
        cout << "--List Developer Kosong--" << endl;
    }
    else if (next(first(LD)) == NULL)
    { // jika list hanya 1 elemen
        p = first(LD);
        first(LD) = NULL;
    }
    else
    {
        p = first(LD);
        first(LD) = next(p);
        next(p) = NULL;
    }
    return p;
}
adrDev deleteLastDev(listDev &LD)
{
    adrDev p, q;

    if (first(LD) == NULL)
    {
        cout << endl;
        cout << "--List Developer Kosong--" << endl; // jika list kosong
    }
    else if (next(first(LD)) == NULL)
    {
        p = first(LD);
        first(LD) = NULL; // jika list hanya 1 elemen
    }
    else
    {
        p = first(LD);
        while (next(p) != NULL)
        {
            q = p;
            p = next(p);
        }
        next(q) = NULL;
    }
    return p; // return elemen yg dihapus
}
adrDev deleteElementDev(listDev &LD, string ID_Studio)
{
    adrDev prev;
    adrDev q = searchDev(LD, prev, ID_Studio);
    adrDev p;
    if (q != NULL)
    {
        if (q == first(LD))
        {
            p = deleteFirstDev(LD);
        }
        else if (next(q) == NULL)
        {
            p = deleteLastDev(LD);
        }
        else
        {
            // Algoritma Delete After
            q = prev;
            p = next(q);
            next(q) = next(p);
            next(p) = NULL;
        }
    }
    else
    {
        cout << endl;
        cout << "--Developer Tidak Ada Dalam List--" << endl;
    }
    return p;
}
adrDev searchDev(listDev LD, adrDev &prev, string ID)
{
    if (first(LD) == NULL)
    {
        cout << endl;
        cout << "--List Developer Kosong--" << endl;
    }
    else
    {
        adrDev p = first(LD);

        while (p != NULL)
        {
            if (info(p).ID_Studio == ID)
            {
                return p;
            }
            prev = p;
            p = next(p);
        }
        return NULL;
    }
}
void printDev(listDev LD)
{
    adrDev p;
    int i = 1;

    p = first(LD);
    while (p != NULL)
    {
        cout << "Developer ke-" << i << endl;
        cout << "------------------" << endl;
        cout << "ID: " << info(p).ID_Studio << endl;
        cout << "Nama: " << info(p).nama << endl;
        cout << "ThnBerdiri: " << info(p).thnBerdiri << endl;
        cout << "Alamat: " << info(p).alamat << endl;
        cout << "Revenue: Rp " << info(p).revenue << endl
             << endl;
        p = next(p);
        i++;
    }
}

// Primitive List Game
void createListGame(listGame &LG)
{
    first(LG) = NULL;
}
adrGame createElmGame(infotypeGame x)
{
    adrGame p = new elmGame;
    info(p) = x;
    next(p) = NULL;
    return p;
}
void insertFirstGame(listGame &LG, adrGame p)
{
    if (first(LG) == NULL)
    {
        first(LG) = p;
    }
    else
    {
        next(p) = first(LG);
        first(LG) = p;
    }
}
void insertLastGame(listGame &LG, adrGame p)
{
    adrGame q;
    q = first(LG);

    if (first(LG) == NULL)
    {
        first(LG) = p;
    }
    else
    {
        while (next(q) != NULL)
        {
            q = next(q);
        }
        next(q) = p;
    }
}
void inserAfterGame(listGame &LG, adrGame p, infotypeGame x)
{
    adrGame prev;
    adrGame prec = searchGame(LG, prev, x.ID_Game);

    if (prec != NULL)
    {
        next(p) = next(prec);
        next(prec) = p;
    }
    else
    {
        cout << endl;
        cout << "--Game Tidak Ada Dalam List--" << endl;
    }
}
adrGame deleteFirstGame(listGame &LG)
{
    adrGame p;

    if (first(LG) == NULL)
    { // jika list kosong
        cout << endl;
        cout << "--List Game Kosong--" << endl;
    }
    else if (next(first(LG)) == NULL)
    { // jika list hanya 1 elemen
        p = first(LG);
        first(LG) = NULL;
    }
    else
    {
        p = first(LG);
        first(LG) = next(p);
        next(p) = NULL;
    }
    return p;
}
adrGame deleteLastGame(listGame &LG)
{
    adrGame p, q;

    if (first(LG) == NULL)
    {
        cout << endl;
        cout << "--List Game Kosong--" << endl;
    }
    else if (next(first(LG)) == NULL)
    {
        p = first(LG);
        first(LG) = NULL;
    }
    else
    {
        p = first(LG);
        while (next(p) != NULL)
        {
            q = p;
            p = next(p);
        }
        next(q) = NULL;
    }
    return p; // return elemen yg dihapus
}
adrGame deleteElementGame(listGame &LG, string ID_Game)
{
    adrGame prev;
    adrGame q = searchGame(LG, prev, ID_Game);
    adrGame p;
    if (q != NULL)
    {
        if (q == first(LG))
        {
            p = deleteFirstGame(LG);
        }
        else if (next(q) == NULL)
        {
            p = deleteLastGame(LG);
        }
        else
        {
            // Algoritma Delete After
            p = q;
            next(p) = NULL;
        }
    }
    else
    {
        cout << endl;
        cout << "--Game Tidak Ada Dalam List--" << endl;
    }
    return p;
}

adrGame searchGame(listGame LG, adrGame &prev, string ID)
{
    if (first(LG) == NULL)
    {
        cout << endl;
        cout << "--List Game Kosong--" << endl;
    }
    else
    {
        adrGame p = first(LG);
        while (p != NULL)
        {
            if (info(p).ID_Game == ID)
            {
                return p;
            }
            prev = p;
            p = next(p);
        }
        return NULL;
    }
}
void printGame(listGame LG)
{
    adrGame p;
    int i = 1;

    p = first(LG);
    while (p != NULL)
    {
        cout << "Game ke-" << i << endl;
        cout << "------------------" << endl;
        cout << "ID Game: " << info(p).ID_Game << endl;
        cout << "Nama: " << info(p).nama << endl;
        cout << "Rating: " << info(p).rating << endl;
        cout << "Genre: " << info(p).genre << endl;
        cout << "Platform: " << info(p).platform << endl;
        cout << "Harga: Rp " << info(p).harga << endl;
        cout << "Jml User: " << info(p).jmlPemain << endl
             << endl;
        p = next(p);
        i++;
    }
}

// Primitive List Relasi
void createListRelasi(listRelasi &LR)
{
    first(LR) = NULL;
}
adrRelasi createElmRelasi(adrGame xGame)
{
    adrRelasi p = new elmRelasi;
    info(p) = xGame;
    next(p) = NULL;
    return p;
}
void insertLastRelasi(listRelasi &LR, adrRelasi p)
{
    if (first(LR) == NULL)
    {
        first(LR) = p;
    }
    else
    {
        adrRelasi q;
        q = first(LR);
        while (next(q) != NULL)
        {
            q = next(q);
        }
        next(q) = p;
    }
}
adrRelasi deleteFirstRelasi(listRelasi &LR)
{
    adrRelasi p;
    if (first(LR) == NULL)
    { // jika list kosong
        cout << endl;
        cout << "--List Relasi Kosong--" << endl;
    }
    else if (next(first(LR)) == NULL)
    { // jika list hanya 1 elemen
        p = first(LR);
        first(LR) = NULL;
    }
    else
    {
        p = first(LR);
        first(LR) = next(p);
        next(p) = NULL;
    }
    return p;
}
adrRelasi deleteLastRelasi(listRelasi &LR)
{
    adrRelasi p, q;

    if (first(LR) == NULL)
    {
        cout << endl;
        cout << "--List Relasi Kosong--" << endl;
        return NULL;
    }
    else if (next(first(LR)) == NULL)
    {
        p = first(LR);
        first(LR) = NULL;
    }
    else
    {
        p = first(LR);
        while (next(p) != NULL)
        {
            q = p;
            p = next(p);
        }
        next(q) = NULL;
    }
    return p; // return elemen yg dihapus
}
adrRelasi searchRelasi(listDev LD, adrRelasi &prevRelasi, string ID_Studio, string ID_Game)
{
    adrDev prevDev;
    if (first(LD) == NULL)
    {
        cout << endl;
        cout << "--List Developer Kosong--" << endl;
    }
    else
    {
        adrDev pDev = searchDev(LD, prevDev, ID_Studio);
        if (pDev != NULL)
        {
            adrRelasi pRelasi = first(game(pDev));
            while (pRelasi != NULL)
            {
                // pRelasi.info.info.ID_Game
                if (info(info(pRelasi)).ID_Game == ID_Game)
                {
                    return pRelasi;
                }
                prevRelasi = pRelasi;
                pRelasi = next(pRelasi);
            }
            return NULL;
        }
        else
        {
            cout << endl;
            cout << "--Developer Tidak Ada Dalam List--" << endl;
            return NULL;
        }
    }
}
void connectGameinDev(listDev &LD, listGame &LG, string ID_Studio, string ID_Game)
{
    adrDev Pdev, prevDev;
    adrGame Pgame, prevGame;
    adrRelasi Pr;

    Pdev = searchDev(LD, prevDev, ID_Studio);
    Pgame = searchGame(LG, prevGame, ID_Game);
    if (Pdev != NULL && Pgame != NULL)
    {
        Pr = createElmRelasi(Pgame);
        insertLastRelasi(game(Pdev), Pr);
    }
    else
    {
        cout << endl;
        cout << "--Developer atau Game Tidak Ada Dalam List--";
    }
}
adrRelasi disconnectGameinDev(listDev &LD, string ID_Studio, string ID_Game)
{
    adrDev pDev, prevDev;
    adrRelasi pRelasi, prevRelasi;
    adrRelasi p = NULL;

    pDev = searchDev(LD, prevDev, ID_Studio);
    if (pDev != NULL)
    {
        pRelasi = searchRelasi(LD, prevRelasi, ID_Studio, ID_Game);
        if (pRelasi != NULL)
        {
            // Jika xGame elm pertama list relasi pada list Dev
            if (pRelasi == first(game(pDev)))
            {
                p = deleteFirstRelasi(game(pDev));
                // Jika xGame elm terakhir list relasi pada list Dev
            }
            else if (next(pRelasi) == NULL)
            {
                p = deleteLastRelasi(game(pDev));
                // Jika xGame berada di tengah list relasi pada list Dev
            }
            else
            {
                // Algoritma deleteAfter
                pRelasi = prevRelasi;
                p = next(pRelasi);
                next(pRelasi) = next(p);
                next(p) = NULL;
            }
        }
        else
        {
            cout << endl;
            cout << "--Game Tidak Ada Dalam List Developer--" << endl;
            return NULL;
        }
    }
    else
    {
        cout << endl;
        cout << "--Developer Tidak Ada Dalam List--" << endl;
        return NULL;
    }
    return p;
}

adrDev deleteDeveloper(listDev &LD, string &ID_Studio)
{
    adrDev prev;
    adrDev p;
    adrRelasi q;

    cout << endl;
    cout << "Delete List Developer" << endl;
    cout << "----------------------" << endl;

    cout << "ID Developer\t: ";
    cin >> ID_Studio;

    adrDev dev = searchDev(LD, prev, ID_Studio);
    if (dev != NULL)
    {
        if (first(game(dev)) == NULL)
        {
            p = deleteElementDev(LD, ID_Studio);
        }
        else
        {
            // p = first list relasi
            q = first(game(dev));
            // Empty list relasi
            first(game(dev)) = NULL;
            p = deleteElementDev(LD, ID_Studio);

            cout << endl;
            cout << "--Developer " << info(p).nama << "(" << info(p).ID_Studio << ")"
                 << " Telah Terhapus Dari List Game--" << endl;
            return p;
        }
    }
    else
    {
        cout << endl;
        cout << "--Developer Tidak Ada Dalam List--" << endl;
        return NULL;
    }
}
adrGame deleteGame(listDev &LD, listGame &LG, string &ID_Game)
{
    adrGame Pgame, xGame, prevGame;
    adrDev Pdev;
    adrRelasi Prelasi;

    cout << endl;
    cout << "Delete List Game" << endl;
    cout << "----------------------" << endl;

    cout << "ID Game\t: ";
    cin >> ID_Game;

    xGame = searchGame(LG, prevGame, ID_Game);
    if (xGame != NULL)
    {
        Pdev = first(LD);
        while (Pdev != NULL)
        {
            Prelasi = first(game(Pdev));
            while (Prelasi != NULL)
            {
                if (info(info(Prelasi)).ID_Game == ID_Game)
                {
                    disconnectGameinDev(LD, info(Pdev).ID_Studio, info(info(Prelasi)).ID_Game);
                }
                Prelasi = next(Prelasi);
            }
            Pdev = next(Pdev);
        }
        Pgame = deleteElementGame(LG, ID_Game);

        cout << endl;
        cout << "--Game " << info(Pgame).nama << "(" << info(Pgame).ID_Game << ")"
             << " Telah Terhapus Dari List Game--" << endl;
        return Pgame;
    }
    else
    {
        cout << endl;
        cout << "--Game Tidak Ada Dalam List--" << endl;
        return NULL;
    }
}
void printRelasi(listDev LD)
{
    // Menampilkan data developer beserta game nya
    adrDev Pdev;
    adrRelasi Pr;

    if (first(LD) == NULL)
    {
        cout << endl;
        cout << "--List Developer Kosong--" << endl;
    }
    else
    {
        // Perulangan List Developer
        int i = 1;
        Pdev = first(LD);
        while (Pdev != NULL)
        {
            cout << "Developer ke-" << i << endl;
            cout << "------------------------------" << endl;
            // cout<<Pdev.info.ID_Studio<<endl;
            // cout<<Pdev.info.nama<<endl;
            cout << "ID Studio: " << info(Pdev).ID_Studio << endl;
            cout << "Nama Studio: " << info(Pdev).nama << endl;
            // Looping List Game
            Pr = first(game(Pdev));
            int j = 1;
            if (Pr == NULL)
            {
                cout << "**No Game Added**" << endl;
            }
            while (Pr != NULL)
            {
                cout << endl;
                cout << "Game ke-" << j << endl;
                // cout<<Pr.info.info.ID_Game<<endl;
                cout << "ID_Game: " << info(info(Pr)).ID_Game << endl;
                cout << "Nama Game: " << info(info(Pr)).nama << endl;
                Pr = next(Pr);
                j++;
            }
            Pdev = next(Pdev);
            i++;
            cout << "------------------------------" << endl;
            cout << endl;
        }
    }
}

void printDevBasedGame(listDev LD, string ID_Game)
{
    adrDev p;
    adrRelasi q;

    cout << "Daftar Developer: ";
    p = first(LD);
    while (p != NULL)
    {
        q = first(game(p));
        while (q != NULL)
        {
            if (info(info(q)).ID_Game == ID_Game)
            {
                cout << info(p).nama << " (" << info(p).ID_Studio << ")"
                     << ", ";
            }
            q = next(q);
        }
        p = next(p);
    }
    cout << endl;
}
void printGameBasedDev(listDev LD, string ID_Studio)
{
    adrDev p, prev;
    adrRelasi q;

    p = searchDev(LD, prev, ID_Studio);
    q = first(game(p));

    cout << "Daftar Game\t: ";
    while (q != NULL)
    {
        cout << info(info(q)).nama << " (" << info(info(q)).ID_Game << ")"
             << ", ";
        q = next(q);
    }
    cout << endl;
}
void printGameBasedGenre(listDev LD, string genre)
{
    adrDev p;
    adrRelasi q;

    p = first(LD);
    while (p != NULL)
    {
        q = first(game(p));
        while (q != NULL)
        {
            if (info(info(q)).genre == genre)
            {
                cout << "ID Game\t: " << info(info(q)).ID_Game << endl;
                cout << "Game\t: " << info(info(q)).nama << endl;
                cout << "Genre\t: " << info(info(q)).genre << endl;
                cout << "Developer\t: " << info(p).nama << endl;
                cout << endl;
            }
            q = next(q);
        }
        p = next(p);
    }
}
void printGameByGenre(listDev LD, string genre)
{
    adrDev d;
    adrRelasi r;
    adrGame g, gNew;

    listGame LGnew;
    bool cekAda = false;
    createListGame(LGnew);

    d = first(LD);
    while (d != NULL)
    {
        r = first(game(d));
        while (r != NULL)
        {
            if (info(info(r)).genre == genre)
            {
                gNew = createElmGame(info(info(r)));
                if (first(LGnew) == NULL)
                {
                    cekAda = false;
                }
                else
                {
                    g = first(LGnew);
                    while (g != NULL && cekAda == false)
                    {

                        if (info(g).ID_Game == info(info(r)).ID_Game)
                        {
                            cekAda = true;
                        }

                        g = next(g);
                    }
                }
                if (cekAda == false)
                {
                    insertLastGame(LGnew, gNew);
                    cout << "ID Game\t: " << info(info(r)).ID_Game << endl;
                    cout << "Game\t: " << info(info(r)).nama << endl;
                    cout << "Genre\t: " << info(info(r)).genre << endl;
                    printDevBasedGame(LD, info(info(r)).ID_Game);
                    cout << endl;
                }
            }
            r = next(r);
            cekAda = false;
        }
        d = next(d);
    }
}
void printGameByGenre2(listDev LD, listGame LG, string genre)
{
    adrGame g;

    g = first(LG);
    while (g != NULL)
    {
        if (info(g).genre == genre)
        {
            cout << "ID Game\t: " << info(g).ID_Game << endl;
            cout << "Game\t: " << info(g).nama << endl;
            cout << "Genre\t: " << info(g).genre << endl;
            printDevBasedGame(LD, info(g).ID_Game);
            cout << endl;
        }
        g = next(g);
    }
}
void printGameBasedPlatform(listDev LD, string platform)
{
    adrDev d;
    adrGame g;
    adrRelasi r;

    d = first(LD);
    while (d != NULL)
    {
        r = first(game(d));
        while (r != NULL)
        {
            if (info(info(r)).platform == platform)
            {
                cout << "ID Game\t: " << info(info(r)).ID_Game << endl;
                cout << "Game\t: " << info(info(r)).nama << endl;
                cout << "Genre\t: " << info(info(r)).genre << endl;
                cout << "Developer\t: " << info(d).nama << endl;
                cout << endl;
            }
            r = next(r);
        }
        d = next(d);
    }
}
void printGameByPlatform(listDev LD, string platform)
{
    adrDev d;
    adrGame g, gNew;
    adrRelasi r;
    bool cekAda = false;

    listGame LGnew;
    createListGame(LGnew);

    d = first(LD);
    while (d != NULL)
    {
        r = first(game(d));
        while (r != NULL)
        {
            if (info(info(r)).platform == platform)
            {
                gNew = createElmGame(info(info(r)));
                if (first(LGnew) == NULL)
                {
                    cekAda = false;
                }
                else
                {
                    g = first(LGnew);
                    while (g != NULL && cekAda == false)
                    {
                        if (info(info(r)).ID_Game == info(g).ID_Game)
                        {
                            cekAda = true;
                        }
                        g = next(g);
                    }
                }
                if (cekAda == false)
                {
                    insertLastGame(LGnew, gNew);
                    cout << "ID Game\t: " << info(info(r)).ID_Game << endl;
                    cout << "Game\t: " << info(info(r)).nama << endl;
                    cout << "Platform\t: " << info(info(r)).platform << endl;
                    printDevBasedGame(LD, info(info(r)).ID_Game);
                    cout << endl;
                }
            }
            r = next(r);
            cekAda = false;
        }
        d = next(d);
    }
}

void printGameByPlatform2(listDev LD, listGame LG, string platform)
{
    adrGame g;

    g = first(LG);
    while (g != NULL)
    {
        if (info(g).platform == platform)
        {
            cout << "ID Game\t: " << info(g).ID_Game << endl;
            cout << "Game\t: " << info(g).nama << endl;
            cout << "Platform\t: " << info(g).platform << endl;
            printDevBasedGame(LD, info(g).ID_Game);
            cout << endl;
        }
        g = next(g);
    }
}

adrGame printHighestRatingGame(listGame LG)
{
    adrGame g, gMax;

    g = first(LG);
    gMax = first(LG);
    while (g != NULL)
    {
        if (info(g).rating > info(gMax).rating)
        {
            gMax = g;
        }
        g = next(g);
    }
    return gMax;
}
adrGame printGameWithMostUser(listGame LG)
{
    adrGame g, gMax;

    g = first(LG);
    gMax = first(LG);
    while (g != NULL)
    {
        if (info(g).jmlPemain > info(gMax).jmlPemain)
        {
            gMax = g;
        }
        g = next(g);
    }
    return gMax;
}
void menu(listDev &LD, listGame &LG)
{
    int pilih;

    while (pilih != 6)
    {
        cout << "^+==================================^+" << endl;
        cout << "^|-------PROGRAM DATABASE GAME-------|^" << endl;
        cout << "^+==================================^+" << endl;
        cout << "[1] List Developer" << endl;
        cout << "[2] List Game" << endl;
        cout << "[3] List Relasi" << endl;
        cout << "[4] Show Developer by Game" << endl;
        cout << "[5] Show Game by Developer" << endl;
        cout << "[6] Keluar" << endl;
        cout << "^+----------------------------------^+" << endl;

        cout << "Pilih Menu\t: ";
        cin >> pilih;

        while (pilih != 1 && pilih != 2 && pilih != 3 && pilih != 4 && pilih != 5 && pilih != 6)
        {
            cout << "Input tidak valid, pilih menu: ";
            cin >> pilih;
        }

        if (pilih == 1)
        {
            ListDeveloperMenu(LD);
            cout << endl;
        }
        else if (pilih == 2)
        {
            ListGameMenu(LD, LG);
            cout << endl;
        }
        else if (pilih == 3)
        {
            listRelasiMenu(LD, LG);
            cout << endl;
        }

        else if (pilih == 4)
        {
            showDevByGame(LD, LG);
            cout << endl;
        }
        else if (pilih == 5)
        {
            showGamebyDev(LD, LG);
            cout << endl;
        }
    }
    cout << endl;
    cout << "^+----------------------------^+" << endl;
    cout << "^| ...Existing from App... |^" << endl;
    cout << "^+----------------------------^+" << endl;
}

void ListDeveloperMenu(listDev &LD)
{
    int pilih;

    while (pilih != 4)
    {
        cout << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "^|     ...LIST DEVELOPER...    |^" << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "[1] Input List Developer" << endl;
        cout << "[2] Show List Developer" << endl;
        cout << "[3] Delete List Developer" << endl;
        cout << "[4] Keluar" << endl;
        cout << "^+----------------------------^+" << endl;

        cout << "Pilih Menu\t: ";
        cin >> pilih;

        while (pilih != 1 && pilih != 2 && pilih != 3 && pilih != 4)
        {
            cout << "Input tidak valid, pilih menu: ";
            cin >> pilih;
        }

        if (pilih == 1)
        {
            inputListDev(LD);
        }
        else if (pilih == 2)
        {
            showListDev(LD);
        }
        else if (pilih == 3)
        {
            string ID_Dev;
            deleteDeveloper(LD, ID_Dev);
        }
    }
}

void ListGameMenu(listDev LD, listGame &LG)
{
    int pilih;

    while (pilih != 4)
    {
        cout << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "^|       ...LIST GAME...       |^" << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "[1] Input List Game" << endl;
        cout << "[2] Show List Game" << endl;
        cout << "[3] Delete List Game" << endl;
        cout << "[4] Keluar" << endl;
        cout << "^+----------------------------^+" << endl;

        cout << "Pilih Menu\t: ";
        cin >> pilih;

        while (pilih != 1 && pilih != 2 && pilih != 3 && pilih != 4)
        {
            cout << "Input tidak valid, pilih menu: ";
            cin >> pilih;
        }

        if (pilih == 1)
        {
            inputListGame(LG);
        }
        else if (pilih == 2)
        {
            showListGame(LG);
        }
        else if (pilih == 3)
        {
            string ID_Game;
            deleteGame(LD, LG, ID_Game);
        }
    }
}
void listRelasiMenu(listDev LD, listGame LG)
{
    int pilih;

    while (pilih != 4)
    {
        cout << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "^|      ...LIST RELASI...      |^" << endl;
        cout << "^+----------------------------^+" << endl;
        cout << "[1] Connect Game in Developer" << endl;
        cout << "[2] Disconnect Game in Developer" << endl;
        cout << "[3] Show Relasi Developer & Game" << endl;
        cout << "[4] Keluar" << endl;
        cout << "^+----------------------------^+" << endl;

        cout << "Pilih Menu\t: ";
        cin >> pilih;

        while (pilih != 1 && pilih != 2 && pilih != 3 && pilih != 4)
        {
            cout << "Input tidak valid, pilih menu: ";
            cin >> pilih;
        }

        if (pilih == 1)
        {
            connect(LD, LG);
        }
        else if (pilih == 2)
        {
            disconnect(LD, LG);
        }
        else if (pilih == 3)
        {
            showRelasiDevGame(LD);
        }
    }
}

void inputListDev(listDev &LD)
{
    adrDev Pdev;
    infotypeDev xDev;

    int n;
    cout << endl;
    cout << "Input List Developer" << endl;
    cout << "----------------------" << endl;

    // cout<<"Banyak Developer: ";
    // cin>>n;
    for (int i = 0; i < 8; i++)
    {
        cin >> xDev.ID_Studio >> xDev.nama >> xDev.thnBerdiri >> xDev.alamat >> xDev.revenue;
        Pdev = createElmDev(xDev);
        insertLastDev(LD, Pdev);
    }
}
void inputListGame(listGame &LG)
{
    adrGame Pgame;
    infotypeGame xGame;

    int n;
    cout << endl;
    cout << "Input List Game" << endl;
    cout << "----------------------" << endl;

    // cin>>n;
    for (int i = 0; i < 11; i++)
    {
        cin >> xGame.ID_Game >> xGame.nama >> xGame.rating >> xGame.genre >> xGame.platform >> xGame.harga >> xGame.jmlPemain;
        Pgame = createElmGame(xGame);
        insertLastGame(LG, Pgame);
    }
}
void showListDev(listDev LD)
{
    cout << endl;
    cout << "Show List Developer    " << endl;
    cout << "----------------------" << endl;

    if (first(LD) == NULL)
    {
        cout << endl;
        cout << "--List Developer Kosong--" << endl;
    }
    else
    {
        printDev(LD);
    }
}
void showListGame(listGame LG)
{
    cout << endl;
    cout << "Show List Game" << endl;
    cout << "----------------------" << endl;
    if (first(LG) == NULL)
    {
        cout << endl;
        cout << "--List Game Kosong--" << endl;
    }
    else
    {
        printGame(LG);
    }
}

void connect(listDev LD, listGame LG)
{
    cout << endl;
    cout << "Connect Developer & Game" << endl;
    cout << "----------------------------" << endl;

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
    connectGameinDev(LD, LG, "14", "011");

    connectGameinDev(LD, LG, "15", "001");
    connectGameinDev(LD, LG, "15", "006");
    connectGameinDev(LD, LG, "15", "007");
    connectGameinDev(LD, LG, "15", "008");
    connectGameinDev(LD, LG, "15", "009");
    connectGameinDev(LD, LG, "15", "010");

    connectGameinDev(LD, LG, "18", "011");

    cout << endl;
    cout << "--Successfully Connected--" << endl;
    cout << endl;
}
void disconnect(listDev LD, listGame LG)
{
    adrRelasi Prel;
    adrDev Pdev, prevDev;
    string ID_Dev, ID_Game;

    cout << endl;
    cout << "Disconnect Game in Dev" << endl;
    cout << "----------------------------" << endl;

    cout << "ID Game\t\t: ";
    cin >> ID_Game;
    cout << "ID Developer\t: ";
    cin >> ID_Dev;

    Prel = disconnectGameinDev(LD, ID_Dev, ID_Game);
    if (Prel != NULL)
    {
        Pdev = searchDev(LD, prevDev, ID_Dev);
        cout << endl;
        cout << "--Game " << info(info(Prel)).nama << "(" << info(info(Prel)).ID_Game << ")"
             << " Telah Terhapus Dari Developer" << info(Pdev).nama << "(" << info(Pdev).ID_Studio << ")--" << endl;
    }
}
void showRelasiDevGame(listDev LD)
{
    // Menampilkan data developer beserta game nya
    adrDev Pdev;
    adrRelasi Pr;

    cout << endl;
    cout << "Show Relasi Developer & Game" << endl;
    cout << "----------------------------" << endl;

    if (first(LD) == NULL)
    {
        cout << "Tidak Ada List" << endl;
    }
    else
    {
        // Perulangan List Developer
        Pdev = first(LD);
        while (Pdev != NULL)
        {
            cout << "Developer: " << info(Pdev).nama << " (" << info(Pdev).ID_Studio << ")" << endl;
            // Looping List Game
            Pr = first(game(Pdev));
            cout << "Daftar Game: " << endl;
            if (Pr == NULL)
            {
                cout << "0. No Game Added" << endl;
            }
            else
            {
                int i = 1;
                while (Pr != NULL)
                {

                    cout << i << ". " << info(info(Pr)).nama << " (" << info(info(Pr)).ID_Game << ")" << endl;
                    Pr = next(Pr);
                    i++;
                }
            }
            Pdev = next(Pdev);
            cout << endl;
        }
    }
}
void showDevByGame(listDev LD, listGame LG)
{
    cout << endl;
    cout << "Show Developer by Game" << endl;
    cout << "----------------------------" << endl;

    adrGame prevGame;
    adrGame xGame;
    // string ID_Game;

    // cout << "ID Game\t\t: ";
    // cin >> ID_Game;
    // cout << endl;

    xGame = searchGame(LG, prevGame, "002");
    if (xGame != NULL)
    {
        cout << "Nama Game\t: " << info(xGame).nama << " (" << info(xGame).ID_Game << ")" << endl;
        printDevBasedGame(LD, "002");
    }
    else
    {
        cout << endl;
        cout << "--Game Tidak Ada Dalam List--" << endl;
    }
}
void showGamebyDev(listDev LD, listGame LG)
{
    cout << endl;
    cout << "Show Game by Developer" << endl;
    cout << "----------------------------" << endl;

    adrDev prevDev;
    adrDev xDev;
    // string ID_Developer;

    // cout << "ID Developer: ";
    // cin >> ID_Developer;
    // cout << endl;

    xDev = searchDev(LD, prevDev, "12");
    if (xDev != NULL)
    {
        cout << "Nama Developer\t: " << info(xDev).nama << "(" << info(xDev).ID_Studio << ")" << endl;
        printGameBasedDev(LD, "12");
    }
    else
    {
        cout << endl;
        cout << "--Developer Tidak Ada Dalam List--" << endl;
    }
}
