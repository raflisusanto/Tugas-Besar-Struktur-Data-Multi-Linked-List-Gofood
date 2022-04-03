#ifndef MLL_GOFOOD_H_INCLUDED
#define MLL_GOFOOD_H_INCLUDED

#include <iostream>
#include <string>

#define infoMerchant(P) (P)->infoMerchant
#define infoOrder(P) (P)->infoOrder
#define nextMerchant(P) (P)->nextMerchant
#define nextOrder(P) (P)->nextOrder
#define infoDriver(P) (P)->infoDriver
#define nextDriver(P) (P)->nextDriver
#define firstMerchant(L) ((L).firstMerchant)
#define firstOrder(M) ((M)->firstOrder)
#define firstDriver(M) ((M).firstDriver)
#define lastMerchant(L) ((L).lastMerchant)
#define driver(P) (P)->driver

using namespace std;

const int nmax = 3;

typedef struct elmMerchant *adr_merch;
typedef struct elmOrder *adr_order;
typedef struct elmDriver *adr_driver;

struct merchant {
    string nama_merchant;
    float rating;
    string nama_makanan[nmax];
    int harga[nmax];
};

struct orderan {
    string orderid;
    string penerima;
    string order_makanan[nmax]; // Warning
    int total_harga;
};

struct driver {
    string nama_driver;
    float rating_driver;
};

struct elmMerchant {
    merchant infoMerchant;
    adr_merch nextMerchant;
    adr_order firstOrder;
};

struct elmOrder {
    orderan infoOrder;
    adr_order nextOrder;
    adr_driver driver;
};

struct elmDriver{
    driver infoDriver;
    adr_driver nextDriver;
};

struct mll {
    adr_merch firstMerchant;
    adr_merch lastMerchant;
};

struct list_driver {
    adr_driver firstDriver;
};

void createMLL (mll &L);
adr_merch alokasi_merchant(string nama, float rating, string makanan[nmax], int harga[nmax]);
adr_order alokasi_order(string id, string pengorder, string order[nmax], int harga);
adr_driver alokasi_driver(string namadriver, float rating);

void insertMerchant (mll &L, adr_merch &X);
void showMerchant (mll L);

adr_order deleteFirstOrder(mll &L, adr_merch X);
adr_order deleteLastOrder(mll &L, adr_merch X);
adr_order deleteAfterOrder(mll &L, adr_merch X, adr_order prev);
adr_order deleteElmOrder(mll &L, adr_merch X, string IDorder);

adr_order findOrder(mll &L, adr_merch X, string IDorder);
void insertOrder (mll &L, adr_merch X, adr_order Y);
void insertDrivertoOrder (mll &L, adr_merch X, adr_order Y, adr_driver Z);

adr_merch findMerch(mll ListMerch, string nama_merchant);

adr_merch deleteFirstMerch(mll &ListMerch);
adr_merch deleteLastMerch(mll &ListMerch);
adr_merch deleteAfterMerch(mll &ListMerch, adr_merch prev);
adr_merch deleteElmMerch(mll &ListMerch, string merchant);

void ShowOrder(mll ListMerch, adr_merch X);

void createListDriver (list_driver &LD);
void insertDriver (list_driver &LD, adr_driver Z);
void deleteDriver (mll &L, list_driver &LD, adr_driver P);

void showDriverofOrderYMerchX (mll L);
void showAllDriver(list_driver LD);
adr_driver findDriver(list_driver LD, string namadriver);

int selectMenu();
int TotalOrder(mll ListMerch, adr_merch X);
void addNDriver(list_driver &LD);
void addNOrdertoMerchX(list_driver &LD, mll &L);
void addNMerchant(mll &L);
void ShowBoomingBisnis(mll L);
void showOrderofMerchantX(mll L);
void showAllOrder(mll L);
void deleteMerchantX (mll &L);
void deleteOrderIDX (mll &L);
void deleteDriverZfromAllOrder (mll &L, adr_driver Z);
void countAllOrder(mll L);
void extremeOrder(mll L);
void addDrivertoOrderY (mll &L, list_driver LD);

void hapusRelasi (mll &L, adr_order &P);
void buatRelasi (mll &L);

#endif // MLL_GOFOOD_H_INCLUDED
