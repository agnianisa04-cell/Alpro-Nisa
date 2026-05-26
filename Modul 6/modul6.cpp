#include <iostream>
using namespace std;

void banner(){
    cout << "============================================================" << endl;
    cout << "\tCyroN Divine Interface, Neural Management Terminal" << endl;
    cout << "============================================================" << endl;
}

void menu(){
    cout << "\t\tCYRON TERMINAL: DIVINE SUPPRESSION" << endl;
    cout << "�[1;35mXelisa: Exquisite... the synchronization is perfect. �[0m" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "1. View Neural Map (Status)" << endl;
    cout << "2. Inject Neural Thread (Add)" << endl;
    cout << "3. Purge Corrupted Link (Delete)" << endl;
    cout << "4. Expand Willpower (Resize)" << endl;
    cout << "0. Surrender (Exit)" << endl;
    cout << "------------------------------------------------------------" << endl;

}

int main (int argc, char** argv) {
    string nama = argv[1];
    int angka;
    menu();
    cin >> angka;

    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Masukkan input berupa angka!" << endl;
    }else if (angka == 1){
        //View Neural Map (Status)
    }else if (angka == 2){
        //Inject Neural Thread (Add)
    }else if(angka == 3){
        //Purge Corrupted Link (Delete)
    }else if(angka == 4){
        //Expand Willpower (Resize)
    }else if(angka == 0){
        //kembali
    }


    return 0;
}