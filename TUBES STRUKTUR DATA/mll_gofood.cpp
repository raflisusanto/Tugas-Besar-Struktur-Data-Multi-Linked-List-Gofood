#include "mll_gofood.h"

void createMLL (mll &L) {
    firstMerchant(L) = NULL;
    lastMerchant(L) = NULL;
}

adr_merch alokasi_merchant(string nama, float rating, string makanan[nmax], int harga[nmax]) {
    adr_merch X;

    X = new elmMerchant;
    infoMerchant(X).nama_merchant = nama;
    infoMerchant(X).rating = rating;
    for (int i = 0; i < nmax; i++) {
        infoMerchant(X).nama_makanan[i] = makanan[i];
        infoMerchant(X).harga[i] = harga[i];
    }
    nextMerchant(X) = NULL;
    firstOrder(X) = NULL;
    return X;
}

adr_order alokasi_order(string id, string pengorder, string order[nmax], int harga){
    adr_order Y;

    Y = new elmOrder;

    infoOrder(Y).orderid = id;
    infoOrder(Y).penerima = pengorder;
    for (int i = 0; i < nmax; i++) {
        infoOrder(Y).order_makanan[i] = order[i];
    }
    infoOrder(Y).total_harga = harga;

    nextOrder(Y) = NULL;
    driver(Y) = NULL;
    return Y;
}

adr_driver alokasi_driver(string namadriver, float rating){
    adr_driver Z;

    Z = new elmDriver;

    infoDriver(Z).nama_driver = namadriver;
    infoDriver(Z).rating_driver = rating;
    nextDriver(Z) = NULL;
    return Z;
}

// InsertLast
void insertMerchant (mll &L, adr_merch &X) {
    if (firstMerchant(L) == NULL) {
        firstMerchant(L) = X;
        lastMerchant(L) = X;
    } else {
        adr_merch P = firstMerchant(L);
        while (nextMerchant(P) != NULL) {
            P = nextMerchant(P);
        }
        nextMerchant(P) = X;
        lastMerchant(L) = nextMerchant(P);
    }
}

void showMerchant (mll L) {
    if (firstMerchant(L) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        adr_merch P = firstMerchant(L);
        while (P != NULL) {
            cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
            cout << "Rating: " << infoMerchant(P).rating << endl;
            cout << "Menu: " << endl;
            for (int i = 0; i < nmax; i++) {
                cout << i+1 << " " << infoMerchant(P).nama_makanan[i] << endl;
                cout << " " << " " << infoMerchant(P).harga[i] << endl;
            }
            cout << endl;
            P = nextMerchant(P);
        }
    }
}

adr_order deleteFirstOrder(mll &L, adr_merch X) {
    adr_order P;

    if (firstOrder(X) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (nextOrder(firstOrder(X))== NULL){
        P = firstOrder(X);
        firstOrder(X) == NULL;
    } else {
        P = firstOrder(X);
        firstOrder(X) = next(firstOrder(X));
        next(P) == NULL;
    }
    return P;
}

adr_order deleteLastOrder(mll &L, adr_merch X) {
    adr_order P = NULL;

    if (firstOrder(X) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (next(firstOrder(X))== NULL){
        P = firstOrder(X);
        firstOrder(X) == NULL;
    } else {
        adr_order Q = firstOrder(X);
        while (nextOrder(Q) != NULL) {
            Q = nextOrder(Q);
        }
        P = nextOrder(Q);
        nextOrder(Q) = NULL;
    }
    return P;
}

adr_order deleteAfterOrder(mll &L, adr_merch X, adr_order prev) {
    adr_order P = NULL;

    if (firstOrder(X) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (next(firstOrder(X))== NULL){
        P = firstOrder(X);
        firstOrder(X) == NULL;
    } else {
        P = nextOrder(prev);
        nextOrder(prev) = nextOrder(P);
        nextOrder(P) = NULL;
    }
    return P;
}

adr_order deleteElmOrder (mll &L, adr_merch X, string IDorder){
    adr_order P;
    adr_order Q;
    adr_order prec;

    if (firstOrder(X) != NULL) {
        Q = firstOrder(X);
        while (nextOrder(Q) != NULL) {
            Q = next(Q);
        }
    }

    if (IDorder == infoOrder(firstOrder(X)).orderid) {
        P = deleteFirstOrder(L, X);
    } else if (IDorder == infoOrder(Q).orderid) {
        P = deleteLastOrder(L, X);
    } else {
        prec = firstOrder(X);
        while (IDorder != infoOrder(nextOrder(prec)).orderid) {
            prec = next(prec);
        }
        P = deleteAfterOrder(L, X, prec);
    }
    return P;
}

adr_order findOrder(mll &L, adr_merch X, string IDorder) {
    adr_order P = NULL;
    if (firstOrder(X) == NULL) {
        cout << "Tidak Ada Orderan" << endl;
        return P;
    } else {
        P = firstOrder(X);
        while ((P != NULL) && (infoOrder(P).orderid != IDorder)) {
            P = nextOrder(P);
        }
        return P;
    }
}

// Insert Last
void insertOrder (mll &L, adr_merch X, adr_order Y){
    if (firstOrder(X) == NULL) {
        firstOrder(X) = Y;
    } else {
        adr_order P = firstOrder(X);
        while (nextOrder(P) != NULL) {
            P = nextOrder(P);
        }
        nextOrder(P) = Y;
    }
}

void insertDrivertoOrder (mll &L, adr_merch X, adr_order Y, adr_driver Z){
    if (firstOrder(X) == NULL) {
        cout << "Tidak Ada Orderan" << endl;
    } else {
        adr_order P = firstOrder(X);
        while ((P != Y) && (P != NULL)) {
            P = nextOrder(P);
        }
        driver(P) = Z;
    }
}

adr_merch findMerch(mll ListMerch, string merchant) {
    adr_merch P = NULL;
    if (firstMerchant(ListMerch) == NULL){
        cout << "Koasong bre" << endl;
        return P;
    } else {
        P = firstMerchant(ListMerch);
        while((P != NULL) && (infoMerchant(P).nama_merchant != merchant)){
            P = nextMerchant(P);
        }
        return P;
    }
}

adr_merch deleteFirstMerch(mll &ListMerch) {
    adr_merch P;

    if (firstMerchant(ListMerch) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (nextMerchant(firstMerchant(ListMerch))== NULL){
        P = firstMerchant(ListMerch);
        firstMerchant(ListMerch) = NULL;
        lastMerchant(ListMerch) = NULL;
    } else {
        P = firstMerchant(ListMerch);
        firstMerchant(ListMerch) = nextMerchant(firstMerchant(ListMerch));
        nextMerchant(P) = NULL;
    }
    return P;
}

adr_merch deleteLastMerch(mll &ListMerch) {
    adr_merch P;

    if (firstMerchant(ListMerch) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (nextMerchant(firstMerchant(ListMerch))== NULL){
        P = firstMerchant(ListMerch);
        firstMerchant(ListMerch) == NULL;
        lastMerchant(ListMerch) = NULL;
    } else {
        adr_merch Q = firstMerchant(ListMerch);
        P = lastMerchant(ListMerch);
        while (nextMerchant(Q) != P) {
            Q = nextMerchant(Q);
        }
        lastMerchant(ListMerch) = Q;
        nextMerchant(Q) = NULL;
    }
    return P;
}

adr_merch deleteAfterMerch(mll &ListMerch, adr_merch prev) {
    adr_merch P = NULL;

    if (firstMerchant(ListMerch) == NULL) {
        cout << "Tidak Ada Order" << endl;
    } else if (nextMerchant(firstMerchant(ListMerch))== NULL){
        P = firstMerchant(ListMerch);
        firstMerchant(ListMerch) == NULL;
        lastMerchant(ListMerch) == NULL;
    } else {
        P = nextMerchant(prev);
        nextMerchant(prev) = nextMerchant(P);
        nextMerchant(P) = NULL;
    }
    return P;
}

adr_merch deleteElmMerch(mll &ListMerch, string merchant) {
    adr_merch P;
    adr_merch Q;
    adr_merch prec;

    if (firstMerchant(ListMerch) != NULL) {
        Q = lastMerchant(ListMerch);
    }
    if (merchant == infoMerchant(firstMerchant(ListMerch)).nama_merchant) {
        P = deleteFirstMerch(ListMerch);
    } else if (merchant == infoMerchant(Q).nama_merchant) {
        P = deleteLastMerch(ListMerch);
    } else {
        prec = firstMerchant(ListMerch);
        while (merchant != infoMerchant(nextMerchant(prec)).nama_merchant) {
            prec = nextMerchant(prec);
        }
        P = deleteAfterMerch(ListMerch, prec);
    }
    return P;
}


void ShowOrder(mll ListMerch, adr_merch X) {
    if (firstOrder(X) == NULL) {
        cout << "Merchant Name: " << infoMerchant(X).nama_merchant << endl;
        cout << "Tidak ada Orderan" << endl;
        cout << endl;
    } else {
        adr_order P = firstOrder(X);
        while (P != NULL) {
            cout << "Merchant Name: " << infoMerchant(X).nama_merchant << endl;
            cout << "Order ID: " << infoOrder(P).orderid << endl;
            cout << "Penerima: " << infoOrder(P).penerima << endl;
            cout << "Makanan yang diorder: ";
            for (int i = 0; i<nmax; i++) {
                cout << infoOrder(P).order_makanan[i] << ", ";
            }
            cout << endl;
            cout << "Total harga: " << infoOrder(P).total_harga << endl;
            if (driver(P) != NULL) {
                cout << "Driver: " << infoDriver(driver(P)).nama_driver << endl;
            } else {
                cout << "Belum ada Driver" << endl;
            }
            cout << endl;
            P = nextOrder(P);
        }
    }
}

void createListDriver (list_driver &LD) {
    firstDriver(LD) = NULL;
}

// Insert Last
void insertDriver (list_driver &LD, adr_driver Z) {
    if (firstDriver(LD) == NULL) {
        firstDriver(LD) = Z;
    } else {
        adr_driver P = firstDriver(LD);
        while (nextDriver(P) != NULL) {
            P = nextDriver(P);
        }
        nextDriver(P) = Z;
    }
}

// Delete First
// Kalo mau jadi delete driver sabi tapi mlz
void deleteDriver (mll &L, list_driver &LD, adr_driver P) {
    if (firstDriver(LD) == NULL) {
        cout << "Tidak Ada Driver" << endl;
    } else if (nextDriver(firstDriver(LD))== NULL){
        deleteDriverZfromAllOrder(L, firstDriver(LD));
        P = firstDriver(LD);
        firstDriver(LD) = NULL;
    } else {
        deleteDriverZfromAllOrder(L, firstDriver(LD));
        P = firstDriver(LD);
        firstDriver(LD) = nextDriver(firstDriver(LD));
        nextDriver(P) = NULL;
    }
}

void showDriverofOrderYMerchX (mll L) {
    adr_merch X;
    adr_order Y;

    string merch, orderid;
    adr_merch P = firstMerchant(L);
    while (P != NULL) {
        cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
        P = nextMerchant(P);
    }
    cout << "Masukkan Nama Merchant: ";
    getline(cin >> ws, merch);
    X = findMerch(L, merch);
    if (X == NULL){
        cout<<"Nama Merchant Tidak ada"<<endl;
        cout << "Masukkan Nama Merchant: ";
        getline(cin >> ws, merch);
        X = findMerch(L, merch);
    }
    cout<<endl;

    adr_order D = firstOrder(X);
    while (D != NULL) {
        cout << "Order ID: " << infoOrder(D).orderid << endl;
        cout << "Penerima: " << infoOrder(D).penerima << endl;
        D = nextOrder(D);
    }
    cout<<endl;
    cout << "Masukkan Order ID: ";
    cin >> orderid;
    Y = findOrder(L, X, orderid);
    while (Y == NULL){
        cout<<"Nomor Order Tidak ada"<<endl;
        cout << "Masukkan Order ID: ";
        cin >> orderid;
        Y = findOrder(L, X, orderid);
    }
    if (Y != NULL) {
        cout << "Driver untuk order " << infoOrder(Y).orderid << ": ";
        if (driver(Y) != NULL) {
            cout << infoDriver(driver(Y)).nama_driver << endl;
        } else {
            cout << "Belum Ada Driver" << endl;
            }
    }
}


void showAllDriver(list_driver LD) {
    adr_driver P;

    if (firstDriver(LD) == NULL) {
        cout << "List Driver Kosong" << endl;
    } else {
        P = firstDriver(LD);
        int i = 1;
        while (P != NULL) {
            cout << "Driver " << i << endl;
            cout << "Nama Driver: " << infoDriver(P).nama_driver << endl;
            cout << "Rating Driver: " << infoDriver(P).rating_driver << endl;
            P = nextDriver(P);
            i += 1;
            cout << endl;
        }
    }
}

adr_driver findDriver(list_driver LD, string namadriver) {
    adr_driver P = NULL;

    if (firstDriver(LD) == NULL) {
        cout << "List Driver Kosong" << endl;
    } else {
        P = firstDriver(LD);
        while ((P != NULL) && (infoDriver(P).nama_driver != namadriver)) {
            P = nextDriver(P);
        }
    }
    return P;
}

int selectMenu() {
    cout << "======= MENU ========" << endl;
    cout << "1. Show All Merchants" << endl;
    cout << "2. Show Merchants that has more than 2 order" << endl;
    cout << "3. Show All Drivers" << endl;
    cout << "4. Show Merchants X Orders" << endl;
    cout << "5. Show All Orders" << endl;
    cout << "6. Add N Merchants" << endl;
    cout << "7. Add N Drivers" << endl;
    cout << "8. Add N Orders to Merchant X" << endl;
    cout << "9. Delete Merchant named X" << endl;
    cout << "10. Delete Order of ID X" << endl;
    cout << "11. Delete First Driver" << endl;
    cout << "12. Show Driver of Order Y" << endl;
    cout << "13. Count Orders from All Merchant" << endl;
    cout << "14. Show Minimum/Maximum Order" << endl;
    cout << "15. Add Driver to Order Y" << endl;
    cout << "16. Change Relation" << endl;
    cout << "0. Exit" << endl;

    int input = 0;
    cout << "Masukan Pilihan Menu: ";
    cin >> input;

    return input;
}

int TotalOrder(mll ListMerch, adr_merch X){
    int totalOrder;
    totalOrder = 0;
    if (firstOrder(X) == NULL) {
        return totalOrder;
    } else {
        adr_order P = firstOrder(X);
        while (P != NULL) {
            totalOrder = totalOrder + 1;
            P = nextOrder(P);
        }
        return totalOrder;
    }
}

void addNDriver(list_driver &LD){
    string NamaDriver;
    int N;
    float ratingDriver;
    adr_driver Z;

    cout << "Berapa data Driver yang ingin dimasukan? "; cin>> N; cout<<endl;
    for(int i = 0; i < N; i++ ){
        cout << "Data ke-" << i+1 << endl;
        cout << "Nama Driver: "; getline(cin >> ws, NamaDriver);
        cout << "Rating Driver: "; cin >> ratingDriver;
        Z = alokasi_driver(NamaDriver, ratingDriver);
        insertDriver(LD, Z);
        cout << endl;
    }
}

void addNOrdertoMerchX(list_driver &LD, mll &L){
    int i, N, harga;
    string Merch, orderID, namaDriver, pengorder, menu[nmax];
    int pilihan = 0;
    adr_merch X;
    adr_order Y;
    adr_driver Z;

    cout <<"Berapa data Order yang ingin dimasukan? "; cin >> N; cout << endl;
    for(int i = 0; i < N; i++ ){
        adr_merch P = firstMerchant(L);
        while (P != NULL) {
            cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
            P = nextMerchant(P);
        }
        cout << "Masukkan Nama Merchant: "; getline(cin >> ws, Merch);
        X = findMerch(L, Merch);
        while (X == NULL){
            cout<<"Merchant tidak ditemukan"<<endl;
            cout << "Masukkan Nama Merchant: "; getline(cin >> ws, Merch);
            X = findMerch(L, Merch);
        }
        // INPUTS
        cout << "Data ke-" << i+1 << endl;
        cout << "Order ID: "; cin >> orderID;
        cout << "Pengorder: "; getline(cin >> ws, pengorder);
        cout << "Pilihan menu: " << endl;
        for (int i = 0; i < nmax; i++) {
            cout << i+1 << " " << infoMerchant(X).nama_makanan[i] << endl;
        }

        cout << "Menu yang dipesan " << endl;
        cout<<"Masukan Nomor menu :"<<endl;
        for (int i = 0; i < nmax; i++) {
            cout << i+1 << ".) ";
            cin >> pilihan;
            if ((pilihan > 0) && (pilihan < 4)) {
                menu[i] = infoMerchant(X).nama_makanan[pilihan-1];
                harga += infoMerchant(X).harga[pilihan-1];
            } else {
                cout << "Input tidak valid" << endl;
            }
        }
        Y = alokasi_order(orderID, pengorder, menu, harga);
        insertOrder(L, X, Y);

        adr_driver C = firstDriver(LD);
        while (C != NULL) {
            cout << "Nama Driver: " << infoDriver(C).nama_driver << endl;
            C = nextDriver(C);
        }
        cout << "Pilih Nama Driver: ";cin>>namaDriver;
        Z = findDriver(LD, namaDriver);
        while (Z == NULL){
            cout<<"Nama driver tidak ditemukan"<<endl;
            cout << "Pilih Nama Driver: ";cin>>namaDriver;
            Z = findDriver(LD, namaDriver);
        }
        insertDrivertoOrder(L,X,Y,Z);
        cout << endl;
    }
}

void addNMerchant(mll &L) {
    int i, N, harga[nmax];
    float rating;
    string namamerch, menu[nmax];
    adr_merch X;

    cout <<"Berapa data Order yang ingin dimasukan? "; cin >> N; cout << endl;
    for(int i = 0; i < N; i++ ){
        cout << "Data ke-" << i+1 << endl;
        cout << "Nama Merchant : "; getline(cin >> ws, namamerch);
        cout << "Rating: "; cin >> rating;
        cout << "Masukkan 3 Menu: " << endl;
        for (int i = 0; i < nmax; i++) {
            cout << "Menu ke-" << i+1 << ": ";
            getline(cin >> ws, menu[i]);
            cout << "Harga menu ke-" << i+1 << ": ";
            cin >> harga[i];
        }
        X = alokasi_merchant(namamerch, rating, menu, harga);
        insertMerchant(L, X);
        cout<<endl;
    }
}

void ShowBoomingBisnis(mll L) {
    adr_merch X;

    X = firstMerchant(L);
    while (X != NULL) {
        if (TotalOrder(L, X) > 2) {
            cout << infoMerchant(X).nama_merchant << endl;
        }
        X = nextMerchant(X);
    }
}

void showOrderofMerchantX(mll L) {
    string inputan;

    cout << "Masukkan Nama Merchant: ";
    getline(cin >> ws, inputan);
    adr_merch X = findMerch(L, inputan);
    while (X == NULL){
        cout << "Merchant Tidak Ditemukan" << endl;
        cout << "Masukkan Nama Merchant: ";
        getline(cin >> ws, inputan);
        X = findMerch(L, inputan);
    }
    ShowOrder(L, X);
}

void showAllOrder(mll L) {
    adr_merch X = firstMerchant(L);
    while (X != NULL) {
        ShowOrder(L, X);
        X = nextMerchant(X);
    }
}

void deleteMerchantX (mll &L) {
    string inputan;
    adr_merch P = firstMerchant(L);
        while (P != NULL) {
            cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
            P = nextMerchant(P);
        }

    cout << "Masukkan Nama Merchant yang Akan Dihapus: ";
    getline(cin >> ws, inputan);
    adr_merch X = findMerch(L, inputan);
    while(X == NULL){
        cout<<"Nama merchant Tidak ada"<<endl;
        cout << "Masukkan Nama Merchant yang Akan Dihapus: ";
        getline(cin >> ws, inputan);
        X = findMerch(L, inputan);
    }
    deleteElmMerch(L, inputan);
}

void deleteOrderIDX (mll &L) {
    string inputan;
    string merch;

    adr_merch P = firstMerchant(L);
    while (P != NULL) {
        cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
        P = nextMerchant(P);
    }
    cout << "Masukkan Nama Merchant: ";
    getline(cin >> ws, merch);
    adr_merch X = findMerch(L, merch);
    if (X != NULL) {
        adr_order P = firstOrder(X);
        while (P != NULL) {
            cout << "Order ID: " << infoOrder(P).orderid << endl;
            cout << "Penerima: " << infoOrder(P).penerima << endl;
            P = nextOrder(P);
        }
        cout << "Masukkan Order ID yang akan dihapus: ";
        cin >> inputan;
        deleteElmOrder(L, X, inputan);
    } else {
        cout << "Merchant tidak ditemukan" << endl;
    }
}

void deleteDriverZfromAllOrder (mll &L, adr_driver Z) {
    adr_merch X = firstMerchant(L);
    adr_order Y;

    while (X != NULL) {
        Y = firstOrder(X);
        while (Y != NULL) {
            if (driver(Y) == Z) {
                driver(Y) = NULL;
            }
            Y = nextOrder(Y);
        }
        X = nextMerchant(X);
    }
}

void countAllOrder(mll L) {
    adr_merch X = firstMerchant(L);

    while (X != NULL) {
        cout << "Nama Merchant: " << infoMerchant(X).nama_merchant << endl;
        cout << "Jumlah Order: " << TotalOrder(L, X) << endl;
        X = nextMerchant(X);
    }
}

void extremeOrder(mll L) {
    adr_merch X = firstMerchant(L);
    int minOrder = TotalOrder(L, X);
    int maxOrder = minOrder;
    string namaMerchantMin = infoMerchant(X).nama_merchant;
    string namaMerchantMax = namaMerchantMin;
    int temp = 0;
    X = nextMerchant(X);

    while (X != NULL) {
        temp = TotalOrder(L, X);
        if (temp > maxOrder) {
            maxOrder = temp;
            namaMerchantMax = infoMerchant(X).nama_merchant;
        }
        if (temp < minOrder) {
            minOrder = temp;
            namaMerchantMin = infoMerchant(X).nama_merchant;
        }
        X = nextMerchant(X);
    }
    cout << "Maximum Order" << endl;
    cout << "-------------" << endl;
    cout << "Nama Merchant: " << namaMerchantMax << endl;
    cout << "Jumlah Order: " << maxOrder << endl;

    cout << endl;
    cout << "Minimum Order" << endl;
    cout << "-------------" << endl;
    cout << "Nama Merchant: " << namaMerchantMin << endl;
    cout << "Jumlah Order: " << minOrder << endl;

}

void addDrivertoOrderY (mll &L, list_driver LD) {
    adr_merch X;
    adr_order Y;
    adr_driver Z;

    string merch, orderid, driver;
    adr_merch P = firstMerchant(L);
        while (P != NULL) {
            cout << "Nama Merchant: " << infoMerchant(P).nama_merchant << endl;
            P = nextMerchant(P);
        }
    cout<<endl;
    cout << "Masukkan Nama Merchant: ";
    getline(cin >> ws, merch);
    X = findMerch(L, merch);
    cout<<endl;
    if (X != NULL) {
        adr_order P = firstOrder(X);
        while (P != NULL) {
            cout << "Order ID: " << infoOrder(P).orderid << endl;
            cout << "Penerima: " << infoOrder(P).penerima << endl;
            P = nextOrder(P);
        }
        cout<<endl;
        cout << "Masukkan Order ID: ";
        cin >> orderid;
        Y = findOrder(L, X, orderid);
        if (Y != NULL) {
            cout << "Masukkan Nama Driver: ";
            getline(cin >> ws, driver);
            Z = findDriver(LD, driver);
            while (Z == NULL) {
                cout << "Driver tidak ditemukan, silahkan input kembali" << endl;
                cout << "Masukkan Nama Driver: ";
                getline(cin >> ws, driver);
                Z = findDriver(LD, driver);
            }
            insertDrivertoOrder(L, X, Y, Z);
        } else {
            cout << "Order tidak ditemukan" << endl;
        }
    } else {
        cout << "Merchant Tidak Ditemukan" << endl;
    }
}

void hapusRelasi (mll &L, adr_order &P) {
    adr_merch X;
    string merchant;
    adr_merch C = firstMerchant(L);
    while (C != NULL) {
        cout << "Nama Merchant: " << infoMerchant(C).nama_merchant << endl;
        C = nextMerchant(C);
    }
    cout<<endl;
    cout << "Masukkan Nama Merchant yang Ordernya mau dipindah: ";
    getline(cin >> ws, merchant);

    X = findMerch(L, merchant);
    while (X == NULL) {
        cout << "Nama Merchant tidak ditemukan, silahkan input kembali" << endl;
        cout << endl;
        cout << "Masukkan Nama Merchant yang Ordernya mau dipindah: ";
        getline(cin >> ws, merchant);
        X = findMerch(L, merchant);
    }
    P = firstOrder(X);
    firstOrder(X) = NULL;
}

void buatRelasi (mll &L) {
    adr_order P;
    adr_merch X;
    string merchant;
    hapusRelasi(L, P);

    cout << "Masukkan Nama Merchant tujuan: ";
    getline(cin >> ws, merchant);
    X = findMerch(L, merchant);
    while (X == NULL) {
        cout << "Nama Merchant tidak ditemukan, silahkan input kembali" << endl;
        cout << endl;
        cout << "Masukkan Nama Merchant yang Ordernya mau dipindah: ";
        getline(cin >> ws, merchant);
        X = findMerch(L, merchant);
    }

    insertOrder(L, X, P);
}
