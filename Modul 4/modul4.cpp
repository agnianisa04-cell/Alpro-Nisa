#include <iostream>
using namespace std;

void bersihBersihError(){
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "[Gagal] Input harus berupa angka!" << endl;
}

void namaToko(){
    cout << "#=============================#" << endl;
    cout << "|         TIVAIZ STORE        |" << endl;
    cout << "#=============================#" << endl;
}
// MENU UTAMA 
void menuUtama() {
    cout << "\n|===================================|" << endl;
    cout << "|                                   |" << endl;
    cout << "|        MODULE 4 - FUNCTION        |" << endl;
    cout << "|                                   |" << endl;
    cout << "|===================================|" << endl;

    cout << "1. TIVAIZ Store" << endl;
    cout << "2. Kalkulator TIVAIZ" << endl;
    cout << "0. Keluar" << endl;

    cout << "=====================================" << endl;
}

// MENU STORE 
void menuStore() {

    cout << endl;

    cout << "#=============================#" << endl;
    cout << "|         TIVAIZ STORE        |" << endl;
    cout << "#=============================#" << endl;

    cout << "1. Input Barang" << endl;
    cout << "2. Hapus Barang" << endl;
    cout << "3. Edit Barang" << endl;
    cout << "4. Lihat Barang" << endl;
    cout << "0. Kembali" << endl;

    cout << "==============================" << endl;
}

// MENU KALKULATOR 
void menuKalkulator() {
    cout << endl;

    cout << "+=============================-" << endl;
    cout << "|         K4LKUL4T0R         |" << endl;
    cout << "x=============================/" << endl;

    cout << "1. Operasi Dasar (+, -, *, /)" << endl;
    cout << "2. Faktorial" << endl;
    cout << "0. Kembali" << endl;

    cout << "==============================" << endl;
}
// INPUT BARANG 
void inputBarang(string namaBarang[],int stokBarang[], int hargaBarang[], int &totalJenisBarang) {
    cin.ignore();

    cout << endl;
    namaToko();
    cout << "------------------------------" << endl;
    cout << "          INPUT BARANG        " << endl;
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;

    cout << "Nama Barang : ";
    getline(cin, namaBarang[totalJenisBarang]);
    cout << "------------------------------" << endl;
    // VALIDASI STOK
    while (true) {
        cout << "Stok (unit) : ";
        cin >> stokBarang[totalJenisBarang];
        cout << "------------------------------" << endl;
        if (cin.fail()) {
            bersihBersihError();
        }else {
            break;
        }
    }

    // VALIDASI HARGA
    while (true) {
        cout << "Harga (Rp)  : ";
        cin >> hargaBarang[totalJenisBarang];

        if (cin.fail()) {
            bersihBersihError();
        }else {
            break;
        }
    }

    totalJenisBarang++;

    cout << "\n[Berhasil] " << namaBarang[totalJenisBarang]<< " berhasil ditambahkan!";
    cout << "(Total barang : " << totalJenisBarang << ")" << endl;
}

// LIHAT BARANG 
void lihatBarang(string namaBarang[], int stokBarang[], int hargaBarang[],int totalJenisBarang) {

    cout << endl;

    namaToko();
    cout << "------------------------------" << endl;
    cout << "          LIHAT BARANG        " << endl;
    cout << "------------------------------" << endl;
    if (totalJenisBarang == 0) {
        cout << "Belum ada barang yang diinput." << endl;
    }else {
        for (int i = 0; i < totalJenisBarang; i++) {

            cout << "\nNomor Barang : " << i + 1 << endl;

            cout << "Nama Barang  : " << namaBarang[i] << endl;
            cout << "Stok         : " << stokBarang[i] << " unit" << endl;
            cout << "Harga        : Rp" << hargaBarang[i] << endl;
            cout << "Total Harga  : Rp" << stokBarang[i] * hargaBarang[i] << endl;
            cout << "------------------------------" << endl;
        }

        cout << "\nTotal Barang : " << totalJenisBarang <<" jenis"<< endl;
        cout << "------------------------------" << endl;
    }
}

// HAPUS BARANG 
void hapusBarang(string namaBarang[], int stokBarang[], int hargaBarang[], int &totalJenisBarang) {
    if (totalJenisBarang == 0) {
        cout << "\nBelum ada barang untuk dihapus." << endl;
        return;
    }

    int nomorHapus;

    cout << endl;
    namaToko();
    cout << "------------------------------" << endl;
    cout << "          HAPUS BARANG        " << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < totalJenisBarang; i++) {
        cout << "\nNomor Barang : " << i + 1 << endl;
        cout << "Nama Barang  : " << namaBarang[i] << endl;
        cout << "Stok         : " << stokBarang[i] << " unit" << endl;
        cout << "Harga        : Rp" << hargaBarang[i] << endl;
        cout << "Total Harga  : Rp" << stokBarang[i] * hargaBarang[i] << endl;
        cout << "------------------------------" << endl;

    }

    while (true) {
        cout << "\nPilih nomor barang yang dihapus (1-" << totalJenisBarang << ") : ";
        cin >> nomorHapus;
        cout << "------------------------------" << endl;

        if (cin.fail()) {
            bersihBersihError();
        }else if (nomorHapus < 1 || nomorHapus > totalJenisBarang) {
            cout << "[Gagal] Nomor " << nomorHapus << " tidak valid! Pilih antara 1 sampai " << totalJenisBarang << "." << endl;
        }else {
            break;
        }
    }

    for (int i = nomorHapus - 1; i < totalJenisBarang - 1; i++) {
        namaBarang[i] = namaBarang[i + 1];
        stokBarang[i] = stokBarang[i + 1];
        hargaBarang[i] = hargaBarang[i + 1];
    }
    totalJenisBarang--;

    cout << "\n[Berhasil] " << namaBarang[totalJenisBarang] << " berhasil dihapus!" << endl;

    cout << "Total jenis barang sekarang : " << totalJenisBarang << endl;
}

// EDIT BARANG 
void editBarang(string namaBarang[], int stokBarang[], int hargaBarang[], int totalJenisBarang) {
    if (totalJenisBarang == 0) {
        cout << "\nBelum ada barang untuk diedit." << endl;
        return;
    }

    int nomorEdit;

    cout << endl;
    namaToko();
    cout << "------------------------------" << endl;
    cout << "          EDIT BARANG        " << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < totalJenisBarang; i++) {

        cout << "\nNomor Barang : " << i + 1 << endl;
        cout << "Nama Barang  : " << namaBarang[i] << endl;
        cout << "Stok         : " << stokBarang[i] << " unit" << endl;
        cout << "Harga        : Rp" << hargaBarang[i] << endl;
        cout << "Total Harga  : Rp" << stokBarang[i] * hargaBarang[i] << endl;
        cout << "------------------------------" << endl;
    }

    while (true) {
        cout << "\nPilih nomor barang yang diedit (1-" << totalJenisBarang << ") : ";
        cin >> nomorEdit;
        cout << "------------------------------" << endl;

        if (cin.fail()) {
            bersihBersihError();
        }else if (nomorEdit < 1 || nomorEdit > totalJenisBarang) {
            cout << "[Gagal] Nomor " << nomorEdit << " tidak valid! Pilih antara 1 sampai " << totalJenisBarang << "." << endl;
        }else {
            break;
        }
    }

    int pilihanEdit;

    do {
        cout << "\nBarang : " << namaBarang[nomorEdit - 1] << endl;
        cout << "------------------------------" << endl;
        cout << "1. Edit Harga" << endl;
        cout << "2. Tambah Stok" << endl;
        cout << "3. Kurangi Stok" << endl;
        cout << "0. Kembali" << endl;
        cout << "------------------------------" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihanEdit;
        cout << "------------------------------" << endl;

        if (cin.fail()) {
            bersihBersihError();
            pilihanEdit = -1;
        }else if (pilihanEdit == 1) {
            // EDIT HARGA
            int hargaLama = hargaBarang[nomorEdit - 1];
            int hargaBaru;

            while (true) {
                cout << "Harga baru (Rp) : ";
                cin >> hargaBaru;
                cout << "------------------------------" << endl;
                if (cin.fail()) {
                    bersihBersihError();
                }else {
                    break;
                }
            }
            hargaBarang[nomorEdit - 1] = hargaBaru;
            cout << "[Berhasil] Harga " << namaBarang[nomorEdit - 1] << " : Rp" << hargaLama<< " -> Rp" << hargaBaru << endl;
        }else if (pilihanEdit == 2) {
            // TAMBAH STOK
            int tambah;

            while (true) {
                cout << "Jumlah tambah : ";
                cin >> tambah;
                cout << "------------------------------" << endl;

                if (cin.fail()) {
                    bersihBersihError();
                }else {
                    break;
                }
            }

            stokBarang[nomorEdit - 1] += tambah;
            cout << "[Berhasil] Stok " << namaBarang[nomorEdit - 1] << " : " << stokBarang[nomorEdit - 1] << endl;
        }else if (pilihanEdit == 3) {
            // KURANGI STOK
            int kurang;
            while (true) {
                cout << "Jumlah kurang : ";
                cin >> kurang;
                cout << "------------------------------" << endl;

                if (cin.fail()) {
                    bersihBersihError();
                }else {
                    break;
                }
            }
            stokBarang[nomorEdit - 1] -= kurang;

            cout << "[Berhasil] Stok " << namaBarang[nomorEdit - 1] << " : " << stokBarang[nomorEdit - 1] << endl;
        }else if (pilihanEdit != 0) {
            cout << "[Gagal] Menu tidak valid!" << endl;
        }
    } while (pilihanEdit != 0);
}

// FAKTORIAL 
long long faktorial(int angka) {
    if (angka == 0 || angka == 1) {
        return 1;
    }
    return angka * faktorial(angka - 1);
}

//  KALKULATOR 
void kalkulatorTivaiz() {
    int pilihKalkulator;
    do {
        menuKalkulator();
        cout << "Pilih menu : ";
        cin >> pilihKalkulator;

        if (cin.fail()) {
            bersihBersihError();
            pilihKalkulator = -1;
        }else if (pilihKalkulator < 0 || pilihKalkulator > 2) {
            // VALIDASI MENU
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2." << endl;
        }else if (pilihKalkulator == 1) {
            // OPERASI DASAR
            char operatorMatematika;
            double angka1, angka2;

            cout << "\nOperator (+, -, *, /) : ";
            cin >> operatorMatematika;
            cout << "------------------------------" << endl;

            // VALIDASI OPERATOR
            if (operatorMatematika != '+' && operatorMatematika != '-' && operatorMatematika != '*' && operatorMatematika != '/') {
                cout << "[Gagal] Operator tidak valid!" << endl;
            }else {
                while (true) {
                    cout << "Angka pertama : ";
                    cin >> angka1;
                    cout << "------------------------------" << endl;

                    if (cin.fail()) {
                        bersihBersihError();
                    }else {
                        break;
                    }
                }

                // INPUT ANGKA KEDUA
                while (true) {

                    cout << "Angka kedua : ";
                    cin >> angka2;
                    cout << "------------------------------" << endl;

                    if (cin.fail()) {
                        bersihBersihError();
                    }else {
                        break;
                    }
                }

                // PEMBAGIAN NOL
                if (operatorMatematika == '/' && angka2 == 0) {
                    cout << "[Gagal] Tidak bisa dibagi nol!" << endl;
                }else {
                    double hasil;
                    if (operatorMatematika == '+') {
                        hasil = angka1 + angka2;
                    }else if (operatorMatematika == '-') {
                        hasil = angka1 - angka2;
                    }else if (operatorMatematika == '*') {
                        hasil = angka1 * angka2;
                    }else {
                        hasil = angka1 / angka2;
                    }

                    cout << "\n " << angka1 << " " << operatorMatematika << " " << angka2 << " = " << hasil << endl;
                }
            }
        }else if (pilihKalkulator == 2) {
            // FAKTORIAL
            int angka;
            while (true) {
                cout << "\nN : ";
                cin >> angka;
                cout << "------------------------------" << endl;

                if (cin.fail()) {
                    bersihBersihError();
                }else {
                    break;
                }
            }

            if (angka < 0) {
                cout << "[Gagal] Faktorial tidak bisa untuk angka negatif!" << endl;
            }else {
                cout << angka << "!" << " = " << faktorial(angka) << endl;
            }
        }
    } while (pilihKalkulator != 0);

    cout << "\nKembali ke Menu Utama..." << endl;
}

int main() {
    int menu;
    int pilihStore;
    string namaBarang[100];
    int stokBarang[100];
    int hargaBarang[100];
    int totalJenisBarang = 0;

    // LOOP MENU UTAMA
    do {
        do {
            menuUtama();
            cout << "Pilih menu: ";
            cin >> menu;

            // VALIDASI INPUT
            if (cin.fail()) {
                bersihBersihError();
                menu = -1;
            }else if (menu < 0 || menu > 2) {
                // VALIDASI MENU
                cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2." << endl;
            }

        } while (menu < 0 || menu > 2);

        // STORE 
        if (menu == 1) {
            do {
                menuStore();
                cout << "Pilih menu: ";
                cin >> pilihStore;

                // VALIDASI INPUT
                if (cin.fail()) {
                    bersihBersihError();
                    pilihStore = -1;
                }else if (pilihStore < 0 || pilihStore > 4) {
                    // VALIDASI MENU
                    cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 4." << endl;
                }else if (pilihStore == 1) {
                    // INPUT BARANG
                    inputBarang(namaBarang, stokBarang, hargaBarang, totalJenisBarang);
                }else if (pilihStore == 2) {
                    // HAPUS BARANG
                    hapusBarang(namaBarang, stokBarang, hargaBarang, totalJenisBarang);
                }else if (pilihStore == 3) {
                    // EDIT BARANG
                    editBarang(namaBarang, stokBarang,hargaBarang,totalJenisBarang);
                }else if (pilihStore == 4) {
                    // LIHAT BARANG
                    lihatBarang(namaBarang, stokBarang, hargaBarang, totalJenisBarang);
                }
            } while (pilihStore != 0);
            cout << "\nKembali ke Menu Utama..." << endl;
        }else if (menu == 2) {
            // KALKULATOR 
            kalkulatorTivaiz();
        }
    } while (menu != 0);

    cout << "\nSampai jumpa! Terima kash telah menggunakan toko TRIVAIZ" << endl;

    return 0;
}