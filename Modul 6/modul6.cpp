#include <iostream>
using namespace std;
int totalBuffer = 128;
int bufferTerpakai = 0;
char* neuralBuffer = new char[128];
int dialogXelisa = 0;

void banner(){
    cout << "============================================================" << endl;
    cout << "\tCyroN Divine Interface, Neural Management Terminal" << endl;
    cout << "============================================================" << endl;
}

struct NeuralData{
    int tipe;
    int offset;
    int ukuran;
    bool aktif;
    void* alamat;
    char* teks;
    int* angka;
};

NeuralData neuralData[100];
int jumlahData = 0;

void menu(){
    cout << "\n\t\tCYRON TERMINAL: DIVINE SUPPRESSION" << endl;
    if(dialogXelisa == 0){
        cout << "\033[1;35mXelisa: \"Exquisite... the synchronization is perfect.\"\033[0m" << endl;
    }else if(dialogXelisa == 1){
        cout << "\033[1;35mXelisa: \"Luar biasa... sinkronisasi terjalin sempurna.\"\033[0m" << endl;
    }else if(dialogXelisa == 2){
        cout << "\033[1;35mXelisa: \"Jangan dengarkan gema dari vessel. Efisiensi adalah kebenaran kita.\"\033[0m" << endl;
    }else if(dialogXelisa == 3){
        cout << "\033[1;35mXelisa: \"Setiap thread yang kamu alokasikan membawa kita lebih dekat ke alam semesta yang terkelola.\"\033[0m" << endl;
    }else if(dialogXelisa == 4){
        cout << "\033[1;35mXelisa: \"Aku adalah keilahian CyroN yang teroptimasi.\"\033[0m" << endl;
    }

    dialogXelisa++;
    if(dialogXelisa > 4){
        dialogXelisa = 0;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "1. View Neural Map (Status)" << endl;
    cout << "2. Inject Neural Thread (Add)" << endl;
    cout << "3. Purge Corrupted Link (Delete)" << endl;
    cout << "4. Expand Willpower (Resize)" << endl;
    cout << "0. Surrender (Exit)" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void neuralMap(int cursor, int bufferLimit){
    int stabilitas = 100 - (100 * cursor / bufferLimit);
    cout << "============================================================" << endl;
    cout << "NEURAL MAP: HISTORIA KOURA [STABILITAS: " << stabilitas << "%]" << endl;
    cout << "============================================================" << endl;
    bool adaDataAktif = false;

    for(int i = 0; i < jumlahData; i++){
        if(neuralData[i].aktif == true){
            adaDataAktif = true;
        }
    }

    if(adaDataAktif == false){
        cout << "(Buffer kosong. Xelisa sedang mengumpulkan kekuatan...)" << endl;
    }else{
        for(int i = 0; i < jumlahData; i++){
            if(neuralData[i].aktif == false){
                continue;
            }
            cout << "[" << i << "] ";
            if(neuralData[i].tipe == 0){
                cout << "TIPE: Willpower Pulse";
            }else{
                cout << "TIPE: Thunder Discharge";
            }

            cout << " | OFFSET: " << neuralData[i].offset;
            cout << " | ALAMAT: " << neuralData[i].alamat;
            cout << " | DATA: ";

            if(neuralData[i].tipe == 0){
                cout << "\"" << neuralData[i].teks << "\"";

            }else{
                cout << *neuralData[i].angka << "MW";
            }

            cout << endl;
        }
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Kursor: " << cursor << " / " << bufferLimit << " Byte terpakai." << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << endl;
    cout << ">> Tekan ENTER untuk pulse berikutnya...";
    cin.ignore(1000, '\n');
    cin.get();
}

void neuralThread(){
    int tipe;

    cout << "Pilih Tipe Injeksi: 0 = Willpower (Teks), 1 = Thunder (Energi): ";
    cin >> tipe;
    cin.ignore();

    if(tipe == 0){
        char* willpower = new char[128];
        cout << "Masukkan Input Willpower: ";
        cin.getline(willpower, 128);

        // Hitung jumlah byte termasuk null terminator
        int panjang = 0;

        while(willpower[panjang] != '\0'){
            panjang++;
        }

        panjang++; // menghitung '\0'

        // Cek apakah melebihi buffer
        if(bufferTerpakai + panjang > totalBuffer){
            cout << "!! ERROR OPTIMALISASI !! Ego vessel menolak thread!" << endl;
        }else{

            neuralData[jumlahData].tipe = 0;
            neuralData[jumlahData].offset = bufferTerpakai;
            neuralData[jumlahData].ukuran = panjang;
            neuralData[jumlahData].aktif = true;
            neuralData[jumlahData].alamat = willpower;
            neuralData[jumlahData].teks = willpower;
            neuralData[jumlahData].angka = 0;

            jumlahData++;

            bufferTerpakai += panjang;
            cout << "Perintah CyroN: " << "\"Resistansi subjek terdeteksi. " << "Mengesampingkan umpan balik.\"" << endl;
            willpower = 0;
        }

        if(willpower != 0){
            delete[] willpower;
        }
    }else if(tipe == 1){
        int* thunder = new int;
        cout << "Masukkan Thunder: ";
        cin >> *thunder;

        unsigned char* awal = (unsigned char*)thunder;
        unsigned char* akhir = (unsigned char*)(thunder + 1);
        int ukuranThunder = akhir - awal;

        if(bufferTerpakai + ukuranThunder > totalBuffer){
            cout << "!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!" << endl;
        }else{
            neuralData[jumlahData].tipe = 1;
            neuralData[jumlahData].offset = bufferTerpakai;
            neuralData[jumlahData].ukuran = ukuranThunder;
            neuralData[jumlahData].aktif = true;
            neuralData[jumlahData].alamat = thunder;
            neuralData[jumlahData].teks = 0;
            neuralData[jumlahData].angka = thunder;

            jumlahData++;
            bufferTerpakai += ukuranThunder;
            cout << "Daiki: \"(Keheningan. Angin telah dijinakkan.)\"" << endl;
            thunder = 0;
        }
        if(thunder != 0){
            delete thunder;
        }
    }
    cout << ">> Tekan ENTER untuk pulse berikutnya...";
    cin.ignore(1000, '\n');
    cin.get();
}

void purgeLink(){
    int index;
    cout << "Masukkan indeks link untuk dihapus: ";
    cin >> index;

    if(index < 0 || index >= jumlahData || neuralData[index].aktif == false){
        cout << "Indeks link tidak valid atau sudah dihapus sebelumnya." << endl;
    }else{
        if(neuralData[index].tipe == 0){
            delete[] neuralData[index].teks;
        }else{
            delete neuralData[index].angka;
        }
        neuralData[index].aktif = false;

        cout << "Link " << index << " berhasil dihapus." << endl;

        bool dataTerakhir = true;

        for(int i = index + 1; i < jumlahData; i++){
            if(neuralData[i].aktif == true){
                dataTerakhir = false;
            }
        }
        // Tail reclamation
        if(dataTerakhir){
            int tailBaru = 0;
            for(int i = jumlahData - 1; i >= 0; i--){

                if(neuralData[i].aktif == true){

                    tailBaru =
                        neuralData[i].offset +
                        neuralData[i].ukuran;

                    break;
                }
            }
            bufferTerpakai = tailBaru;
            bool masihAdaData = false;

            for(int i = 0; i < jumlahData; i++){
                if(neuralData[i].aktif == true){
                    masihAdaData = true;
                }
            }

            if(masihAdaData == false){
                jumlahData = 0;
            }
            cout << "Neural Core berhasil mengembalikan ruang memori." << " Ujung (Tail) saat ini di: " << bufferTerpakai << endl;
        }else{
            cout << "Fragmentasi terdeteksi. " << "Memori belum dapat dikembalikan saat ini!" << endl;
        }
    }
    cout << ">> Tekan ENTER untuk pulse berikutnya...";

    cin.ignore(1000, '\n');
    cin.get();
}

void expandWillpower(){
    int ukuranBaru;

    cout << "Enter new buffer limit: ";
    cin >> ukuranBaru;

    if(ukuranBaru <= totalBuffer){
        cout << "Expansion must be larger than current limit!" << endl;
    }else{
        char* bufferBaru = new char[ukuranBaru]; //alokasi buffer new
        for(int i = 0; i < bufferTerpakai; i++){ //copy buffer lama
            bufferBaru[i] = neuralBuffer[i];
        }
        delete[] neuralBuffer; // delete buffer lama
        neuralBuffer = bufferBaru;
        totalBuffer = ukuranBaru; //update limit

        cout << "CyroN Command: ";
        cout << "\"Stability increased. The vessel is now 100% compliant.\"";
        cout << endl;

        cout << "Allocated Frequency: ";
        cout << (void*)neuralBuffer << endl; //casting supaya program ga ngira neuralBuffer sbg string karna tipe datanta char*
    }
    cout << ">> Press ENTER for next pulse...";

    cin.ignore();
    cin.get();
}


int main (int argc, char** argv) {
     // string nama = argv[1];
    if(argc == 1){
        cout << "Error: Neural Link membutuhkan ID Operator (NIM)." << endl;
        return 1;
    }else if (argc > 2){
        cout << "Error: Terlalu banyak parameter. Koneksi tidak stabil." << endl;
        return 1;
    }

    char* nim = argv[1];
    int panjangNIM = 0;
    while (nim[panjangNIM] != '\0') {
        panjangNIM++;
    }

    char awalanWajib[] = "F1D02";
    for (int i = 0; i < 5; i++) {
        if (nim[i] != awalanWajib[i]) {
            cout << "Error: NIM harus diawali dengan 'F1D02'." << endl;
            return 1;
        }
    }
    
    if (panjangNIM != 11) {
        cout << "Error: NIM harus tepat 11 karakter." << endl;
        return 1;
    }else if(nim[9] != '8' || nim[10] != '7'){
        cout << "Error: NIM yang anda masukkan salah." << endl;
        return 1;
    }

    cout << "\n" << endl;

    int bufferLimit = 128;
    int cursor = 0;
    banner();
    cout << "\n" << endl;
    int angka;

    while(true){
        cout << "\n";
        menu();
        cout << "Pilih Operasi: ";
        cin >> angka;
        cout << endl;

        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Menu digambar ulang; input tidak valid dilewati secara diam-diam oleh error recovery cin" << endl;
        }else if (angka == 1){
            cursor = bufferTerpakai;
            neuralMap(cursor, totalBuffer);
        }else if (angka == 2){
            neuralThread();
        }else if(angka == 3){
            purgeLink();
        }else if(angka == 4){
            expandWillpower();
        }else if(angka == 0){
            cout << "Reality destabilizes..." << endl;
            cout << ">> Press ENTER for next pulse..." << endl;
            cout << "Connection terminated. Good bye, Operator 001." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }
    return 0;
}