#include <iostream>
#include <vector>

int main() {
	std::vector<int> index;
	while(true) {
		std::cout<<"choose program - a (Add, l (List), r (Remove): ";
		char input;
		std::cin>>input;
		if (input == 'l') {
			if (index.empty()) {
				std::cout<<"List is empty! Add a new entry by using 'a' ";
			} else {
				int i;
				for (i = 0; i < index.size(); i++) {
					std::cout<<index[i]<<std::endl;
				}
			}
		} else if (input == 'a') {
			std::cout<<"Input your number: ";
			int ninput;
			std::cin>>ninput;
			index.push_back(ninput);
		}		
	}
}