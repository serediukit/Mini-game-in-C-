#include <bits/stdc++.h>

using namespace std;

int main() {
    srand( time(NULL) );

    int hp = 100;
    int mp = 50;
    int armor = 5;
    int damage = 10;
    int killsCount = 0;

    string name;
    cout << "Input your name: ";
    cin >> name;

    while (true) {
        system("cls");

        cout << "Player: " << name << endl;

        cout << endl << "HP |";
        for (int i = 1; i <= 20; i++) {
            if (i*5 <= hp) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << "| " << hp << "/100" << endl;

        cout << endl << "MP |";
        for (int i = 1; i <= 10; i++) {
            if (i*5 <= mp) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << "| " << mp << "/50" << endl<< endl << endl;

        cout << "--------MENU--------\n";
        cout << "--------------------\n";
        cout << "1. Go to fight\n";
        cout << "2. Heal (5 mp cost)\n";
        cout << "3. Exit\n";
        cout << "--------------------\n\n";

        int choice;
        cout << "Yout choice: ";
        cin >> choice;

        // Variables...
        int monsterType, monsterHP, monsterArmor, monsterDamage;
        string monsterName;

        int attackType;

        switch (choice) {
            case 1:
                monsterType = rand()%5 + 1;

                switch (monsterType) {
                    case 1:
                        monsterName = "Zombie";
                        monsterHP = 20;
                        monsterArmor = 2;
                        monsterDamage = 5;
                        break;
                    case 2:
                        monsterName = "Skelet";
                        monsterHP = 15;
                        monsterArmor = 0;
                        monsterDamage = 15;
                        break;
                    case 3:
                        monsterName = "Phantom";
                        monsterHP = 21;
                        monsterArmor = 3;
                        monsterDamage = 22;
                        break;
                    case 4:
                        monsterName = "Lader";
                        monsterHP = 10;
                        monsterArmor = 4;
                        monsterDamage = 20;
                        break;
                    case 5:
                        monsterName = "Niner";
                        monsterHP = 5;
                        monsterArmor = 8;
                        monsterDamage = 35;
                        break;
                }

                while (monsterHP > 0) {
                    system("cls");

                    cout << "Player: " << name << endl;

                    cout << endl << "HP |";
                    for (int i = 1; i <= 20; i++) {
                        if (i*5 <= hp) {
                            cout << "#";
                        } else {
                            cout << " ";
                        }
                    }
                    cout << "| " << hp << "/100" << endl;

                    cout << endl << "MP |";
                    for (int i = 1; i <= 10; i++) {
                        if (i*5 <= mp) {
                            cout << "#";
                        } else {
                            cout << " ";
                        }
                    }
                    cout << "| " << mp << "/50" << endl<< endl << endl;

                    cout << "Monster name: " << monsterName << endl;
                    cout << "Monster HP: " << monsterHP << endl;
                    cout << "Monster armor: " << monsterArmor << endl;
                    cout << "Monster damage: " << monsterDamage << endl;

                    cout << endl << endl;

                    cout << "--------------------MENU--------------------\n";
                    cout << "--------------------------------------------\n";
                    cout << "1. Sword attack\n";
                    cout << "2. Magic attack (+5 damage, 10 mp cost)\n";
                    cout << "3. Leave\n";
                    cout << "--------------------------------------------\n\n";
                    cout << "Yout choice: ";

                    cin >> attackType;

                    switch (attackType) {
                        case 1:
                            cout << "You attacked with your sword " << damage - monsterArmor << " hp\n";

                            monsterHP -= damage - monsterArmor;
                            if (monsterHP < 0)
                                monsterHP = 0;

                            monsterArmor--;
                            if (monsterArmor < 0)
                                monsterArmor = 0;

                            cout << "Current monster HP: " << monsterHP << endl << endl << endl;
                            break;
                        case 2:
                            if (mp >= 10) {
                                cout << "You attacked with your magic wand " << damage + 5 << " hp\n";
                                monsterHP -= damage + 5;
                                if (monsterHP < 0)
                                    monsterHP = 0;
                                cout << "You spend 10 mp\n";
                                mp -= 10;
                                cout << "Current monster HP: " << monsterHP << endl << endl << endl;
                            } else {
                                cout << "You attacked with your wand 1 hp\n";
                                monsterHP -= 1;
                                cout << "Current monster HP: " << monsterHP << endl << endl << endl;
                            }
                            break;
                        default:
                            cout << "GAME OVER\n";
                            if (killsCount >= 5) {
                                cout << "YOU KILLED " << killsCount << "MONSTERS!!!\n";
                                cout << "YOU ARE GREATE!\n";
                            } else {
                                cout << "You are looser...\n";
                                cout << "But you killed " << killsCount << " monsters!\n";
                            }
                            cout << "Exiting the game...\n";
                            return 0;
                    }

                    if (monsterHP == 0) {
                        system("pause");
                        break;
                    }

                    cout << "MONSTER IS ATTACKING!!!\n";
                    cout << monsterName << " attacked you on " << monsterDamage - armor << " hp\n";
                    hp -= monsterDamage - armor;
                    if ( hp < 0 )
                        hp = 0;
                    cout << "Current " << name << " hp: " << hp << endl << endl;

                    if ( hp == 0 ) {
                        cout << endl << endl;
                        cout << "GAME OVER\n";
                        if (killsCount >= 5) {
                            cout << "YOU KILLED " << killsCount << "MONSTERS!!!\n";
                            cout << "YOU ARE GREATE!\n";
                        } else {
                            cout << "You are looser...\n";
                            cout << "But you killed " << killsCount << " monsters!\n";
                        }
                        cout << "Exiting the game...\n";
                        cout << endl << endl;
                        return 0;
                    }

                    system("pause");
                }

                system("cls");

                cout << monsterName << " has been defeated!\n\n\n";
                killsCount++;

                system("pause");

                break;
            case 2:
                if (mp >= 5) {
                    cout << "Healing...\n";
                    mp -= 5;
                    hp += 20;
                    if (hp > 100)
                        hp = 100;
                } else {
                    cout << "You haven't enough mp...\n";
                }
                system("pause");
                break;
            default:
                cout << "You killed " << killsCount << " monsters\n";
                cout << "Exiting...\n";
                break;
        }
    }

    return 0;
}
