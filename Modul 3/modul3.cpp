#include <iostream>
using namespace std;

int main () {
    int key;
    char teks[100];
    int coba [50];
    //string txt;
    //getline(cin, txt);

    cout << "[TASK 1/3] - DECODE SIGNAL - Comunication room" << endl;
    cout << ">> kirim sinyal terenkripsi dan deskripsi balasan dari Bumi \n" << endl;

    cout << "[ ENKRIPSI ]\n" << endl;

    do{
        cout << "Masukkan key : ";
        cin >> key;
    } while (key <= 0);
    cin.ignore(1000,'\n');

    cout << "Masukkan teks : ";
    cin.getline(teks, 100);
    int counter = 0;

    while(teks[counter] != '\0'){
        counter++;
    }

    for (int i = 0; i <= counter; i++){
        for (int j = 0; j <= 4; j++){
            coba[i][j] = counter;
        }
    }
    for (int i = 0; i <= counter; i++){
        for (int j = 0; j <= 4; j++){
            cout << coba[i][j] << endl;
        }
    }

    
    

    return 0;
}