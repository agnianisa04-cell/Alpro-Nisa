#include <iostream>
#include <cstdlib>

using namespace std;

struct Player{
    string nama;
    int hp, maxHp;
    int mp, maxMp;
    int agi;
    int exp;
    int level;
};

struct Enemy{
    string nama;
    int hp, maxHp;
    int agi;
    int expReward;
};

void clearScreen(){

    cout << "\033[2J\033[H";
}

void pressEnter(){

    cin.ignore();
    cin.get();
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

void sevenDeadlySins(){

    cout << "+=======================================================================+" << endl;
    cout << "|                     THE 7 DEADLY SINS                                |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "| 1. Pride                                                             |" << endl;
    cout << "| 2. Greed                                                             |" << endl;
    cout << "| 3. Wrath                                                             |" << endl;
    cout << "| 4. Sloth                                                             |" << endl;
    cout << "| 5. Gluttony                                                          |" << endl;
    cout << "| 6. Envy                                                              |" << endl;
    cout << "| 7. Lust                                                              |" << endl;
    cout << "| 8. Exit                                                              |" << endl;
    cout << "+=======================================================================+" << endl;
}

void attackMenu(){

    cout << "+=======================================================================+" << endl;
    cout << "| 1. Basic Attack    (No MP | 100% ATK)                                |" << endl;
    cout << "| 2. Heavy Attack    (30 MP | 160% ATK | lower accuracy)               |" << endl;
    cout << "| 3. Heal            (20 MP | Restore 200 HP)                          |" << endl;
    cout << "| 4. Run Away        (Exit game)                                       |" << endl;
    cout << "+=======================================================================+" << endl;
}

void battleScreen(Player player, Enemy enemy){

    clearScreen();

    cout << "+=======================================================================+" << endl;
    cout << "|                         ABYSSAL REALM                                 |" << endl;
    cout << "+=======================================================================+" << endl;

    cout << "| [" << player.nama << "]" << endl;
    cout << "| HP    : " << player.hp << " / " << player.maxHp << endl;
    cout << "| MP    : " << player.mp << " / " << player.maxMp << endl;
    cout << "| AGI   : " << player.agi << endl;
    cout << "| EXP   : " << player.exp << endl;
    cout << "| LEVEL : " << player.level << endl;

    cout << "+=======================================================================+" << endl;

    cout << "| [" << enemy.nama << "]" << endl;
    cout << "| HP    : " << enemy.hp << " / " << enemy.maxHp << endl;
    cout << "| AGI   : " << enemy.agi << endl;
    cout << "| EXP   : " << enemy.expReward << endl;

    attackMenu();
}

int main(){

    srand(time(0));

    Player player;

    banner();

    cout << "\n[Enter your name]: ";
    getline(cin, player.nama);

    player.level = 1;
    player.exp = 0;

    Enemy sins[7][4] = {

        // Pride
        {
            {"Arrogant Soldier", 50, 50, 5, 10},
            {"Noble Knight", 120, 120, 20, 70},
            {"Fallen Champion", 200, 200, 40, 140},
            {"King of Pride", 400, 400, 80, 300}
        },

        // Greed
        {
            {"Gold Hoarder", 70, 70, 10, 20},
            {"Corrupt Merchant", 140, 140, 25, 80},
            {"Living Treasure", 230, 230, 45, 160},
            {"Dragon of Greed", 450, 450, 90, 350}
        },

        // Wrath
        {
            {"Furious Beast", 80, 80, 12, 25},
            {"Berserker", 150, 150, 30, 90},
            {"Flame Demon", 250, 250, 50, 180},
            {"Avatar of Wrath", 500, 500, 100, 400}
        },

        // Sloth
        {
            {"Lazy Undead", 85, 85, 10, 28},
            {"Sleeping Giant", 160, 160, 28, 95},
            {"Dream Spirit", 260, 260, 48, 190},
            {"Lord of Sloth", 520, 520, 105, 420}
        },

        // Gluttony
        {
            {"Hungry Slime", 90, 90, 12, 30},
            {"Devourer Beast", 150, 150, 30, 80},
            {"Endless Maw", 200, 200, 45, 130},
            {"Lord of Gluttony", 350, 350, 70, 250}
        },

        // Envy
        {
            {"Shadow Copy", 100, 100, 15, 35},
            {"Mirror Spirit", 170, 170, 35, 90},
            {"Shapeshifter", 230, 230, 50, 150},
            {"Embodiment of Envy", 400, 400, 75, 300}
        },

        // Lust
        {
            {"Charming Spirit", 110, 110, 18, 40},
            {"Siren", 190, 190, 40, 110},
            {"Succubus", 260, 260, 60, 180},
            {"Queen of Lust", 450, 450, 80, 350}
        }
    };

    string sinNames[7] = {

        "Pride",
        "Greed",
        "Wrath",
        "Sloth",
        "Gluttony",
        "Envy",
        "Lust"
    };

    int stage;
    int path;

    while(true){

        clearScreen();

        sevenDeadlySins();

        cout << "\n[Choose your desired stage]: ";
        cin >> stage;

        if(stage == 8){

            cout << "\nThank you for playing Abyssal Realm!" << endl;
            break;
        }

        if(stage < 1 || stage > 8){

            cout << "\nInvalid Input!";
            pressEnter();
            continue;
        }

        clearScreen();

        cout << "+=======================================================================+" << endl;
        cout << "|                            " << sinNames[stage - 1] << endl;
        cout << "+=======================================================================+" << endl;

        cout << "| 1. " << sins[stage - 1][0].nama << endl;
        cout << "| 2. " << sins[stage - 1][1].nama << endl;
        cout << "| 3. " << sins[stage - 1][2].nama << endl;
        cout << "| 4. " << sins[stage - 1][3].nama << " (Boss)" << endl;
        cout << "| 5. Retreat" << endl;

        cout << "+=======================================================================+" << endl;

        cout << "\n[Choose Enemy]: ";
        cin >> path;

        if(path == 5){
            continue;
        }

        Enemy enemy = sins[stage - 1][path - 1];

        // PLAYER STATUS

        if(path == 1){

            player.hp = 1500;
            player.maxHp = 1500;

            player.mp = 100;
            player.maxMp = 100;

            player.agi = 15;
        }

        else if(path == 2){

            player.hp = 12000;
            player.maxHp = 12000;

            player.mp = 300;
            player.maxMp = 300;

            player.agi = 80;
        }

        else if(path == 3){

            player.hp = 20000;
            player.maxHp = 20000;

            player.mp = 400;
            player.maxMp = 400;

            player.agi = 120;
        }

        else{

            player.hp = 25000;
            player.maxHp = 25000;

            player.mp = 500;
            player.maxMp = 500;

            player.agi = 150;
        }

        int choice;

        // ================= BATTLE LOOP =================

        while(player.hp > 0 && enemy.hp > 0){

            battleScreen(player, enemy);

            cout << "\n[Choose action]: ";
            cin >> choice;

            // ================= BASIC ATTACK =================

            if(choice == 1){

                int damage = rand() % 41 + 80;

                cout << "\n[Basic Attack] "
                     << player.nama
                     << " attacks "
                     << enemy.nama
                     << "!" << endl;

                int enemyDodge = rand() % 100;

                if(enemyDodge < enemy.agi / 2){

                    cout << enemy.nama
                         << " dodged the attack!"
                         << endl;
                }

                else{

                    enemy.hp -= damage;

                    if(enemy.hp < 0){
                        enemy.hp = 0;
                    }

                    cout << enemy.nama
                         << " takes "
                         << damage
                         << " damage!"
                         << endl;
                }
            }

            // ================= HEAVY ATTACK =================

            else if(choice == 2){

                if(player.mp >= 30){

                    player.mp -= 30;

                    int accuracy = rand() % 100;

                    cout << "\n[Heavy Attack] "
                         << player.nama
                         << " unleashes a powerful strike!"
                         << endl;

                    if(accuracy < 30){

                        cout << "But the attack missed!"
                             << endl;
                    }

                    else{

                        int damage = rand() % 61 + 140;

                        int enemyDodge = rand() % 100;

                        if(enemyDodge < enemy.agi / 2){

                            cout << enemy.nama
                                 << " dodged the Heavy Attack!"
                                 << endl;
                        }

                        else{

                            enemy.hp -= damage;

                            if(enemy.hp < 0){
                                enemy.hp = 0;
                            }

                            cout << enemy.nama
                                 << " takes "
                                 << damage
                                 << " damage!"
                                 << endl;
                        }
                    }
                }

                else{

                    cout << "\nNot enough MP!" << endl;
                }
            }

            // ================= HEAL =================

            else if(choice == 3){

                if(player.mp >= 20){

                    player.mp -= 20;

                    int heal = 200;

                    player.hp += heal;

                    if(player.hp > player.maxHp){
                        player.hp = player.maxHp;
                    }

                    cout << "\n[Heal] "
                         << player.nama
                         << " restores "
                         << heal
                         << " HP!"
                         << endl;
                }

                else{

                    cout << "\nNot enough MP!" << endl;
                }
            }

            // ================= RUN AWAY =================

            else if(choice == 4){

                cout << "\nYou ran away!" << endl;
                break;
            }

            else{

                cout << "\nInvalid choice!" << endl;
            }

            // ================= ENEMY TURN =================

            if(enemy.hp > 0){

                cout << "\n[" << enemy.nama
                     << "] attacks!" << endl;

                int dodge = rand() % 100;

                if(dodge < player.agi / 2){

                    cout << player.nama
                         << " dodged the attack!"
                         << endl;
                }

                else{

                    int enemyDamage = rand() % 81 + 20;

                    player.hp -= enemyDamage;

                    if(player.hp < 0){
                        player.hp = 0;
                    }

                    cout << player.nama
                         << " takes "
                         << enemyDamage
                         << " damage!"
                         << endl;
                }
            }

            cout << "\n";
            pressEnter();
        }

        // ================= RESULT =================

        if(enemy.hp <= 0){

            cout << "\n=====================================" << endl;
            cout << "Enemy Defeated!" << endl;

            player.exp += enemy.expReward;

            cout << "You gained "
                 << enemy.expReward
                 << " EXP!" << endl;

            if(player.exp >= 100){

                player.level++;
                player.exp -= 100;

                cout << "LEVEL UP!" << endl;
                cout << "Current Level : "
                     << player.level
                     << endl;
            }
        }

        else if(player.hp <= 0){

            cout << "\n=====================================" << endl;
            cout << "You were defeated..." << endl;
        }

        pressEnter();
    }

    return 0;
}