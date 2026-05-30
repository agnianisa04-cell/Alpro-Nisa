#include<iostream>
#include <string>
#include <ctime>
#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
using namespace std;

void tampilHeader(string username){
    cout << endl;
    cout << COLOR_CYAN << "GITSIM" << COLOR_RESET << " - Git simulator" << endl;
    cout << "Author : " << username << endl;

}

struct Branch{
    string nama;
    int jumlahCommit;

};

struct Repository{
    string nama;
    string branchAktif;
};

struct Commit{
    string hash;
    string pesan;
    string author;
    string waktu;
    string branch;
};

Commit daftarCommit[100];
int totalCommit = 0;
Branch daftarBranch[100];
int totalBranch = 1;

string buatHash(int nomorCommit){
    const string karakter = "0123456789abcdef";
    time_t sekarang = time(NULL);
    string hash = "";
    for(int i = 0; i < 7; i++){
        hash += karakter[(sekarang + nomorCommit + i * 13) % 16];
        sekarang /= 2;
    }

    return hash;
}

string ambilWaktu(){
    time_t sekarang = time(NULL);
    tm* waktuLokal = localtime(&sekarang);
    char buffer[100];

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M",waktuLokal);

    return buffer;
}

void tampilanUtama(string username, Repository* repo){
    int pilih;
    cout << COLOR_CYAN << "GITSIM" << COLOR_RESET << " - Git simulator" << endl;
    cout << "Author : " << username;
    cout << " | Repo: " << (*repo).nama << " | HEAD: " << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << " | [1/1]" << endl;
    cout << "----------------------------------------" << endl;
    cout << "[1] git commit" << endl;
    cout << "[2] git log" << endl;
    cout << "[3] git branch" << endl;
    cout << "[4] git checkout" << endl;
    cout << "[5] new repository" << endl;
    cout << "[6] switch repository" << endl;
    cout << "[0] exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << COLOR_CYAN << "> " << COLOR_RESET;
}

void gitCommit(string username, Repository* repo, Commit daftarCommit[], int &totalCommit, Branch daftarBranch[], int totalBranch){
    string pesan;
    char konfirmasi;

    cout << "----------------------------------------" << endl;
    cout << "git commit [" << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << "]" << endl;
    cout << "----------------------------------------" << endl;
    cin.ignore();

    cout << "Message : ";
    getline(cin, pesan);

    cout << endl;
    cout << "Push commit? (y/n): ";
    cin >> konfirmasi;

    if(konfirmasi == 'y' || konfirmasi == 'Y'){
        daftarCommit[totalCommit].pesan = pesan;
        daftarCommit[totalCommit].author = username;
        daftarCommit[totalCommit].hash = buatHash(totalCommit);
        daftarCommit[totalCommit].waktu = ambilWaktu();
        daftarCommit[totalCommit].branch = (*repo).branchAktif;
        for(int i = 0; i < totalBranch; i++){
            if(daftarBranch[i].nama == (*repo).branchAktif){
                daftarBranch[i].jumlahCommit++;
            }
        }
        cout << endl;

        cout << "[" << COLOR_GREEN << (*repo).branchAktif << " " << daftarCommit[totalCommit].hash << COLOR_RESET << "] " << daftarCommit[totalCommit].pesan << endl;
        cout << "----------------------------------------" << endl;
        cout << (*repo).branchAktif << " -> origin/" << (*repo).branchAktif << endl;
        cout << "$ git push origin " << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << endl;
        totalCommit++;
        cout << "----------------------------------------" << endl;
    }
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

void gitLog(Repository* repo, Commit daftarCommit[], int totalCommit){
    cout << "----------------------------------------" << endl;
    cout << "git log [" << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << "]" << endl;
    cout << "----------------------------------------" << endl;
    bool adaCommit = false;

    for(int i = totalCommit - 1; i >= 0; i--){
        if(daftarCommit[i].branch == (*repo).branchAktif){
            adaCommit = true;
            cout << "commit " << COLOR_YELLOW << daftarCommit[i].hash << COLOR_RESET << endl;
            cout << "Author : "<< daftarCommit[i].author << endl;
            cout << "Date   : " << daftarCommit[i].waktu << endl;
            cout << "         " << "docs: "<< daftarCommit[i].pesan << endl;
            cout << endl;
        }
    }
    if(!adaCommit){
        cout << "(No commits on this branch)" << endl;
    }
    cout << "\nPress Enter...";
    cin.get();
}

int hitungCommitBranch(string namaBranch, Commit daftarCommit[], int totalCommit){
    int jumlah = 0;
    for(int i = 0; i < totalCommit; i++){
        if(daftarCommit[i].branch == namaBranch){
            jumlah++;
        }
    }
    return jumlah;
}

void gitBranch(Repository* repo, Branch daftarBranch[], int &totalBranch, Commit daftarCommit[], int &totalCommit){
    cout << "----------------------------------------" << endl;
    cout << "git branch" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < totalBranch; i++){
        if(daftarBranch[i].nama == (*repo).branchAktif){
            cout << COLOR_GREEN << "* " << daftarBranch[i].nama << COLOR_RESET << " (" << hitungCommitBranch(daftarBranch[i].nama, daftarCommit, totalCommit)
                 << " commits)"
                 << endl;
        }else{
            cout << daftarBranch[i].nama << " (" << hitungCommitBranch(daftarBranch[i].nama, daftarCommit, totalCommit)
                 << " commits)"
                 << endl;
        }
    }
    cout << "----------------------------------------" << endl;
    string namaBaru;

    cout << "New branch name: ";
    cin.ignore();
    getline(cin, namaBaru);

    if(namaBaru == ""){
        cout << endl;
        cout << "[ERROR] Branch name cannot be empty!" << endl;

        cout << "\nPress Enter...";
        cin.get();
        return;
    }

    for(int i = 0; i < totalBranch; i++){
        if(daftarBranch[i].nama == namaBaru){
            cout << endl;
            cout << "[ERROR] Branch '" << namaBaru << "' already exists!" << endl;
            cout << "\nPress Enter...";
            cin.get();
            return;
        }
    }

    int commitDiwariskan = 0;
    for(int i = 0; i < totalCommit; i++){
        if(daftarCommit[i].branch == (*repo).branchAktif){

            daftarCommit[totalCommit] = daftarCommit[i];

            // ubah branch commit hasil salinan
            daftarCommit[totalCommit].branch = namaBaru;

            totalCommit++;
            commitDiwariskan++;
        }
    }

    daftarBranch[totalBranch].nama = namaBaru;
    daftarBranch[totalBranch].jumlahCommit = commitDiwariskan;

    totalBranch++;
    cout << endl;

    cout << COLOR_GREEN << "[OK]" << COLOR_RESET << " Branch '" << namaBaru << "' created from '" << (*repo).branchAktif << "'" << endl;
    cout << commitDiwariskan << " commit(s) inherited" << endl;
    cout << "\nPress Enter...";
    cin.get();
}

void gitCheckout(Repository* repo, Branch daftarBranch[], int totalBranch){
    cout << "----------------------------------------" << endl;
    cout << "git checkout" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < totalBranch; i++){
        if(daftarBranch[i].nama == (*repo).branchAktif){
            cout << COLOR_GREEN << "* " << daftarBranch[i].nama << COLOR_RESET << endl;
        }else{
            cout << "  " << daftarBranch[i].nama << endl;
        }
    }
    cout << "----------------------------------------" << endl;
    string tujuan;

    cout << "Switch to branch: ";
    cin.ignore();
    getline(cin, tujuan);

    bool ditemukan = false;
    for(int i = 0; i < totalBranch; i++){
        if(daftarBranch[i].nama == tujuan){
            ditemukan = true;
            if(tujuan == (*repo).branchAktif){
                cout << endl;
                cout << "[ERROR] Invalid branch!" << endl;

                cout << "\nPress Enter...";
                cin.get();
                return;
            }
            (*repo).branchAktif = tujuan;
            cout << endl;
            cout << COLOR_GREEN << "[OK]" << COLOR_RESET << " Switched to branch '" << tujuan << "'" << endl;
            cout << "\nPress Enter...";
            cin.get();
            return;
        }
    }
    cout << endl;
    cout << "[ERROR] Invalid branch!" << endl;

    cout << "\nPress Enter...";
    cin.get();
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
        repoName = "my-repo";
    }
    cout << COLOR_GREEN << "[OK] " << COLOR_RESET << "Initialized empty repository: " << repoName << endl;
    cout << endl;
    cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << endl;

    cout << "\nPress Enter...";
    cin.get();

    Repository repo;
    Repository* ptrRepo = &repo;
    (*ptrRepo).nama = repoName;
    (*ptrRepo).branchAktif = "main";
    daftarBranch[0].nama = "main";
    daftarBranch[0].jumlahCommit = 0;

    int pilih;
    while(true){
        cout << endl;
        tampilanUtama(username, ptrRepo);
        cin >> pilih;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }else if(pilih == 1){
            tampilHeader(username);
            gitCommit(username, ptrRepo, daftarCommit, totalCommit, daftarBranch, totalBranch);
        }else if(pilih == 2){
            cin.ignore();
            tampilHeader(username);
            gitLog(ptrRepo, daftarCommit, totalCommit);
        }else if(pilih == 3){
            tampilHeader(username);
            gitBranch(ptrRepo, daftarBranch, totalBranch, daftarCommit, totalCommit);
        }else if(pilih == 4){
            tampilHeader(username);
            gitCheckout(ptrRepo, daftarBranch, totalBranch);
        }else if (pilih == 5){
            // new repository
        }else if(pilih == 6){
            // switch repository
        }else if(pilih == 0){
            cout << COLOR_CYAN << "Session ended!" << COLOR_RESET << endl;
            cout << "Author: " << username << endl;
            cout << COLOR_GREEN << "Good bye!" << COLOR_RESET << endl;
            break;
        }
    }


    return 0;

}