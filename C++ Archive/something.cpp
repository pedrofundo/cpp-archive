#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
	int balance, gamble, playerValue, dealerValue;
	string mAction, gAction;
    
    srand(time(0));
	bool mainMenu = true;
	cout<<"Welcome to 'Blackjack But the Ace is Always Equal to 1'."<<endl;
	cout<<"Enter your starting balance: ";
	cin>>balance;
	while(mainMenu){ 
		cout<<"Available actions: play, balance, quit"<<endl;
		cin>>mAction;
		if (mAction == "quit") {
			cout<<"Until next time!";
			mainMenu = false;
		}
		else if (mAction == "balance") {
			cout<<"You currently have "<<balance<<" in your balance."<<endl;
		}
		else if (mAction == "play") {
			bool payMenu = true;
			while(payMenu) {
				cout<<"Bet amount: ";
				cin>>gamble;
				if (gamble > balance) {
					cout<<"You only have "<<balance<<" in your balance!"<<endl;
					continue;
				}
				balance = balance - gamble;
				playerValue = (rand() % 10) + 1 + (rand() % 10) + 1;
				dealerValue = (rand() % 10) + 1 + (rand() % 10) + 1;
				bool gambleMenu = true;
				while (gambleMenu) {
					cout<<"Player: "<<playerValue<<" Dealer: "<<dealerValue<<" (hit, stand)"<<endl;
					cin>>gAction;
					if (gAction == "stand") {
						while(dealerValue < 17) {
							dealerValue = dealerValue + (rand() % 10) + 1;
						}
						if (dealerValue > 21) {
							cout<<"Dealer has bust! You win!"<<endl;
							balance = balance + gamble * 2;
							gambleMenu = false;
							payMenu = false;
						}
						else if (dealerValue > playerValue) {
							cout<<"The dealer has won! You lose."<<endl;
							gambleMenu = false;
							payMenu = false;
						}
						else if (dealerValue == playerValue) {
							cout<<"Push. You get your money back."<<endl;
							balance = balance + gamble;
							gambleMenu = false;
							payMenu = false;
						}
						else if (playerValue > dealerValue) {
							cout<<"You win!"<<endl;
							balance = balance + gamble * 2;
							gambleMenu = false;
							payMenu = false; 
						}
					}
					else if (gAction == "hit") {
						playerValue = playerValue + (rand() % 10) + 1;
						if (playerValue > 21) {
							cout<<"Bust! You lose."<<endl;
							gambleMenu = false;
							payMenu = false;
						}
					}
				}
			}
		}
	}
}