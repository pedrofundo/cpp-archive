#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	int potionBonus = 4;
    int potion = 0;
    int gold, enemyDamage, enemyHealth, fleeChance, playerDamage, loot, hpBonus, playerHealth;
    string playerClass, playerName, mAction, fAction, sAction;
    string enemies[5] = {"goblin", "slime", "skeleton", "imp", "zombie"};
    bool mainMenu = true;

    srand(time(0));
    cout<<"Welcome to RPG, choose your class (warrior, wizard): "<<endl;
    cin>>playerClass;
    if (playerClass == "wizard") {
        gold = 10;
        playerHealth = 8;
        playerDamage = (rand() % 7) + 3;
    }
    else if (playerClass == "warrior") {
        gold = 5;
        playerHealth = 12;
        playerDamage = (rand() % 4) + 2;
    }
    else {
        cout<<"Invalid class! Try reentering in lowercase letters!";
        return 1;
    }
    int healthBeforeHealing = playerHealth;
    cout<<"What is your name, "<<playerClass<<"? "<<endl;
    cin>>playerName;
    while(mainMenu) {
        cout<<playerName<<", what will you do? (fight, health, gold, shop, quit)"<<endl;
        cin>>mAction;
        if (mAction == "health") {
            cout<<"You have "<<playerHealth<<" HP remaining."<<endl;
        }
        else if (mAction == "gold") {
            cout<<"You have "<<gold<<" gold on you!"<<endl;
        }
        else if (mAction == "quit") {
            cout<<"Until next time!"<<endl;
            mainMenu = false;
        }
        else if (mAction == "shop") {
            bool shopMenu = true;
            while (shopMenu) {
                cout<<"Welcome to the store of a single potion!"<<endl;
                cout<<"May I interest you in a... potion of healing?!"<<endl;
                cout<<"Adds 4 full HP for the mere price of 15 gold."<<endl;
                cout<<"(buy, quit)"<<endl;
                cin>>sAction;
                if (sAction == "buy" && gold >= 15) {
                    potion = potion + 1;
                    gold = gold - 15;
                    cout<<"+1 potion added!";
                }
                else if (sAction == "buy" && gold < 15) {
                    cout<<"Not enough gold on ye, get out!"<<endl;
                    shopMenu = false;
                }
                else if (sAction == "quit") {
                    cout<<"See you round, pardner.";
                    shopMenu = false;
                }
                else {
                    cout<<"Invalid command! Check spelling and ensure lowercase letters.";
                }
            }
        }
        else if (mAction == "fight") {
            bool fightMenu = true;
            int enemyIndex = rand() % 5;
            enemyHealth = (rand() %10) + 4;
            while (fightMenu) {
                cout<<"You have encountered a "<<enemies[enemyIndex]<<"! What will you do? (attack, potion, flee)"<<endl;
                cin>>fAction;
                if(fAction == "flee") {
                    fleeChance = (rand() % 10) + 1;
                    if (fleeChance >
                     5) {
                        cout<<"You managed to escape!!"<<endl;
                        fightMenu = false;
                    }
                    else {
                        cout<<"You failed to escape! You took 3 damage!"<<endl;
                        playerHealth = playerHealth - 3;
                        if (playerHealth <= 0) {
                            cout<<"Alas, you have perished, "<<playerName<<". Woe is us!";
                            return 1;
                        }
                    }
                }
                else if(fAction == "attack") {
                    cout<<"You have dealt "<<playerDamage<<" damage to the enemy!"<<endl;
                    enemyHealth = enemyHealth - playerDamage;
                    if (enemyHealth <= 0) {
                        loot = (rand() % 17) + 2;
                        hpBonus = (rand() % 4) + 2;
                        gold = gold + loot;
                        playerHealth = playerHealth + hpBonus;
                        if (playerClass == "wizard" && playerHealth > 8) {
                            playerHealth = 8;
                        }
                        else if (playerClass == "warrior" && playerHealth > 12) {
                            playerHealth = 12;
                        }
                        int truehpBonus = playerHealth - healthBeforeHealing;
                        cout<<"The enemy has been defeated! You gained "<<loot<<" gold and "<<truehpBonus<<" HP!"<<endl;
                        fightMenu = false;
                    }
                    else {
                        enemyDamage = (rand() % 4) + 2;
                        cout<<"The enemy has dealt "<<enemyDamage<<" damage to you! "<<endl;
                        playerHealth = playerHealth - enemyDamage;
                        if (playerHealth <= 0) {
                            cout<<"Alas, you have perished, "<<playerName<<". Woe is us!";
                            return 1;
                        } 
                    }                
                }
                else if(fAction == "potion") {
                    if (potion <= 0) {
                        cout<<"You don't have any potions!"<<endl;
                    }
                    else if (potion >= 1) {
                        potion = potion - 1;
                        playerHealth = playerHealth + potionBonus;
                        if (playerClass == "wizard" && playerHealth > 8) {
                            playerHealth = 8;
                        }
                        else if (playerClass == "warrior" && playerHealth > 12) {
                            playerHealth = 12;
                        }                 
                    }
                }
            }       
        }
        else {
            cout<<"Check spelling, and make sure you typed the command in lowercase."<<endl;
        }
    }
}
