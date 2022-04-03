#include "mll_gofood.h"

int main()
{
    // Initialize
    mll L;
    list_driver LD;
    adr_merch X;
    adr_order Y;
    adr_driver Z;
    adr_driver R;

    createMLL(L);
    createListDriver(LD);

    // Insert Driver
    Z = alokasi_driver("Rapli", 5.0);
    insertDriver(LD, Z);
    Z = alokasi_driver("Riski", 4.7);
    insertDriver(LD, Z);
    Z = alokasi_driver("Sutarman", 4.9);
    insertDriver(LD, Z);
    Z = alokasi_driver("Andri", 4.6);
    insertDriver(LD, Z);
    Z = alokasi_driver("Royadi", 5.0);
    insertDriver(LD, Z);

    cout << "====== Showing Drivers List ======" << endl;
    showAllDriver(LD);

    // Insert Merchant
    // 1
    string menu[nmax] = {"Nasi Goreng", "Nasi Bakar", "Nasi Kuning"};
    int harga[nmax] = {15000, 15000, 15000};
    X = alokasi_merchant("Alcove", 4.5, menu, harga);
    insertMerchant(L, X);

    // 2
    string menu1[nmax] = {"Pizza Tuna", "Spaghetti", "Orange Juice"};
    int harga1[nmax] = {50000, 30000, 15000};
    X = alokasi_merchant("Pizza Hut", 4.8, menu1, harga1);
    insertMerchant(L, X);

    // 3
    string menu2[nmax] = {"Ekado", "Salad", "Spicy Chicken Roll"};
    int harga2[nmax] = {32000, 12000, 30000};
    X = alokasi_merchant("Hoka Bento", 4.7, menu2, harga2);
    insertMerchant(L, X);

    // 4
    string menu3[nmax] = {"Ayam Ori", "Burger", "Ayam Pedes"};
    int harga3[nmax] = {15000, 5000, 15000};
    X = alokasi_merchant("KFC", 4.9, menu3, harga3);
    insertMerchant(L, X);

    cout << "====== Showing Merchants List ======" << endl;
    showMerchant(L);

    // Insert Orders + Masukin Driver ke Order
    // 1
    X = findMerch(L, "Alcove");
    Y = alokasi_order("A", "Rapli", menu, 45000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Sutarman");
    insertDrivertoOrder(L, X, Y, Z);

    Y = alokasi_order("B", "Ilpar", menu, 45000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Riski");
    insertDrivertoOrder(L, X, Y, Z);

    Y = alokasi_order("C", "Lapri", menu, 45000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Rapli");
    insertDrivertoOrder(L, X, Y, Z);

    cout << "====== Showing " << infoMerchant(X).nama_merchant << " Orders ======" << endl;
    ShowOrder(L, X);

    // 2
    X = findMerch(L, "Pizza Hut");
    Y = alokasi_order("A1", "Royadi", menu1, 95000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Sutarman");
    insertDrivertoOrder(L, X, Y, Z);

    Y = alokasi_order("B1", "Idayor", menu1, 95000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Riski");
    insertDrivertoOrder(L, X, Y, Z);

    cout << "====== Showing " << infoMerchant(X).nama_merchant << " Orders ======" << endl;
    ShowOrder(L, X);

    // 3 (No Orders)
    // 4
    X = findMerch(L, "KFC");
    Y = alokasi_order("A3", "Rayodi", menu3, 35000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Royadi");
    insertDrivertoOrder(L, X, Y, Z);

    Y = alokasi_order("B3", "Budi", menu3, 35000);
    insertOrder(L, X, Y);
    Z = findDriver(LD, "Andri");
    insertDrivertoOrder(L, X, Y, Z);

    cout << "====== Showing " << infoMerchant(X).nama_merchant << " Orders ======" << endl;
    ShowOrder(L, X);

    cout << "==================INITIALIZE COMPLETE==================" << endl;
    cout << endl;
    int pilihan = 0;
    pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
        case 1:
            cout << "====== Showing Merchants List ======" << endl;
            showMerchant(L);
            cout<<endl;
            break;
        case 2:
            cout<<endl;
            cout << "====== Showing Booming Business ======" << endl;
            ShowBoomingBisnis(L);
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            cout << "====== Showing Drivers List ======" << endl;
            showAllDriver(LD);
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            showOrderofMerchantX(L);
            cout << endl;
            break;
        case 5:
            cout<<endl;
            showAllOrder(L);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            addNMerchant(L);
            cout<<endl;
            break;
        case 7:
           cout<<endl;
           addNDriver(LD);
           cout<<endl;
           break;
        case 8:
           cout<<endl;
           addNOrdertoMerchX(LD, L);
           cout<<endl;
           break;
        case 9:
           cout<<endl;
           deleteMerchantX(L);
           cout<<endl;
           break;
        case 10:
           cout<<endl;
           deleteOrderIDX(L);
           cout<<endl;
           break;
        case 11:
           cout<<endl;
           deleteDriver(L, LD, R);
           cout<<"First Driver Deleted"<<endl;
           cout<<endl;
           break;
        case 12:
           cout<<endl;
           showDriverofOrderYMerchX(L);
           cout<<endl;
           break;
        case 13:
           cout<<endl;
           cout << "====== Showing Order Count ======" << endl;
           countAllOrder(L);
           cout<<endl;
           break;
        case 14:
           cout<<endl;
           cout << "====== Showing Min/Max Order ======" << endl;
           extremeOrder(L);
           cout<<endl;
           break;
        case 15:
           cout<<endl;
           addDrivertoOrderY(L, LD);
           cout<<endl;
           break;
        case 16:
           cout<<endl;
           buatRelasi(L);
           cout<<endl;
           break;
        }
        pilihan = selectMenu();
    }


    return 0;
}
