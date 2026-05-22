#include<iostream>
using namespace std;


void clearScreen() {
    cout << "\033[2J\033[H";
}

void banner(){
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|      _    _                         _   ____            _             |" << endl;
    cout << "|     / \\  | |__  _   _ ___ ___  __ _| | |  _ \\ ___  __ _| |_ __ ___    |" << endl;
    cout << "|    / _ \\ | '_ \\| | | / __/ __|/ _` | | | |_) / _ \\/ _` | | '_ ` _ \\   |" << endl;
    cout << "|   / ___ \\| |_) | |_| \\__ \\__ \\ (_| | | |  _ <  __/ (_| | | | | | | |  |" << endl;
    cout << "|  /_/   \\_\\_.__/ \\__, |___/___/\\__,_|_| |_| \\_\\___|\\__,_|_|_| |_| |_|  |" << endl;
    cout << "|                 |___/                                                 |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
}

void pressEnter() {
    cout << "Press ENTER to continue...";
    cin.ignore();
    cin.get();
}

void sevenDeadlySins(){
    int stage;
    cout << "+=======================================================================+" << endl;
    cout << "|\t\t THE 7 DEADLY SINS ARE WAITING FOR YOU                  |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|\t\t 1. Pride                                               |" << endl;
    cout << "|\t\t 2. Greed                                               |" << endl;
    cout << "|\t\t 3. Wrath                                               |" << endl;
    cout << "|\t\t 4. Sloth                                               |" << endl;
    cout << "|\t\t 5. Gluttony                                            |" << endl;
    cout << "|\t\t 6. Envy                                                |" << endl;
    cout << "|\t\t 7. Lust                                                |" << endl;
    cout << "|\t\t 8. Exit                                                |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|\t\t The deeper you go, the stronger they are               |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "[Choose your desired stage]: " << endl;
}

void pride(){
    int path;
    cout << "+=======================================================================+" << endl;
    cout << "| [???]     : Fufufu, human. Are you strong enough to fight me?" << endl;
    cout << "| [???]     : I am Pride, and you dare to challenge me?" << endl;
    cout << "| [Pride]   : But first, prove your worth." << endl;
    cout << "+=======================================================================+" << endl;
    cout << "| 1. Arrogant Soldier" << endl;
    cout << "| 2. Noble Knight" << endl;
    cout << "| 3. Fallen Champion" << endl;
    cout << "| 4. King of Pride (Boss)" << endl;
    cout << "| 5. retreat" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "[which path will you take]: ";
    cin >> path;

}





int main(){
    banner();
    cout << "+=======================================================================+" << endl;
    cout << "|\t\t Welcome to Abyssal Realm, adventurer.                  |" << endl;
    cout << "|\t\t The seven deadly sins await your challenge.            |" << endl;
    cout << "+=======================================================================+" << endl;
    string nama;
    cin.ignore(1000, '\n');
    cout << "[Enter your name]: ";
    getline(cin, nama);
    pressEnter();

    sevenDeadlySins();
    //yeaa whatever T-T 
}