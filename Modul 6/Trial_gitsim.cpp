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

struct Commit{
    string hash;
    string pesan;
    string author;
    string waktu;
    string branch;
};

struct Repository{
    string nama;
    string branchAktif;
    Branch daftarBranch[100];
    int totalBranch;
    Commit daftarCommit[100];
    int totalCommit;
};

Repository daftarRepo[100];
int totalRepo = 1;
int repoAktif = 0;

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

void tampilanUtama(string username, Repository* repo, int repoAktif, int totalRepo){
    int pilih;
    cout << COLOR_CYAN << "GITSIM" << COLOR_RESET << " - Git simulator" << endl;
    cout << "Author : " << username;
    cout << " | Repo: " << (*repo).nama << " | HEAD: " << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << " | [" << repoAktif + 1 << "/" << totalRepo << "]" << endl;
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

void gitCommit(string username, Repository* repo){
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
        repo->daftarCommit[repo->totalCommit].pesan = pesan;
        repo->daftarCommit[repo->totalCommit].author = username;
        repo->daftarCommit[repo->totalCommit].hash = buatHash(repo->totalCommit);
        repo->daftarCommit[repo->totalCommit].waktu = ambilWaktu();
        repo->daftarCommit[repo->totalCommit].branch = (*repo).branchAktif;
        for(int i = 0; i < repo->totalBranch; i++){
            if(repo->daftarBranch[i].nama == (*repo).branchAktif){
                repo->daftarBranch[i].jumlahCommit++;
            }
        }
        cout << endl;

        cout << "[" << COLOR_GREEN << (*repo).branchAktif << " " << repo->daftarCommit[repo->totalCommit].hash << COLOR_RESET << "] " << repo->daftarCommit[repo->totalCommit].pesan << endl;
        cout << "----------------------------------------" << endl;
        cout << (*repo).branchAktif << " -> origin/" << (*repo).branchAktif << endl;
        cout << "$ git push origin " << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << endl;
        repo->totalCommit++;
        cout << "----------------------------------------" << endl;
    }
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

void gitLog(Repository* repo){
    cout << "----------------------------------------" << endl;
    cout << "git log [" << COLOR_GREEN << (*repo).branchAktif << COLOR_RESET << "]" << endl;
    cout << "----------------------------------------" << endl;
    bool adaCommit = false;

    for(int i = repo->totalCommit - 1; i >= 0; i--){
        if(repo->daftarCommit[i].branch == repo->branchAktif){
            adaCommit = true;
            cout << "commit " << COLOR_YELLOW << repo->daftarCommit[i].hash << COLOR_RESET << endl;
            cout << "Author : "<< repo->daftarCommit[i].author << endl;
            cout << "Date   : " << repo->daftarCommit[i].waktu << endl;
            cout << "         " << "docs: "<< repo->daftarCommit[i].pesan << endl;
            cout << endl;
        }
    }
    if(!adaCommit){
        cout << "(No commits on this branch)" << endl;
    }
    cout << "\nPress Enter...";
    cin.get();
}

int hitungCommitHEAD(Repository* repo){
    int jumlah = 0;

    for(int i = 0; i < repo->totalCommit; i++){
        if(repo->daftarCommit[i].branch == repo->branchAktif){
            jumlah++;
        }
    }

    return jumlah;
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

void gitBranch(Repository* repo){
    cout << "----------------------------------------" << endl;
    cout << "git branch" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < repo->totalBranch; i++){
        if(repo->daftarBranch[i].nama == (*repo).branchAktif){
            cout << COLOR_GREEN << "* " << repo->daftarBranch[i].nama << COLOR_RESET << " (" << hitungCommitBranch(repo->daftarBranch[i].nama, repo->daftarCommit, repo->totalCommit)
                 << " commits)"
                 << endl;
        }else{
            cout << repo->daftarBranch[i].nama << " (" << hitungCommitBranch(repo->daftarBranch[i].nama, repo->daftarCommit, repo->totalCommit)
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

    for(int i = 0; i < repo->totalBranch; i++){
        if(repo->daftarBranch[i].nama == namaBaru){
            cout << endl;
            cout << "[ERROR] Branch '" << namaBaru << "' already exists!" << endl;
            cout << "\nPress Enter...";
            cin.get();
            return;
        }
    }

    int commitDiwariskan = 0;
    int jumlahCommitAwal = repo->totalCommit;
    for(int i = 0; i < jumlahCommitAwal; i++){
        if(repo->daftarCommit[i].branch == repo->branchAktif){

            repo->daftarCommit[repo->totalCommit] = repo->daftarCommit[i];

            // ubah branch commit hasil salinan
            repo->daftarCommit[repo->totalCommit].branch = namaBaru;

            repo->totalCommit++;
            commitDiwariskan++;
        }
    }

    repo->daftarBranch[repo->totalBranch].nama = namaBaru;
    repo->daftarBranch[repo->totalBranch].jumlahCommit = commitDiwariskan;

    repo->totalBranch++;
    cout << endl;

    cout << COLOR_GREEN << "[OK]" << COLOR_RESET << " Branch '" << namaBaru << "' created from '" << (*repo).branchAktif << "'" << endl;
    cout << commitDiwariskan << " commit(s) inherited" << endl;
    cout << "\nPress Enter...";
    cin.get();
}

void gitCheckout(Repository* repo){
    cout << "----------------------------------------" << endl;
    cout << "git checkout" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < repo->totalBranch; i++){
        if(repo->daftarBranch[i].nama == (*repo).branchAktif){
            cout << COLOR_GREEN << "* " << repo->daftarBranch[i].nama << COLOR_RESET << endl;
        }else{
            cout << "  " << repo->daftarBranch[i].nama << endl;
        }
    }
    cout << "----------------------------------------" << endl;
    string tujuan;

    cout << "Switch to branch: ";
    cin.ignore();
    getline(cin, tujuan);

    bool ditemukan = false;
    for(int i = 0; i < repo->totalBranch; i++){
        if(repo->daftarBranch[i].nama == tujuan){
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

void newRepository(Repository daftarRepo[], int &totalRepo){
    cout << "----------------------------------------" << endl;
    cout << "git init (new repository)" << endl;
    cout << "----------------------------------------" << endl;
    string namaRepo;

    cout << "New repository name: ";
    cin.ignore();
    getline(cin, namaRepo);

    if(namaRepo == ""){
        namaRepo = "repo-" + to_string(totalRepo + 1);
    }

    for(int i = 0; i < totalRepo; i++){
        if(daftarRepo[i].nama == namaRepo){
            cout << endl;
            cout << "[ERROR] Repository '" << namaRepo << "' already exists!" << endl;
            cout << "\nPress Enter...";
            cin.get();
            return;
        }
    }
    // simpan repository baru
    daftarRepo[totalRepo].nama = namaRepo;
    daftarRepo[totalRepo].branchAktif = "main";
    daftarRepo[totalRepo].totalBranch = 1;
    daftarRepo[totalRepo].totalCommit = 0;

    daftarRepo[totalRepo].daftarBranch[0].nama = "main";
    daftarRepo[totalRepo].daftarBranch[0].jumlahCommit = 0;

    daftarRepo[totalRepo].nama = namaRepo;
    repoAktif = totalRepo;
    totalRepo++;

    cout << endl;
    cout << COLOR_GREEN << "[OK] " << COLOR_RESET << "Repository '" << namaRepo << "' created and set as active." << endl;
    cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << endl;

    cout << "\nPress Enter...";
    cin.get();
}

void switchRepository(Repository* repo, Repository daftarRepo[], int totalRepo, int &repoAktif){
    cout << "----------------------------------------" << endl;
    cout << "switch repository" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < totalRepo; i++){
        if(i == repoAktif){
            cout << COLOR_GREEN << "* ";
        }else{
            cout << "  ";
        }
        cout << "[" << i + 1 << "] " << daftarRepo[i].nama << " (" << daftarRepo[i].totalBranch << " branch, " << hitungCommitHEAD(&daftarRepo[i]) << " commits at HEAD)" << COLOR_RESET << endl;

    }
    cout << "----------------------------------------" << endl;

    int pilihan;
    cout << "Select repository number: ";
    cin >> pilihan;

    if(cin.fail() || pilihan < 1 || pilihan > totalRepo){
        cin.clear();
        cin.ignore(1000,'\n');

        cout << endl;
        cout << "[ERROR] Invalid repository number!" << endl;

        cout << "\nPress Enter...";
        cin.ignore();
        cin.get();
        return;
    }
    repoAktif = pilihan - 1;

    cout << endl;
    cout << COLOR_GREEN << "[OK]" << COLOR_RESET << " Switched to repository '" << daftarRepo[repoAktif].nama << "'" << endl;
    cout << "HEAD: " << COLOR_GREEN << daftarRepo[repoAktif].branchAktif << COLOR_RESET << endl;
    cout << "\nPress Enter...";
    cin.ignore();
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

    repoAktif = 0;
    Repository* ptrRepo = &daftarRepo[repoAktif];
    (*ptrRepo).nama = repoName;
    (*ptrRepo).branchAktif = "main";
    daftarRepo[0].nama = repoName;
    daftarRepo[0].branchAktif = "main";
    daftarRepo[0].daftarBranch[0].nama = "main";
    daftarRepo[0].daftarBranch[0].jumlahCommit = 0;
    daftarRepo[0].totalBranch = 1;
    daftarRepo[0].totalCommit = 0;

    int pilih;
    while(true){
        cout << endl;
        tampilanUtama(username, ptrRepo, repoAktif, totalRepo);
        cin >> pilih;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }else if(pilih == 1){
            tampilHeader(username);
            gitCommit(username, ptrRepo);
        }else if(pilih == 2){
            cin.ignore();
            tampilHeader(username);
            gitLog(ptrRepo);
        }else if(pilih == 3){
            tampilHeader(username);
            gitBranch(ptrRepo);
        }else if(pilih == 4){
            tampilHeader(username);
            gitCheckout(ptrRepo);
        }else if (pilih == 5){
            tampilHeader(username);
            newRepository(daftarRepo, totalRepo);
            repoAktif = totalRepo - 1;
            ptrRepo = &daftarRepo[repoAktif];
        }else if(pilih == 6){
            tampilHeader(username);
            switchRepository(ptrRepo, daftarRepo, totalRepo, repoAktif);
            ptrRepo = &daftarRepo[repoAktif];
        }else if(pilih == 0){
            cout << COLOR_CYAN << "Session ended!" << COLOR_RESET << endl;
            cout << "Author: " << username << endl;
            cout << COLOR_GREEN << "Good bye!" << COLOR_RESET << endl;
            break;
        }
    }
    return 0;

}