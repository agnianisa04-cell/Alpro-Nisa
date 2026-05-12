#include <iostream>
using namespace std;

void bebas(){
    cout << "|==============================|" << endl;
    cout << "|" << "                              |" << endl;
    cout << "[" << "\tMODULE 4 - FUNCTION    ]" << endl;
    cout << "|" << "                              |" << endl;
    cout << "|==============================|" << endl;
    cout << "1. TIVAIZ Store" << endl;
    cout << "2. Kalkulator TIVAIZ" << endl;
    cout << "0. Keluar" << endl;
    cout << "==============================" << endl;
}

void store(){
    cout << "#==============================#" << endl;
    cout << "|" << "\tTIVAIZ STOTE" << "           |" << endl; 
    cout << "#==============================#" << endl;
    cout << "1. Input Barang" << endl;
    cout << "2. Hapus Barang" << endl;
    cout << "3. Edit Barang" << endl;
    cout << "4. Lihat Barang" << endl;
    cout << "0. Kembali" << endl;
}

void kalkulator(){
    cout << "+==============================-" << endl;
    cout << "|" << "\tTIVAIZ STOTE" << "           |" << endl; 
    cout << "x==============================/" << endl;
    cout << "1. Operasi Dasar (+, -, *, /)" << endl;
    cout << "2. Faktorial" << endl;
    cout << "3. Kembali" << endl;
}

int main () {
    int menu;
    string kalimat;
    bebas();

    do{
        cout << "Pilih menu: ";
        cin >> menu;
        cout << "\n";

        if(cin.fail()){
            cout << "[Gagal] Input harus berupa angka;" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        if (menu != 1 || menu != 2 || menu != 0 ){
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 1" << endl;
        }else {
            if (menu == 1){
                store();
            }else if(menu == 2){
                kalkulator();
            }
        }

        
    } while (menu != 1 || menu != 2 || menu != 0 );
    

    return 0;
}