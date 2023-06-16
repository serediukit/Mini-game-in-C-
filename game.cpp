#include <bits/stdc++.h>

using namespace std;

int main() {
    int hp = 100;
    int mp = 50;
    int armor = 5;
    int damage = 10;

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

        switch (choice) {
            case 1:
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
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                }

                cout << "Monter: " << monsterName << endl;

                system("pause");
                break;
            case 2:
                cout << "Healing...\n";
                if (mp >= 5) {
                    mp -= 5;
                    hp += 20;
                    if (hp > 100)
                        hp = 100;
                }
                system("pause");
                break;
            default:
                cout << "Exiting...\n";
                break;
        }
    }

    return 0;
}
