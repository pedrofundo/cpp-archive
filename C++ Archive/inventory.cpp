#include <iostream>
#include <vector>
#include <string>

struct Product {
    std::string name;
    int id;
    int quantity;
    double price;
};

bool (inputHandling()) {
	if (!std::cin){
		std::cin.clear();
		std::cin.ignore(2147483647, '\n');
		std::cout<<"Invalid input!";
		return true;
	}
	return false;
}
int main(){
	std::vector<Product> item;
	Product nProd;
	while(true) {
		std::cout<<"\nInput your action (add, list, remove, search, help, exit): ";
		std::string action;
		std::cin>>action;
		if (action == "exit") {
			std::cout<<"Exiting..."<<std::endl;
			return 0;
		} else if (action == "add") {
			std::cout<<"Enter product name."<<std::endl;
            std::cin.ignore(9999, '\n');
			getline(std::cin, nProd.name);
			std::cout<<"Enter product ID."<<std::endl;
			std::cin>>nProd.id;
			if (inputHandling()) {
            	continue;
            }
			std::cout<<"Enter product quantity."<<std::endl;
			std::cin>>nProd.quantity;
            if (inputHandling()) {
            	continue;
            }
			std::cout<<"Enter product price."<<std::endl;
			std::cin>>nProd.price;
			if (inputHandling()) {
            	continue;
            }
            item.push_back(nProd);
            std::cout<<"Product added successfully!";
		}
		else if (action == "help") {
			std::cout<<"add    - adds a new product to the list"<<std::endl;
			std::cout<<"list   - displays the product list "<<std::endl;
			std::cout<<"search - by inputting a product ID, search fetches and prints out its info"<<std::endl;
			std::cout<<"remove - by inputting a product ID, remove fetches and removes ALL info"<<std::endl;
		}
		else if (action == "list") {
			int i = 0;
            if (item.empty()) {
                std::cout<<"No products yet! Add a new one using 'add'!";
                continue;
            }
            
            while (i < item.size()) {
                std::cout<<i + 1<<". "<<item[i].name<<std::endl;
                std::cout<<"   ID: "<<item[i].id<<std::endl;
                std::cout<<"   Quantity: "<<item[i].quantity<<std::endl;
                std::cout<<"   Price: "<<item[i].price<<std::endl;
                i++;
            }
		}
		else if (action == "search") {
			std::cout<<"Enter ID of the product you want to fetch."<<std::endl;
			int searchID;
			std::cin>>searchID;
			if (inputHandling()) {
            	continue;
            }
			int i = 0;
			bool found = false;
			while(i < item.size()) {
			    if (item[i].id == searchID) {
                    std::cout<<i + 1<<". "<<item[i].name<<std::endl;
                    std::cout<<"   ID: "<<item[i].id<<std::endl;
                    std::cout<<"   Quantity: "<<item[i].quantity<<std::endl;
                    std::cout<<"   Price: "<<item[i].price<<std::endl;
                    found = true;
                    break;
			    }
			    i++;
            }
            if(found == false) {
			    std::cout<<"Invalid ID! Check your list and try again!";
			}
		}
		else if (action == "remove") {
			std::cout<<"Enter ID of the product you want to erase."<<std::endl;
			int removeID;
			std::cin>>removeID;
			if (inputHandling()) {
				continue;
			}
			int i = 0;
			bool exterminated = false;
			while(i < item.size()) {
			    if (item[i].id == removeID) {
                    item.erase(item.begin()+i);
                    exterminated = true;
                    break;
			    }
			    i++;
            }
            if (exterminated == false) {
            	std::cout<<"Invalid ID! Check your list and try again!";
            }
		}
	}
}