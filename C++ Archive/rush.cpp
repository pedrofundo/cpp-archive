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
struct {
    int hp; // Variable HP
    int maxHp = 40; // Cannot heal over maxHp HP
    int minDamage = 11; // Cannot deal less than minDamage damage
    int maxDamage = 25; // Cannot deal more than maxDamage damage
    int critChance = 15; // critChance% Critical chance
    int gold = 50; // Starting 50 gold
    int dodgeChance; // Dodge chance, will be dependent on boss
    int crisps = 0; // Crisps count, starts with 0
    int potion = 0; // Potion count, starts with 0
    int vaporizor = 0; // determines if hero has a vaporizor
    int scarf = 0; // determines if hero has a scarf
} hero;

int main() {
    srand(time(0));
    string sAction, saAct, conAction, nkAct, nkAttack, dgAct, dgMenu;
    int playerAttackValue, bossAttackValue, bossDamage, bossCritValue, playerCritValue, heroDamage, multiplier, nuclearCounter;
    hero.hp = hero.maxHp;
    nuclearCounter = 14;
    Boss brutes[3] {
        {"Sir Antoine", 100, 100, 5, 12, 20, 133, 15},
        {"Nameless King", 160, 160, 7, 14, 33, 142, 25},
        {"Devourer of Gods", 9999, 9999, 10, 18, 10, 0, 5},
    };
    string mAction;
    string nMessages[]{
        "Time's out...", // nuclearCounter 0
        "Is this it?",
        "You feel as if doom is inevitable...",
        "You can barely move...",
        "There is no more room for existence to occupy.",
        "The universal horizon is closing in rapidly...",
        "You feel the universe closing in on itself...",
        "You're starting to forget who you are...",
        "You can't feel your body...",
        "You can't discern colors...",
        "Your muscles are getting tenser...",
        "Your vision is becoming narrower...",
        "You feel encumbered...",
        "Your movements are becoming slower..."
    };
    int currentBoss = 0;
    bool mainMenu = true;
    cout<<"You wake up in a dungeon, and you must escape."<<endl;
    while (mainMenu) {
        cout<<"It feels as if you're at home... (venture, shillings, smuggler, quit)"<<endl;
        cin>>mAction;
        if (mAction == "shillings"){
            cout<<"You have "<<hero.gold<<" shillings on you."<<endl;
        }
        else if (mAction == "quit"){
            cout<<"Until next time.";
            return 0;
        }
        else if (mAction == "smuggler") {
            bool shopMenu = true;
            while (shopMenu) {
                cout<<"Smuggler"<<endl;
                cout<<"crisps: +11HP, 20 gold. potion: +22HP, 35 gold."<<endl;
                if (currentBoss == 1) {
                    cout<<"scarf: +27 dodgechance, 20 gold"<<endl;
                }
                else if (currentBoss >= 2) {
                    cout<<"scarf: +27 dodgechance, 20 gold"<<endl;
                    cout<<"vaporizor: +11 basedamage, 40 gold"<<endl;
                }
                cout<<"(itemname, quit)"<<endl;
                cin>>sAction;
                if (sAction == "crisps" && hero.gold >= 20 ) {
                    hero.crisps = hero.crisps + 1;
                    hero.gold -= 20;
                    cout<<"+1 crisps added."<<endl;
                }
                else if (sAction == "potion" && hero.gold >= 35) {
                    hero.potion = hero.potion + 1;
                    hero.gold -= 35;
                    cout<<"+1 potion added."<<endl;
                }
                else if (sAction == "vaporizor" && hero.vaporizor == 0 &&currentBoss >= 2 && hero.gold >= 40) {
                    hero.vaporizor += 1;
                    hero.minDamage += 11;
                    hero.maxDamage += 11;
                    hero.gold -= 40;
                    cout<<"Here! Take whatever this is..."<<endl;
                }
                else if (sAction == "vaporizor" && hero.vaporizor == 1) {
                    cout<<"I don't have this anymore."<<endl;
                }
                else if (sAction == "scarf" && hero.scarf == 0 && currentBoss >= 1 && hero.gold >= 20) {
                    hero.scarf += 1;
                    hero.dodgeChance += 27;
                    hero.gold -= 20;
                    cout<<"Here! Take this cloth piece..."<<endl;
                }
                else if (sAction == "scarf" && hero.scarf == 1) {
                    cout<<"I don't have this anymore."<<endl;
                }
                else if (sAction == "quit") {
                    cout<<"Good luck"<<endl;
                    shopMenu = false;
                }
                else {
                    cout<<"Check your shillings and/or spelling. (lowercase)"<<endl;
                }
            }
        }
        else if (mAction == "venture") {
            if (currentBoss == 0) {
                hero.dodgeChance = 14;
                cout<<"You walk down the decaying dungeons, where a man covered in dirty, rusty steel"<<endl;
                cout<<"armor is sitting next to the grim, muddy stone walls. He presents himself as"<<endl;
                cout<<"'Sir Antoine', and claims to be an elite guard who was sent to protect these dungeons,"<<endl;
                cout<<"but was left to rot inside by his very men. The man has visibly lost his grip"<<endl;
                cout<<"on reality, and it appears his only goal is to escape... first by killing you."<<endl;
                bool saMenu = true;
                while(saMenu) {
                    cout<<"You have encountered Antoine! (fight, check, consume)"<<endl;
                    cin>>saAct;
                    if(saAct == "check") {
                        cout<<"The guard's once pristine armor is now covered in dirt, mud, and waste."<<endl;
                        cout<<"The emblem on his chestplate deliberately scratched out, he is no longer"<<endl;
                        cout<<"fighting for the kingdom, he is fighting for his own survival."<<endl;
                        cout<<brutes[currentBoss].hp<<" HP, "<<brutes[currentBoss].dodgeChance<<" DC"<<endl;
                    }
                    else if (saAct == "consume") {
                        bool conMenu = true;
                        while(conMenu) {
                            cout<<"What will you use? (crisps, potion, cancel)"<<endl;
                            cin>>conAction;
                            if (conAction == "cancel") {
                                conMenu = false;
                            }
                            else if (conAction == "crisps") {
                                if (hero.crisps == 0) {
                                    cout<<"You have no crisps!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.crisps -= 1;
                                    hero.hp += 11;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                    cout<<"You eat the crisps."<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                }
                            }
                            else if (conAction == "potion") {
                                if (hero.potion == 0) {
                                    cout<<"You have no potions!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.potion -= 1;
                                    hero.hp += 22;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                    cout<<"You drink the potion"<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                }
                            }
                        }
                    }    
                    else if (saAct == "fight") {
                        playerAttackValue = (rand() % 100) + 1;
                        if (playerAttackValue <= brutes[currentBoss].dodgeChance) {
                            cout<<"The guard evades your attack..."<<endl;
                            bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                            bossCritValue = (rand() % 100) + 1;
                            if (bossCritValue <= brutes[currentBoss].critChance) {
                                bossDamage = (bossDamage * 3) / 2;
                                hero.hp -= bossDamage;
                                cout<<"The guard's blade tears open through your ragged gear for "<<bossDamage<<" HP. It hurts..."<<endl;
                                if (hero.hp <= 0) {
                                    cout<<"Antoine claims the finishing blow, collapsing on you out of pure desperation."<<endl;
                                    cout<<"You perish, left to rot in these dungeons like many others before you.";
                                    return 0;
                                }
                                cout<<"Your current HP: "<<hero.hp<<endl;
                            }
                            else {
                                cout<<"The guard swings his blade..."<<endl;
                                bossAttackValue = (rand() % 100) + 1;
                                if (bossAttackValue <= hero.dodgeChance) {
                                    cout<<"You avoid the attack..."<<endl;
                                }
                                else {
                                    bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                    hero.hp -= bossDamage;
                                    cout<<"The blade hits you for "<<bossDamage<<" HP. It hurts..."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"Antoine claims the finishing blow, collapsing on you out of pure desperation."<<endl;
                                        cout<<"You perish, left to rot in these dungeons like many others before you."<<endl;
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                            }
                            
                        }
                        else {
                            heroDamage = rand() % (hero.maxDamage - hero.minDamage + 1) + hero.minDamage;
                            playerCritValue = (rand() % 100) + 1;
                            if (playerCritValue <= hero.critChance) {
                                heroDamage = (heroDamage * 3) / 2;
                                cout<<"You strike the guard in a gap of his armor. He wails in pain. (1.5x dmg)"<<endl;
                            }
                            brutes[currentBoss].hp -= heroDamage;
                            cout<<"You deal "<<heroDamage<<" damage. His breathing intensifies."<<endl;
                            if (brutes[currentBoss].hp <= 0) {
                                cout<<"As you deal what appears to be the finishing blow, the fallen guard falls to his knees,"<<endl;
                                cout<<"He mutters something you cannot make out, and collapses completely."<<endl;
                                cout<<"Rumor spreads the smuggler is selling a new item..."<<endl;
                                cout<<"+"<<brutes[currentBoss].goldReward<<" gold."<<endl;
                                hero.gold += brutes[currentBoss].goldReward;    
                                currentBoss += 1;
                                saMenu = false;
                            }
                            else {
                                bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                bossCritValue = (rand() % 100) + 1;
                                if (bossCritValue <= brutes[currentBoss].critChance) {
                                    bossDamage = (bossDamage * 3) / 2;
                                    hero.hp -= bossDamage;
                                    cout<<"The guard's blade tears open through your ragged gear for "<<bossDamage<<" HP. It hurts..."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"Antoine claims the finishing blow, collapsing on you out of pure desperation."<<endl;
                                        cout<<"You perish, left to rot in these dungeons like many others before you.";
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                                else {
                                    cout<<"The guard swings his blade..."<<endl;
                                    bossAttackValue = (rand() % 100) + 1;
                                    if (bossAttackValue <= hero.dodgeChance) {
                                        cout<<"You avoid his attack... The guard mutters something."<<endl;
                                    }
                                    else if (bossAttackValue > hero.dodgeChance) {
                                        hero.hp -= bossDamage;
                                        cout<<"The blade hits you for "<<bossDamage<<" HP."<<endl;
                                        if (hero.hp <= 0) {
                                            cout<<"Antoine claims the finishing blow, collapsing on you out of pure desperation."<<endl;
                                            cout<<"You perish, left to rot in these dungeons like many others before you.";
                                            return 0;
                                        }
                                    }
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                }
                            }
                        }   
                    }
                }
            }
            else if (currentBoss == 1) {
                hero.dodgeChance = 3;
                if (hero.scarf == 1) {
                    hero.dodgeChance += 27;
                }
                cout<<"The exit room, once guarded by Antoine, is now unoccupied, and maybe you can leave..."<<endl;
                cout<<"You budge the door... And it opens? The door was never locked. Why didn't Antoine leave?"<<endl;
                cout<<"You step out of the dungeon. Fresh air hits your nose like a sharp blade. ..."<<endl;
                cout<<"You expected a bustling city full of colors and life, but instead you're met with a now ruined,"<<endl;
                cout<<"colorless, seemingly abandoned kingdom. You push past the ruins and into the royal halls. The marble"<<endl;
                cout<<"floors are covered in soot, and resting on a cracked, ruined throne is a man who's skin is devoid of color,"<<endl;
                cout<<"his robes tattered and dirty. He stands up, and without a word he takes his sword, its edge scraping"<<endl;
                cout<<"loudly against the stone."<<endl;
                bool nkMenu = true;
                while(nkMenu) {
                    cout<<"You have encountered the Nameless King! (fight, check, consume)"<<endl;
                    cin>>nkAct;
                    if(nkAct == "check") {
                        cout<<"A sliver of human reason remains in his hollow eyes."<<endl;
                        cout<<"He doesn't hate you, he is simply begging for one final duel in the ashes."<<endl;
                        cout<<brutes[currentBoss].hp<<" HP, "<<brutes[currentBoss].dodgeChance<<" DC"<<endl;
                    }
                    else if(nkAct == "consume") {
                        bool conMenu = true;
                        while(conMenu) {
                            cout<<"What will you use? (crisps, potion, cancel)"<<endl;
                            cin>>conAction;
                            if (conAction == "cancel") {
                                conMenu = false;
                            }
                            else if (conAction == "crisps") {
                                if (hero.crisps == 0) {
                                    cout<<"You have no crisps!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.crisps -= 1;
                                    hero.hp += 11;
                                    cout<<"You eat the crisps."<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                }
                                
                            }
                            else if (conAction == "potion") {
                                if (hero.potion == 0) {
                                    cout<<"You have no potions!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.potion -= 1;
                                    hero.hp += 22;
                                    cout<<"You drink the potion."<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                }
                                
                            }
                        }
                    }
                    else if (nkAct == "fight") {
                        brutes[currentBoss].dodgeChance = 25;
                        cout<<"Prepare your attack...";
                        cout<<"(swing, lunge, cleave)";
                        cin>>nkAttack;
                        if (nkAttack == "swing") {
                            cout<<"You swing your weapon..."<<endl;
                            multiplier = 1;
                        }
                        else if (nkAttack == "lunge") {
                            cout<<"You wind up your attack...";
                            multiplier = 2;
                            brutes[currentBoss].dodgeChance += 15;
                        }
                        else if (nkAttack == "cleave") {
                            cout<<"You force the weapon down with your entire might..."<<endl;
                            multiplier = 3;
                            brutes[currentBoss].dodgeChance += 37;
                        }
                        playerAttackValue = (rand() % 100) + 1;
                        if (playerAttackValue <= brutes[currentBoss].dodgeChance) {
                            cout<<"The king sidesteps, and your attack falls short..."<<endl;
                            bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                            bossCritValue = (rand() % 100) + 1;
                            if (bossCritValue <= brutes[currentBoss].critChance) {
                                bossDamage = (bossDamage * 3) / 2;
                                hero.hp -= bossDamage;
                                cout<<"The king's blade tears open through your ragged gear for "<<bossDamage<<" HP. It hurts..."<<endl;
                                if (hero.hp <= 0) {
                                    cout<<"The king deals the final, fatal blow and you collapse to the ground."<<endl;
                                    cout<<"You perish, left to fade away in these remnants like many others before you.";
                                    return 0;
                                }
                                cout<<"Your current HP: "<<hero.hp<<endl;
                            }
                            else {
                                cout<<"The king swings his blade..."<<endl;
                                bossAttackValue = (rand() % 100) + 1;
                                if (bossAttackValue <= hero.dodgeChance) {
                                    cout<<"You avoid the attack..."<<endl;
                                }
                                else {
                                    bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                    hero.hp -= bossDamage;
                                    cout<<"The blade hits you for "<<bossDamage<<" HP."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"The king deals the final, fatal blow and you collapse to the ground."<<endl;
                                        cout<<"You perish, left to fade away in these remnants like many others before you."<<endl;
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                            }
                            
                        }
                        else {
                            heroDamage = (rand() % (hero.maxDamage - hero.minDamage + 1) + hero.minDamage) * multiplier;
                            playerCritValue = (rand() % 100) + 1;
                            if (playerCritValue <= hero.critChance) {
                                heroDamage = (heroDamage * 3) / 2;
                                cout<<"You strike the king perfectly. He recoils from your hit. (1.5x dmg)"<<endl;
                            }
                            brutes[currentBoss].hp -= heroDamage;
                            cout<<"You deal "<<heroDamage<<" damage. His grip on the sword becomes tighter."<<endl;
                            if (brutes[currentBoss].hp <= 0) {
                                cout<<"The king collapses."<<endl;
                                cout<<"The air around you becomes thinner... You look up at the glass ceiling above the king's throne,"<<endl;
                                cout<<"and you see a thin fracture slowly widening across the sky. You feel lighter than usual..."<<endl;
                                cout<<"Rumor spreads the smuggler is selling a new item."<<endl;
                                cout<<"+"<<brutes[currentBoss].goldReward<<" gold."<<endl;
                                hero.gold += brutes[currentBoss].goldReward;    
                                currentBoss += 1;
                                nkMenu = false;
                            }
                            else {
                                bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                bossCritValue = (rand() % 100) + 1;
                                if (bossCritValue <= brutes[currentBoss].critChance) {
                                    bossDamage = (bossDamage * 3) / 2;
                                    hero.hp -= bossDamage;
                                    cout<<"The king's blade tears open through your ragged gear for "<<bossDamage<<" HP. It hurts..."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"The king deals the final, fatal blow and you collapse to the ground."<<endl;
                                        cout<<"You perish, left to fade away in these remnants like many others before you.";
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                                else {
                                    cout<<"The king swings his blade..."<<endl;
                                    bossAttackValue = (rand() % 100) + 1;
                                    if (bossAttackValue <= hero.dodgeChance) {
                                        cout<<"You avoid his attack... The king scoffs to himself."<<endl;
                                    }
                                    else if (bossAttackValue > hero.dodgeChance) {
                                        hero.hp -= bossDamage;
                                        cout<<"The blade hits you for "<<bossDamage<<" HP."<<endl;
                                        if (hero.hp <= 0) {
                                            cout<<"The king deals the final, fatal blow and you collapse to the ground."<<endl;
                                            cout<<"You perish, left to fade away in these remnants like many others before you.";
                                            return 0;
                                        }
                                    }
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                }
                            }
                        }

                    }
                }
            }
            else if (currentBoss == 2) {
                hero.dodgeChance = 0;
                if (hero.scarf == 1) {
                    hero.dodgeChance += 27;
                }
                cout<<"The sky dissapears completely. You lost your sense of depth perception. These surfaces are intersecting"<<endl;
                cout<<"in angles that shouldn't exist. And within this realm, it has already noticed you. You're standing on"<<endl;
                cout<<"on everything and nothing at the same time. It feels as if the universe is closing in on itself..."<<endl;
                cout<<"You don't have much time."<<endl;
                bool dgMenu = true;
                while(dgMenu) {
                    cout<<"You have encountered the enemy!"<<endl;
                    cin>>dgAct;
                    if(dgAct == "check") {
                        cout<<"Whatever it is, you can't make it out."<<endl;
                        cout<<" HP, "<<brutes[currentBoss].dodgeChance<<" DC"<<endl;
                    }
                    else if(dgAct == "consume") {
                        bool conMenu = true;
                        while(conMenu) {
                            cout<<"What will you use? (crisps, potion, cancel)"<<endl;
                            cin>>conAction;
                            if (conAction == "cancel") {
                                conMenu = false;
                            }
                            else if (conAction == "crisps") {
                                if (hero.crisps == 0) {
                                    cout<<"You have no crisps!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.crisps -= 1;
                                    hero.hp += 11;
                                    cout<<"You eat the crisps."<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                }
                                
                            }
                            else if (conAction == "potion") {
                                if (hero.potion == 0) {
                                    cout<<"You have no potions!"<<endl;
                                }
                                else if (hero.hp == hero.maxHp) {
                                    cout<<"Your HP is already maxed out!"<<endl;
                                }
                                else {
                                    hero.potion -= 1;
                                    hero.hp += 22;
                                    cout<<"You drink the potion."<<endl;
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                    if (hero.hp > hero.maxHp) {
                                        hero.hp = hero.maxHp;
                                    }
                                }
                                
                            }
                        }
                    }
                    else if (dgAct == "fight") {
                        nuclearCounter -= 1;
                        cout<<nMessages[nuclearCounter]<<endl;
                        if (nuclearCounter == 0) {
                            cout << endl;
                            cout << "The last of existence folds inward." << endl;
                            cout << "The surfaces disappear. Then the distances between them." << endl;
                            cout << "There is nothing left to perceive." << endl;
                            cout << "Nothing left to distinguish." << endl;
                            cout << "Nothing left to escape from." << endl;
                            cout << endl;
                            cout << "Thanks for playing, seriously :)";
                            return 0;
                        }
                        brutes[currentBoss].dodgeChance = 5;
                        playerAttackValue = (rand() % 100) + 1;
                        if (playerAttackValue <= brutes[currentBoss].dodgeChance) {
                            cout<<"Your weapon swings into the emptiness..."<<endl;
                            bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                            bossCritValue = (rand() % 100) + 1;
                            if (bossCritValue <= brutes[currentBoss].critChance) {
                                bossDamage = (bossDamage * 3) / 2;
                                hero.hp -= bossDamage;
                                cout<<"Something ruptures within you. You take "<<bossDamage<<" HP. It hurts..."<<endl;
                                if (hero.hp <= 0) {
                                    cout<<"You succumb to your wounds, and are left afloat in the vast nothingness."<<endl;
                                    cout<<"You perish.";
                                    return 0;
                                }
                                cout<<"Your current HP: "<<hero.hp<<endl;
                            }
                            else {
                                cout<<"You feel a disturbance in the void..."<<endl;
                                bossAttackValue = (rand() % 100) + 1;
                                if (bossAttackValue <= hero.dodgeChance) {
                                    cout<<"You felt something ripple near you..."<<endl;
                                }
                                else {
                                    bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                    hero.hp -= bossDamage;
                                    cout<<"A wound appears... You take "<<bossDamage<<" HP."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"You succumb to your wounds, and are left afloat in the vast nothingness."<<endl;
                                        cout<<"You perish.";
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                            }
                            
                        }
                        else {
                            heroDamage = (rand() % (hero.maxDamage - hero.minDamage + 1) + hero.minDamage);
                            playerCritValue = (rand() % 100) + 1;
                            if (playerCritValue <= hero.critChance) {
                                heroDamage = (heroDamage * 3) / 2;
                            }
                            brutes[currentBoss].hp -= heroDamage;
                            cout<<"You deal "<<heroDamage<<" damage. It slithers, indifferent to your actions."<<endl;
                            if (brutes[currentBoss].hp <= 0) {
                                cout<<"Cheaters are LOSERS!!! Unless you're just curious. Take this return 1."<<endl;
                                return 1;
                            }
                            else {
                                bossDamage = rand() % (brutes[currentBoss].maxDamage - brutes[currentBoss].minDamage + 1) + brutes[currentBoss].minDamage;
                                bossCritValue = (rand() % 100) + 1;
                                if (bossCritValue <= brutes[currentBoss].critChance) {
                                    bossDamage = (bossDamage * 3) / 2;
                                    hero.hp -= bossDamage;
                                    cout<<"Something ruptures within you. You take "<<bossDamage<<" HP. It hurts..."<<endl;
                                    if (hero.hp <= 0) {
                                        cout<<"You succumb to your wounds, and are left afloat in the vast nothingness."<<endl;
                                        cout<<"You perish.";
                                        return 0;
                                    }
                                    cout<<"Your current HP: "<<hero.hp<<endl;
                                }
                                else {
                                    cout<<"You feel a disturbance in the void..."<<endl;
                                    bossAttackValue = (rand() % 100) + 1;
                                    if (bossAttackValue <= hero.dodgeChance) {
                                        cout<<"You felt something ripple near you..."<<endl;
                                    }
                                    else if (bossAttackValue > hero.dodgeChance) {
                                        hero.hp -= bossDamage;
                                        cout<<"The blade hits you for "<<bossDamage<<" HP."<<endl;
                                        if (hero.hp <= 0) {
                                            cout<<"You succumb to your wounds, and are left afloat in the vast nothingness."<<endl;
                                            cout<<"You perish.";
                                            return 0;
                                        }
                                    }
                                    cout<<"Current HP: "<<hero.hp<<endl;
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}