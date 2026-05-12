#include <iostream>
using namespace std;

int main () {
    int key;
    char teks[100], deskripsi[100];
    char baru[25][4], baru2[25][4];
    int indexText = 0;
    int indexText2 = 0;
    char spasi;
    

    cout << "[TASK 1/3] DECODE SIGNAL - Comunication room" << endl;
    cout << ">> kirim sinyal terenkripsi dan deskripsi balasan dari Bumi \n" << endl;

    cout << "[ ENKRIPSI ]\n" << endl;

    do{
        cout << "Masukkan key  : ";
        cin >> key;
        if (key <= 0){
        cout << "[!] Key harus bilangan bulat positif. Coba lagi." << endl;
        }
    } while (key <= 0);
    cin.ignore(1000,'\n');

    do{
        cout << "Masukkan teks : ";
        cin.getline(teks, 100);
        if (teks[0] == '\0'){
            cout << "[!] Input tidak boleh kosong. Coba lagi." << endl;
        }
    } while (teks[0] == '\0');
   
    cout << "\n";

    int counterPanjang = 0;

    while(teks[counterPanjang] != '\0'){
        counterPanjang++;
    }
    int kolom = 4;
    int baris = counterPanjang / kolom;

    if (counterPanjang % 4 != 0){
        baris++;
    }
    cout << "Matriks enkripsi:\n" << endl;
    
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < 4; j++){
            if (indexText < counterPanjang){
                baru[i][j]=teks[indexText];
                indexText++;
            }else{
                baru[i][j] ='_';
            }
        }
    }
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < 4; j++){
            cout << baru[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<"\n";
    //BAGIAN ENKRIPSI!!!
    cout << "Enkripsi sebelum ditambah key : ";
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < baris; i++){
            cout << baru[i][j];
        }
    }
    cout << endl;

    cout << "Enkripsi sesudah ditambah key : ";
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < baris; i++){
            baru[i][j] = baru[i][j] + key;
            cout << baru[i][j];
        }
    }
    cout <<"\n" << endl;

//--------------------------------------------------------------Batas 
    cout << "[ DESKRIPSI ]\n" << endl;
    do{
        cout << "Masukkan teks terekripsi      : ";
        cin.getline(deskripsi, 100);
        if (deskripsi[0] == '\0'){
            cout << "[!] Input tidak boleh kosong. Coba lagi." << endl;
        }
    }while (deskripsi[0] == '\0');

    int counterPanjang2 = 0;

    while(deskripsi[counterPanjang2] != '\0'){
        counterPanjang2++;
    }
    
    cout << "Deskripsi setelah dikurangi key : ";
    for (int i = 0; i < counterPanjang2; i++){
        deskripsi[i]= deskripsi[i] - key;
        cout << deskripsi[i];
    }
    cout << "\n";

    int baris2 = counterPanjang2 / kolom;
    cout << "Matriks deskripsi : " << endl;

    for (int j = 0; j < 4; j++){
        for (int i = 0; i < baris2; i++){
            if (indexText2 < counterPanjang2){
                baru2[i][j]=deskripsi[indexText2];
                indexText2++;
            }else{
                baru2[i][j] ='_';
            }
        }
    }
    for (int i = 0; i < baris2; i++){
        for (int j = 0; j < 4; j++){
            cout << baru2[i][j] <<" ";
        }
        cout << endl;
    }

    cout << "Hasil deskrpsi final      : ";
    for (int i = 0; i < baris2; i++) {
        for (int j = 0; j < kolom; j++) {
            if (baru2[i][j] != '_') {
                cout << baru2[i][j];
            }
        }
    }
    cout << endl;

    cout << endl << ">> [TASK 1/3] COMPLETE - Signal chanel restored." << endl;
    cout << ">> Tekan ENTER untuk keluar.";
    cin.ignore();
    cin.get();

    cout << "[TASK 2/3] REPAIR TEXT CONSOLE - Captain's Bridge" << endl;
    cout << ">> Konsol teks mengalami intervensi kosmik" << endl;
    cout << ">> Verifikasi integritas data teks sebelum terlambat! \n" << endl;

    cout << "Vrifikasi Teks\n" << endl;
    char kata[200];
    char tanpaSpasi[200];
    char pilihan;

    do{
        for(int k = 1; k <= 3; k++){
            cout << "Masukkan kalimat ke-" << k << " :";
            cin.getline(kata, 200);

            int len = 0;
            for(int i = 0; kata[i] != '\0'; i++){
                if (kata[i] != ' '){
                    tanpaSpasi[len] = kata[i];
                    len++;
                }
            }
            tanpaSpasi[len] = '\0';

            cout << "------------------------------------------" << endl;
            cout << "Hasil untuk Kalimat ke-" << k << ":" << endl;

            cout << "Jumlah Huruf       : " << len << endl;

            cout << "1. Asli            : ";
            for (int i = 0; i < len; i++) {
                cout << tanpaSpasi[i];
                if (i == len - 1){
                    cout << "";
                }else{
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "2. Inverse         : ";
            for (int i = len - 1; i >= 0; i--) {
                cout << tanpaSpasi[i];
                if (i == 0){
                    cout << "";
                }else{
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "3. Swap Awal-Akhir : ";
            if (len > 0) {
                for (int i = 0; i < len; i++) {
                    if (i == 0 && len > 1) {
                        cout << tanpaSpasi[len - 1];
                    }else if (i == len - 1 && len > 1) {
                        cout << tanpaSpasi[0];
                    } else {
                        cout << tanpaSpasi[i];
                    } 
                }
            }
            cout << endl;

            bool isPalindrome = true;
            for (int i = 0; i < len / 2; i++) {
                char charDepan = tanpaSpasi[i];
                char charBelakang = tanpaSpasi[len - 1 - i];

                if (charDepan >= 'A' && charDepan <= 'Z'){
                    charDepan += 32;
                }
                if (charBelakang >= 'A' && charBelakang <= 'Z'){
                    charBelakang += 32;
                } 
                if (charDepan != charBelakang) {
                    isPalindrome = false;
                    break;
                }
            }
            cout << "4. Palindrome?     : ";
            if (isPalindrome && len > 0){
                cout << "YES" << endl;
            }else {
                cout << "NO" << endl;
            }
            cout << endl;
        }
        while (true) {
            cout << "==========================================" << endl;
            cout << "Verifikasi Teks Lain? (y/n): ";
            cin >> pilihan;
            cin.ignore(1000, '\n'); 

            if (pilihan == 'y' || pilihan == 'Y' || pilihan == 'n' || pilihan == 'N') {
                break;
            } else {
                cout << "[!] Input tidak valid. Masukkan y atau n." << endl;
            }
        }
    } while (pilihan == 'y' || pilihan == 'Y');
    cout << endl << ">> [TASK 2/3] COMPLETE - Text console back online." << endl;
    cout << ">> Tekan ENTER untuk keluar.";
    cout << "\n";
    cin.ignore();
    cin.get();

    cout << "[TASK 3/3] ALIGN NAVIGATION MATRIX - Engine Core" << endl;
    cout << ">> Sistem navigasi mati total akibat sabotase." << endl;
    cout << ">> Rekonstruksi matriks koordinat sekarang!\n" << endl << endl;
    cout << "[ MATRIX NAVIGATION ]\n" << endl;
    int n;

    while (true) {
        cout << "Masukkan ukuran Navigation Matrix (min 3, max 5): ";
        cin >> n;

        if (n >= 3 && n <= 5) {
            break;
        } else {
            cout << "[!] Input tidak valid. Masukkan ukuran antara 3 sampai 5." << endl;
        }
    }

    int ganjil[5][5], genap[5][5], fusion[5][5], transpose[5][5];
    int nilaiGanjil = 1, nilaiGenap = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ganjil[i][j] = nilaiGanjil;
            nilaiGanjil += 2;
            genap[i][j] = nilaiGenap;
            nilaiGenap += 2;
        }
    }

    cout << "-------------------------------------------" << endl;
    cout << "Odd Coordinate Matrix (Ganjil):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ganjil[i][j] < 10) {
                cout << "0";
            } 
            cout << ganjil[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nEven Coordinate Matrix (Genap):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (genap[i][j] < 10) {
                cout << "0";

            }
            cout << genap[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << "Matriks koordinat telah dipulihkan" << endl;
    cout << "Lakukanlah proses-proses berikut ini untuk membuat matriks koordinat lebih akurat!" << endl;
    cout << "1. Coordinate Matrix Integration (Fusion)" << endl;
    cout << "2. Matrix Transpose" << endl;
    cout << "3. Snake Traverse" << endl << endl;
    
    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore();
    cin.get();

    cout << "\nCOORDINATE MATRIX INTEGRATION:" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fusion[i][j] = ganjil[i][j] + genap[i][j];
            if (fusion[i][j] < 10) {
                cout << "0";

            } 
            cout << fusion[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMATRIX TRANSPOSE:" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = fusion[j][i]; // baris jadi kolom
            if (transpose[i][j] < 10) {
                cout << "0";
            } 
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSNAKE TRAVERSE:" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // baris genap dari kiri ke kanan
            for (int j = 0; j < n; j++) {
                if (transpose[i][j] < 10) {
                    cout << "0";

                } 
                cout << transpose[i][j] << " ";
            }
        } else {
            // baris ganjil dari kanan ke kiri
            for (int j = n - 1; j >= 0; j--) {
                if (transpose[i][j] < 10) {
                    cout << "0";
                } 
                cout << transpose[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "\n>> [TASK 3/3] COMPLETE - Navigation matrix aligned." << endl;
    cout << "==========================================================" << endl;
    cout << "   ALL TASKS COMPLETE - SHIP SYSTEMS RESTORED" << endl;
    cout << "==========================================================" << endl;

    return 0;
}