#include<iostream>
#include <string>
#include <ctime>
#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_GREEN "\033[1;32m"
using namespace std;

void tampilHeader(string username){
    cout << COLOR_CYAN << "GITSIM" << COLOR_RESET << " - Git simulator" << endl;
    cout << "Author : " << username << endl;
    cout << "----------------------------------------" << endl;
}

int main(int argc, char** argv){
    if(argc != 2){
        cout << "Penggunaan: ./gitsim <username>" << endl;
        return 1;
    }
    //cara akses = gitsim.exe agnianisa
    string username = argv[1];
    if(username != "agnianisa"){
        cout << "Akses ditolak!" << endl;
        return 1;
    }

    cout << COLOR_CYAN << "GITSIM " << COLOR_RESET << "- Lightweight Git Simulator" << endl;
    cout << "\nAuthor : " << username << endl;
    cout << "----------------------------------------" << endl;
    cout << "git init" << endl;
    cout << "----------------------------------------" << endl;
    string repoName;

    cout << "Repository name: ";
    getline(cin, repoName);

    if(repoName == ""){
        repoName = "cpp_alpro";
    }
    cout << COLOR_GREEN << "[OK] " << COLOR_RESET << "Initialized empty repository: " << repoName << endl;
    cout << endl;
    cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << endl;

    cout << "\nPress Enter...";
    cin.get();


    return 0;

}