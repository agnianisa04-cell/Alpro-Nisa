#include <iostream>
using namespace std;

void menuUtama (){
    cout << "======================================================" << endl;
    cout << "\tSISTEM MANAJEMEN RS GAZACARE PLUS" << endl;
    cout << "======================================================" << endl;
    cout << "\n";
    cout << "[1] Daftarikan Pasien Baru" << endl;
    cout << "[2] Lihat Semua Pasien" << endl;
    cout << "[3] Cari Pasien" << endl;
    cout << "[4] Pulangkan Pasien" << endl;
    cout << "======================================================" << endl;
    cout << "Pilihan: ";
}

struct Tanggal_lahir{
    int tanggal;
    int bulan;
    int tahun;
};

struct Alamat{
    string jalan;
    string kelurahan;
    string kota;
    string provinsi;
    int kodePos;
};

struct Data{
    string nik;
    string nama;
    Tanggal_lahir tanggal;
    char jenisKelamin;
    char golDarah;
    string noTelpon;
    Alamat alamat;
};

void daftarPasien(Data pasien){
    cout << "=======================================" << endl;
    cout << "\tPENDAFTARAN PASIEN BARU" << endl;
    cout << "=======================================" << endl;
    cout << "NIK (16 digit)       : "; 
    cin >> pasien.nik;
    cout << "Nama                 : "; 
    cin.ignore(1000, '\n');
    getline(cin, pasien.nama);
    cout << "Tgl Lahir            : " << endl;
    cout << "    Tanggal          : "; cin >> pasien.tanggal.tanggal;
    cout << "    Bulan            : "; cin >> pasien.tanggal.bulan;
    cout << "    Tahun            : "; cin >> pasien.tanggal.tahun;
    cout << "Jenis Kelamin (L/p)  : "; cin >> pasien.jenisKelamin;
    cout << "Gol. Darah           : "; cin >> pasien.golDarah;
    cout << "No. Telp             : "; cin >> pasien.noTelpon;
    cout << "Alamat               : " << endl;
    cout << "    Jalan            : "; 
    cin.ignore(1000, '\n');
    getline(cin, pasien.alamat.jalan);
    cout << "    Kelurahan        : "; cin.ignore(1000, '\n'); getline(cin, pasien.alamat.kelurahan);
    cout << "    Kota             : "; cin.ignore(1000, '\n'); getline(cin, pasien.alamat.kota);
    cout << "    Provinsi         : "; cin.ignore(1000, '\n'); getline(cin, pasien.alamat.provinsi);
    cout << "    Kode Pos         : "; cin >> pasien.alamat.kodePos;
}

int main () {
    Data p;
    int pilih;

    while(true){
        menuUtama();
        cin >> pilih;
        if (pilih == 1){
            daftarPasien(p);
        }
        break;
    }


    return 0;
}