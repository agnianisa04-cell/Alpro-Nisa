#include <iostream>
using namespace std;

int main () {
    int umur, angka;
    int perlindunganSihir = 3;
    char a, b, jawaban, strategi;
    int waktu, arah;
    char h;
    bool penanda;
    int sisaToleransiKesalahan = 2;
    int langkahDitempuh = 0;
    //bang gatau kenapa pas pake system("pause") sm system("cls") td gabisa di laptop saya:(. muncul kya simbol nada musik.
    //kalo cari di google sih harus pake library <cstdlib>. kan gaboleh yak pake selain <iostream>.
    //ga saya pakein jdnya:( karna dh mepet jg.
    cout << "== GOBLET OF FIRE: TURNAMEN TRIWIZARD ==" << endl;
    cout << "Masukkan umur : ";
    cin >> umur;

    if (umur >= 17){
        cout << "Piala Api menyala! Anda terpilih sebagai Triwizard Champions." << endl;
    }else {
        cout << "Piala Api menolak Anda! Umur terlalu kecil" << endl;
        return 0;
    } 
    cout <<"\n";

    cout << "--- TUGAS 1: NAGA HUNGARIAN HORNTAIL --- " << endl;
    while (perlindunganSihir > 0){
        cout << "Sisa perlindungan sihir : " << perlindunganSihir << endl;

        cout << "Pilih strategi (a : sembunyi, b : panggil sapu) : ";
        cin >> strategi;
        
        if (strategi == 'b'){
            cout << "Berhasil! Anda mengambil Telur Emas." << endl;
            break;
        }else if (strategi == 'a'){
            cout << "Naga menymburkan api! Anda terluka." << endl;
            --perlindunganSihir;

            if (perlindunganSihir == 0) {
                cout << ">> KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga." << endl;
                cout << ">> MENGULANG TUGAS 1 DARI AWAL..." << endl;
                perlindunganSihir = 3;
            }
        }else {
            cout << "Pilihan tidak valid! Ulangi pilihan." << endl;
        }
        

    }
    cout << "\n";

    cout << "-- TUGAS 2: DANAU HITAM --" << endl;
    do
    {
        for (int i = 10; i <= 50 ; i = i + 10){
            cout << "Menit " << i << "..." << "Ada Grindylow ! (l: lawan, h: hindari) : ";
            cin >> jawaban;
    
            if (jawaban == 'h') {
                cout << "Lolos dari Grindylow." << endl;
                penanda = true;
            }
            if (jawaban == 'l') {
                cout << "Oksigen Anda habis karena bertarung!" << endl;
                cout << ">> WAKTU/OKSIGEN HABIS! Putri duyung membawa anda ke permukaan." << endl;
                cout << ">> MENGULANG TUGAS 2 DARI AWAL..." << endl;
                penanda = false;
                break;
            }
        
        }
    } while (jawaban == 'l');

    if (penanda){
        cout << "Tepat 60 menit anda menyelamatkan sandera.\n" << endl;
    }


    cout << "--- TUGAS 3: LABIRIN ---" << endl;
    cout << "Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
    cout << "Langkah ditempuh         : " << langkahDitempuh << endl;

    while (true){
        cout << "Pilih arah (1: kiri, 2: kanan, 3: lurus) : ";
        cin >> arah;
        if (arah == 1){
            cout << "Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
            cout << "Langkah ditempuh         : " << langkahDitempuh << endl;
            cout << "Terkena Akar Berbisa!";
            --sisaToleransiKesalahan;
            cout << " Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
            if (sisaToleransiKesalahan == 0){
                cout << ">> KESEMPATAN HABIS! Labirin berubah bentuk dan menendang Anda ke pintu masuk." << endl;
                cout << ">> MENGULANG TUGAS 3 DARI AWAL..." << endl;
                sisaToleransiKesalahan = 2;
                langkahDitempuh = 0;
            }
        }else if (arah == 2){
            langkahDitempuh++;
            cout << "Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
            cout << "Langkah ditempuh         : " << langkahDitempuh << endl;
            cout << "Jalan aman, Anda semakin dalam" << endl;
            if (langkahDitempuh == 3){
            cout << "Anda melihat cahaya... Oh tunggu, apa itu..." << endl;
            break;
            }
        }else if (arah == 3){
            cout << "Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
            cout << "Langkah ditempuh         : " << langkahDitempuh << endl;
            cout << "Anda melihat cahaya... Oh tunggu, apa itu..." << endl;
            break;
        }else{
            cout << "Sisa toleransi kesalahan : " << sisaToleransiKesalahan << endl;
            cout << "Anda tidak berada di jalur pilihan! Ulangi pilihan!" << endl;
        }
    }
    cout << "\n";

    cout << "--- JALAN KELUAR ---" << endl;
    cout << "Anda melihat sesuatu yang bersinar di tengah arena..." << endl;
    cout << "Terdapat sesuatu yang terkurung di dalamnya, dan terdapat mesin yang meminta Anda untuk memasukkan sebuah angka...\n" << endl;

    cout << "Masukkan angka (minimal 5) : ";
    cin >> angka;
    cout << "Sebuah cahaya bersinar dan di tanganmu kini terdapat sebuah diamond besar!" << endl;
    for (int i = 1; i <= angka; i++) {
        for (int j = 1; j <= angka - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = angka - 1; i >= 1; i--) {
        for (int j = 1; j <= angka - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";

    cout << "*** SELAMAT! ANDA ADALAH PEMENANG TURNAMEN TRIWIZARD! ***" << endl;
    cout << "---------------------------------------------------------" << endl;

    return 0;

}
    
