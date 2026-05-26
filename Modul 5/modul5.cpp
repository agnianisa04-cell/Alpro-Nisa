#include <iostream>
using namespace std;

void inputTidakValid(){
    cin.clear();
    cin.ignore(1000, '\n');
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
    char nik[100];
    string nama;
    Tanggal_lahir tanggal;
    Tanggal_lahir tanggalMasuk;
    char jenisKelamin;
    string golDarah;
    string noTelpon;
    Alamat alamat;
    char bpjs;
    int alergi;
    string alergen;
    string reaksi;
};
Tanggal_lahir tanggalSekarang = {21, 5, 2026};

void menuUtama (Tanggal_lahir hariIni){
    cout << "======================================================" << endl;
    cout << "\tSISTEM MANAJEMEN RS GAZACARE PLUS" << endl;
    cout << "======================================================" << endl;
    cout << "\t\t\t\tTanggal: " << hariIni.tanggal << "/" << hariIni.bulan << "/" << hariIni.tahun << endl;
    cout << "[1] Daftarkan Pasien Baru" << endl;
    cout << "[2] Lihat Semua Pasien" << endl;
    cout << "[3] Cari Pasien" << endl;
    cout << "[4] Pulangkan Pasien" << endl;
    cout << "[0] Kembali" << endl;
    cout << "======================================================" << endl;
    cout << "Pilihan: ";
}

bool cekNikSama(char nik1[], char nik2[]){
    int i = 0;
    while (nik1[i] != '\0' || nik2[i] != '\0'){
        if (nik1[i] != nik2[i]){
            return false;
        }
        i++;
    }
    return true;
}

bool daftarPasien(Data pasien[], int jumlahPasien, Tanggal_lahir hariIni){
    string alergen, reaksi;
    int urutanPasien[100];
    int urutan = 0;
    int counterPanjang;
    cout << "\n=======================================" << endl;
    cout << "\tPENDAFTARAN PASIEN BARU" << endl;
    cout << "=======================================" << endl;
    cin.ignore(1000, '\n');
    do{
        counterPanjang = 0;
        cout << "NIK                  : "; cin.getline(pasien[jumlahPasien].nik, 100);
        while (pasien[jumlahPasien].nik[counterPanjang] != '\0'){
            counterPanjang++;
        }
        if (counterPanjang != 16){
            cout << "Panjang nik wajib 16 karakter...." << endl;
        }
    } while (counterPanjang != 16);

    for (int i = 0; i < jumlahPasien; i++){
        if (cekNikSama(pasien[i].nik, pasien[jumlahPasien].nik)){
            cout << "\nPasien sudah terdaftar sebagai " << pasien[i].nama << endl;
            return false;
        }
    }
    
    cout << "Nama                 : "; getline(cin, pasien[jumlahPasien].nama);
    cout << "Tgl Lahir            : " << endl;
    while (true){
        cout << "    Tanggal          : "; cin >> pasien[jumlahPasien].tanggal.tanggal;
        if (cin.fail()){
            inputTidakValid();
            cout << "input tidak valid" << endl;
        }else if (pasien[jumlahPasien].tanggal.tanggal == 0 || pasien[jumlahPasien].tanggal.tanggal >= 31){
            cout << "input tidak valid" << endl;
        }else{
            break;
        }
    }
    while (true){
        cout << "    Bulan            : "; cin >> pasien[jumlahPasien].tanggal.bulan;
        if (cin.fail()){
            inputTidakValid();
            cout << "input tidak valid" << endl;
        }else if (pasien[jumlahPasien].tanggal.bulan == 0 || pasien[jumlahPasien].tanggal.bulan >= 13){
            cout << "input tidak valid" << endl;
        }else{
            break;
        }
    }
    while (true){
        cout << "    Tahun            : "; cin >> pasien[jumlahPasien].tanggal.tahun;
        if (cin.fail()){
            inputTidakValid();
            cout << "input tidak valid" << endl;
        }else if (pasien[jumlahPasien].tanggal.tahun == 0 || pasien[jumlahPasien].tanggal.tahun >= 2027){
            cout << "input tidak valid" << endl;
        }else{
            break;
        }
    }
    cout << "Jenis Kelamin (L/P)  : "; cin >> pasien[jumlahPasien].jenisKelamin;
    cout << "Gol. Darah           : "; cin >> pasien[jumlahPasien].golDarah;
    cout << "No. Telp             : "; cin >> pasien[jumlahPasien].noTelpon;
    cout << "Alamat               : " << endl;
    cout << "    Jalan            : "; 
    cin.ignore(1000, '\n');
    getline(cin, pasien[jumlahPasien].alamat.jalan);
    cout << "    Kelurahan        : "; getline(cin, pasien[jumlahPasien].alamat.kelurahan);
    cout << "    Kota             : "; getline(cin, pasien[jumlahPasien].alamat.kota);
    cout << "    Provinsi         : "; getline(cin, pasien[jumlahPasien].alamat.provinsi);
    while (true){
        cout << "    Kode Pos         : "; cin >> pasien[jumlahPasien].alamat.kodePos;
        if (cin.fail()){
            inputTidakValid();
            cout << "input tidak valid" << endl;
        }else{
            break;
        }
    }
    cout << "Peserta BPJS (y/n)   : "; cin >> pasien[jumlahPasien].bpjs;
    cout << "Jumlah alergi (0-5)  : "; cin >> pasien[jumlahPasien].alergi;
    for (int i = 1; i <= pasien[jumlahPasien].alergi; i++){
        if (pasien[jumlahPasien].alergi != 0){
            cout << "[Alergi " << i << "]" << endl;
            cout << "Alergen : "; cin >> pasien[jumlahPasien].alergen;
            cout << "Reaksi  : "; cin.ignore(1000, '\n'); getline(cin, pasien[jumlahPasien].reaksi);
        }else{
            break;
        }
    }
    cout << "Tanggal Masuk        : " << endl;
    cout << "    Tanggal          : ";
    cin >> pasien[jumlahPasien].tanggalMasuk.tanggal;

    cout << "    Bulan            : ";
    cin >> pasien[jumlahPasien].tanggalMasuk.bulan;

    cout << "    Tahun            : ";
    cin >> pasien[jumlahPasien].tanggalMasuk.tahun;
    return true;
}

void lihatPasien(Data pasien[], int jumlahPasien){
    cout << "\n=======================================" << endl;
    cout << "\tDAFTAR PASIEN" << endl;
    cout << "=======================================" << endl;
    if (jumlahPasien == 0){
        cout << "\nBelum ada pasien terdaftar..." << endl;
    }

    for(int i = 0; i < jumlahPasien; i++){
        cout << "\t\t\t\tTanggal Masuk  : " << pasien[i].tanggalMasuk.tanggal << "/" << pasien[i].tanggalMasuk.bulan << "/" << pasien[i].tanggalMasuk.tahun<< endl;
        cout << "\nID              : " << i + 1 << endl;
        cout << "NIK             : " << pasien[i].nik << endl;
        cout << "Nama            : " << pasien[i].nama << endl;
        cout << "Jenis Kelamin   : " << pasien[i].jenisKelamin << endl;
        cout << "Tgl lahir       : " << endl;
        cout << "     Tanggal    : " << pasien[i].tanggal.tanggal << endl;
        cout << "     Bulan      : " << pasien[i].tanggal.bulan << endl;
        cout << "     Tahun      : " << pasien[i].tanggal.tahun << endl;
        cout << "Gol. Darah      : " << pasien[i].golDarah << endl;
        cout << "No. Telp        : " << pasien[i].noTelpon << endl;
        cout << "BPJS            : " << pasien[i].bpjs << endl;
        cout << "Alamat          : " << endl;
        cout << "     Jalan      : " << pasien[i].alamat.jalan << endl;
        cout << "     Kelurahan  : " << pasien[i].alamat.kelurahan << endl;
        cout << "     Kota       : " << pasien[i].alamat.kota << endl;
        cout << "     Provinsi   : " << pasien[i].alamat.provinsi << endl;
        cout << "     Kode Pos   : " << pasien[i].alamat.kodePos << endl;
        if (pasien[i].alergi == 0){
            cout << "Alergi          : " << "Tidak ada" << endl;
        }else{
            cout << "Alergi          : " << endl;
            cout << pasien[i].alergen << " -> " << pasien[i].reaksi << endl;
        }
        cout << "-----------------------------------" << endl;
    }
}

void cariPasien(Data pasien[], int jumlahPasien){
    string cariNama;
    bool ditemukan = false;
    int identity[] = {1, 2, 3, 4, 5, 6};

    cout << "\n=======================================" << endl;
    cout << "\tCARI PASIEN" << endl;
    cout << "=======================================" << endl;
    cin.ignore(1000, '\n');
    cout << "Masukkan nama : ";
    getline(cin, cariNama);
    cout << "\n=======================================" << endl;
    cout << "\tDAFTAR PASIEN" << endl;
    cout << "=======================================" << endl;
    for(int i = 0; i < jumlahPasien; i++){
        if (pasien[i].nama == cariNama){
            cout << "\t\t\t\tTanggal Masuk  : " << pasien[i].tanggalMasuk.tanggal << "/" << pasien[i].tanggalMasuk.bulan << "/" << pasien[i].tanggalMasuk.tahun<< endl;
            ditemukan = true;
            cout << "\nID              : " << identity[i] << endl;
            cout << "NIK             : " << pasien[i].nik << endl;
            cout << "Nama            : " << pasien[i].nama << endl;
            cout << "Jenis Kelamin   : " << pasien[i].jenisKelamin << endl;
            cout << "Tgl lahir       : " << endl;
            cout << "     Tanggal    : " << pasien[i].tanggal.tanggal << endl;
            cout << "     Bulan      : " << pasien[i].tanggal.bulan << endl;
            cout << "     Tahun      : " << pasien[i].tanggal.tahun << endl;
            cout << "Gol. Darah      : " << pasien[i].golDarah << endl;
            cout << "No. Telp        : " << pasien[i].noTelpon << endl;
            cout << "BPJS            : " << pasien[i].bpjs << endl;
            cout << "Alamat          : " << endl;
            cout << "     Jalan      : " << pasien[i].alamat.jalan << endl;
            cout << "     Kelurahan  : " << pasien[i].alamat.kelurahan << endl;
            cout << "     Kota       : " << pasien[i].alamat.kota << endl;
            cout << "     Provinsi   : " << pasien[i].alamat.provinsi << endl;
            cout << "     Kode Pos   : " << pasien[i].alamat.kodePos << endl;

            if (pasien[i].alergi == 0){
                cout << "Alergi          : Tidak ada" << endl;
            }else{
                cout << "Alergi          : " << pasien[i].alergen << " -> " << pasien[i].reaksi << endl;
            }
            cout << "-----------------------------------" << endl;

        }
    }
    if (!ditemukan){
        cout << "\nPasien tidak ditemukan..." << endl;
    }
}
int hitungHari(Tanggal_lahir t){
    return t.tahun * 365 + t.bulan * 30 + t.tanggal;
}

void pulangkanPasien(Data pasien[], int &jumlahPasien){
    if (jumlahPasien == 0){
        cout << "\nTidak ada pasien terdaftar..." << endl;
        return;
    }
    int identity[] = {1, 2, 3, 4, 5, 6};
    int id;
    char konfirmasi;

    cout << "\n=======================================" << endl;
    cout << "\tPULANGKAN PASIEN" << endl;
    cout << "=======================================" << endl;

    for (int i = 0; i < jumlahPasien; i++){
        identity[i] = identity[i + 1];
        cout << "ID-" << identity[i] << " | " << pasien[i].nama << endl;
    }

    cout << "\nMasukkan ID pasien yang ingin dipulangkan: ";
    cin >> id;

    if (id <= 0 || id > jumlahPasien){
        cout << "\n[!] ID-" << id << " tidak ditemukan" << endl;
        return;
    }

    int index = id - 1;
    int tanggalKeluar = 21;
    int lamaRawat = hitungHari(tanggalSekarang) - hitungHari(pasien[index].tanggalMasuk);
    int tarif = 75000;

    cout << "\n=======================================" << endl;
    cout << "\tRINCIAN TAGIHAN" << endl;
    cout << "=======================================" << endl;

    cout << "Nama           : " << pasien[index].nama << endl;
    cout << "NIK            : " << pasien[index].nik << endl;
    cout << "BPJS           : " << pasien[index].bpjs << endl;
    
    cout << "Tanggal Masuk  : " << pasien[index].tanggalMasuk.tanggal << "/" << pasien[index].tanggalMasuk.bulan << "/" << pasien[index].tanggalMasuk.tahun<< endl;
    cout << "Tanggal Keluar : " << tanggalSekarang.tanggal << "/" << tanggalSekarang.bulan << "/" << tanggalSekarang.tahun << endl;
    if (lamaRawat <= 0){
    lamaRawat = 1;
    }
    int total = lamaRawat * tarif;
    cout << "Lama Rawat     : " << lamaRawat << " hari" << endl;
    cout << "Tarif per Hari : Rp 75000" << endl;
    
    if (pasien[index].bpjs == 'y' || pasien[index].bpjs == 'Y'){
        total = 0;
        cout << "Total Tagihan  : Rp " << total << " (Ditanggung BPJS)" << endl;
    }else{
        cout << "Total Tagihan  : Rp " << total << endl;
    }

    cout << "\nPulangkan pasien? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'n'|| konfirmasi == 'N'){
        cout << "\n[!] Pemulangan dibatalkan" << endl;
        return;
    }
    for (int i = index; i < jumlahPasien - 1; i++){
        pasien[i] = pasien[i + 1];
    }
    jumlahPasien--;
    cout << "\n[OK] Pasien ID-" << id << " berhasil dipulangkan" << endl;
    cout << "Sisa pasien : " << jumlahPasien << endl;
}

int main () {
    Data p[100];
    int pilih;
    int urutanPasien[100];
    int urutan = 0;

    while(true){
        menuUtama(tanggalSekarang);
        cin >> pilih;
        if (cin.fail()){
            inputTidakValid();
            cout << "[!] Input harus berupa angka..." << endl;
        }else if (pilih == 1){
            if (daftarPasien(p, urutan, tanggalSekarang)){
                urutanPasien[urutan] = urutan + 1;
                cout << "[OK] Pasien ID-" << urutanPasien[urutan] << " berhasil didaftarkan!" << endl;
                urutan++;
            }
        }else if (pilih == 2){
            lihatPasien(p, urutan);
        }else if (pilih == 3){
            cariPasien(p, urutan);
        }else if (pilih == 4){
            pulangkanPasien(p, urutan);
        }else if (pilih == 0){
            cout << "Terima Kasih! Sistem ditutup." << endl;
            break;
        }else {
            cout << "[!] Pilihan tidak valid." << endl;
        }
    }
    return 0;
}