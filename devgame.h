#ifndef DEVGAME_H_INCLUDED
#define DEVGAME_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define info(P) P->info
#define next(P) P->next
#define game(P) P->game

// Tipe data bentukan Dev, Game dan relasi
struct developer
{
    string ID_Studio;
    string nama;
    string thnBerdiri;
    string alamat;
    int revenue;
};
struct game
{
    string ID_Game;
    string nama;
    string tglRilis;
    float rating;
    string genre;
    string platform;
    string publisher;
    string harga;
    int jmlPemain;
};

typedef struct developer infotypeDev;
typedef struct game infotypeGame;
typedef struct elmDev *adrDev;
typedef struct elmRelasi *adrRelasi;
typedef struct elmGame *adrGame;
struct listRelasi
{
    adrRelasi first;
};
struct listDev
{
    adrDev first;
};
struct listGame
{
    adrGame first;
};

// ADT Developer, Game, Relasi
struct elmDev
{
    infotypeDev info;
    adrDev next;
    listRelasi game;
};
struct elmGame
{
    infotypeGame info;
    adrGame next;
};
struct elmRelasi
{
    adrGame info;
    adrRelasi next;
};

// List Dev
void createListDev(listDev &LD);
adrDev createElmDev(infotypeDev x);
void insertFirstDev(listDev &LD, adrDev p);
void insertLastDev(listDev &LD, adrDev p);
void inserAfterDev(listDev &LD, adrDev p, infotypeDev x);
adrDev deleteFirstDev(listDev &LD);
adrDev deleteLastDev(listDev &LD);
adrDev deleteElementDev(listDev &LD, string ID_Studio);
adrDev searchDev(listDev LD, adrDev &prev, string ID);
void printDev(listDev LD);

// List Game
void createListGame(listGame &LG);
adrGame createElmGame(infotypeGame x);
void insertFirstGame(listGame &LG, adrGame p);
void insertLastGame(listGame &LG, adrGame p);
void inserAfterGame(listGame &LG, adrGame p, infotypeGame x);
adrGame deleteFirstGame(listGame &LG);
adrGame deleteLastGame(listGame &LG);
adrGame deleteElementGame(listGame &LG, string ID_Game);
adrGame searchGame(listGame LG, adrGame &prev, string ID);
void printGame(listGame LG);

// List Relasi
void createListRelasi(listRelasi &LR);
adrRelasi createElmRelasi(adrGame infoRelasi);
void insertLastRelasi(listRelasi &LR, adrRelasi p);
adrRelasi deleteFirstRelasi(listRelasi &LR);
adrRelasi deleteLastRelasi(listRelasi &LR);

adrRelasi searchRelasi(listDev LD, adrRelasi &prevRelasi, infotypeDev xDev, infotypeGame xGame);
void connectGameinDev(listDev &LD, listGame &LG, string ID_Studio, string ID_Game);
adrRelasi disconnectGameinDev(listDev &LD, string ID_Studio, string ID_Game);
adrDev deleteDeveloper(listDev &LD, string ID_Studio);
adrGame deleteGame(listDev &LD, listGame &LG, string ID_Game);

void printDevBasedGame(listDev LD, string ID_Game);
void printGameBasedDev(listDev LD, string ID_Studio);
void printRelasi(listDev LD);
void printRelasi2(listDev LD);

#endif // DEVGAME_H_INCLUDED
