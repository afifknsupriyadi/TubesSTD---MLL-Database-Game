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
        cout << "Elemen tidak ditemukan" << endl;
    }
}
adrDev deleteFirstDev(listDev &LD)
{
    adrDev p;
    if (first(LD) == NULL)
    { // jika list kosong
        cout << "List Kosong" << endl;
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
        cout << "List Kosong" << endl; // jika list kosong
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
        cout << "**Developer Tidak Ditemukan**" << endl;
    }
    return p;
}
adrDev searchDev(listDev LD, adrDev &prev, string ID)
{
    if (first(LD) == NULL)
    {
        cout << "List Kosong" << endl;
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
        cout << "------------------" << endl;
        cout << "Developer ke-" << i << endl;
        cout << "------------------" << endl;
        cout << "ID: " << info(p).ID_Studio << endl;
        cout << "Nama: " << info(p).nama << endl;
        cout << "ThnBerdiri: " << info(p).thnBerdiri << endl;
        cout << "Alamat: " << info(p).alamat << endl;
        cout << "Revenue: " << info(p).revenue << endl;
        p = next(p);
        i++;
    }
    cout << "------------------" << endl;
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
        cout << "Elemen tidak ditemukan" << endl;
    }
}
adrGame deleteFirstGame(listGame &LG)
{
    adrGame p;

    if (first(LG) == NULL)
    { // jika list kosong
        cout << "List Kosong" << endl;
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
        cout << "List Kosong" << endl; // jika list kosong
    }
    else if (next(first(LG)) == NULL)
    {
        p = first(LG);
        first(LG) = NULL; // jika list hanya 1 elemen
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
        cout << "**Game Tidak Ditemukan**" << endl;
    }
    return p;
}

adrGame searchGame(listGame LG, adrGame &prev, string ID)
{
    if (first(LG) == NULL)
    {
        cout << "List Kosong" << endl;
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
        cout << "------------------" << endl;
        cout << "Game ke-" << i << endl;
        cout << "------------------" << endl;
        cout << "ID Game: " << info(p).ID_Game << endl;
        cout << "Nama: " << info(p).nama << endl;
        cout << "Rating: " << info(p).rating << endl;
        cout << "Genre: " << info(p).genre << endl;
        cout << "Platform: " << info(p).platform << endl;
        cout << "Harga: Rp" << info(p).harga << endl;
        cout << "Jml User: " << info(p).jmlPemain << endl;
        p = next(p);
        i++;
    }
    cout << "------------------" << endl;
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
        cout << "List Kosong" << endl;
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
        cout << "List Kosong" << endl; // jika list kosong
        return NULL;
    }
    else if (next(first(LR)) == NULL)
    {
        p = first(LR);
        first(LR) = NULL; // jika list hanya 1 elemen
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
        cout << "List Kosong" << endl;
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
            cout << "Developer tidak ditemukan" << endl;
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
        cout << "Developer atau Game tidak ditemukan" << endl;
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
            cout << "**Game Tidak Ada Dalam List Developer**" << endl;
        }
    }
    else
    {
        cout << "**Developer Tidak Ditemukan**" << endl;
    }
    return p;
}

adrDev deleteDeveloper(listDev &LD, string ID_Studio)
{
    adrDev prev;
    adrDev dev = searchDev(LD, prev, ID_Studio);
    adrDev p;
    adrRelasi q;

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
        }
    }
    else
    {
        cout << "**Developer Tidak Ditemukan**" << endl;
    }
    return p;
}
adrGame deleteGame(listDev &LD, listGame &LG, string ID_Game)
{
    adrDev p = first(LD);
    listRelasi LR;
    adrRelasi q;

    while (p != NULL)
    {
        LR = game(p);
        q = first(LR);
        while (q != NULL)
        {
            if (info(info(q)).ID_Game == ID_Game)
            {
                disconnectGameinDev(LD, info(p).ID_Studio, info(info(q)).ID_Game);
            }
            q = next(q);
        }
        p = next(p);
    }
    adrGame Game = deleteElementGame(LG, ID_Game);

    return Game;
}
void printRelasi(listDev LD)
{
    // Menampilkan data developer beserta game nya
    adrDev Pdev;
    adrRelasi Pr;

    if (first(LD) == NULL)
    {
        cout << "Tidak Ada List" << endl;
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

void printRelasi2(listDev LD)
{
    // Menampilkan data developer beserta game nya
    adrDev Pdev;
    adrRelasi Pr;

    if (first(LD) == NULL)
    {
        cout << "Tidak Ada List" << endl;
    }
    else
    {
        // Perulangan List Developer
        int i = 1;
        Pdev = first(LD);
        while (Pdev != NULL)
        {
            cout << "Developer ke-" << i << " - " << info(Pdev).nama << " (" << info(Pdev).ID_Studio << ")" << endl;
            // Looping List Game
            Pr = first(game(Pdev));
            if (Pr == NULL)
            {
                cout << "**No Game Added**" << endl;
            }
            cout << "Daftar Game: ";
            while (Pr != NULL)
            {
                cout << info(info(Pr)).nama << " (" << info(info(Pr)).ID_Game << ")"
                     << ", ";
                Pr = next(Pr);
            }
            Pdev = next(Pdev);
            i++;
            cout << endl;
            cout << endl;
        }
    }
}
void printDevBasedGame(listDev LD, string ID_Game)
{
    adrDev p;
    adrRelasi q;
    listRelasi LR;

    cout << "Daftar Developer: ";
    p = first(LD);
    while (p != NULL)
    {
        LR = game(p);
        q = first(LR);
        while (q != NULL)
        {
            if (info(info(q)).ID_Game == ID_Game)
            {
                cout << info(p).nama << ", ";
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
    listRelasi LR;

    p = searchDev(LD, prev, ID_Studio);
    LR = game(p);
    q = first(LR);

    cout << "Daftar Game: ";
    while (q != NULL)
    {
        cout << info(info(q)).nama << ", ";
        q = next(q);
    }
    cout << endl;
}
