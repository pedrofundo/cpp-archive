#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Boss {
    string name;
    int hp;
    int maxHp;
    int minDamage;
    int maxDamage;
    int critChance;
    int goldReward;
    int dodgeChance;
};

int main() {
    srand(time(0));
    struct {
        int hp; // Variable HP
        int maxHp = 40; // Cannot heal over maxHp HP
     	int minDamage = 11; // Cannot deal less than minDamage damage
        int maxDamage = 25; // Cannot deal more than maxDamage damage
        int critChance = 15; // critChance% Critical chance
        int gold = 50; // Starting 50 gold
        int dodgechance; // Dodge chance, will be dependent on boss
        int potions = 0; // Potion count, starts with 0
    } hero;
    hero.hp = hero.maxHp;
    Boss brutes[3] {
    	{"Sir Antoine", 100, 100, 5, 12, 20, 93, 15},
    	{"Nameless King", 160, 160, 7, 14, 33, 12, 25},
    	{"Devourer of Gods", 300, 300, 10, 18, 10, 0, 5},
    };
    string mAction;
    int currentBoss = 0;
    bool mainMenu = true;
    cout<<"You wake up in a dungeon, and your only escape is to defeat 3 mythical creatures..."<<endl;
    while (mainMenu) {
    	cout<<"You're in a dungeon... (venture, shillings, smuggler, quit)"<<endl;
        cin>>mAction;
    	if (mAction == "shillings"){
    		cout<<"You have "<<hero.gold<<" shillings on you."<<endl;
    	}
    	else if (mAction == "quit"){
    		cout<<"Until next time.";
    		return 0;
    	}
    }

}