#include <iostream>
#include <vector>
#include <string>

void inputHandling(int &position) {
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cout<<"Invalid position!";
        position = -1;
    }
}
int main() {
    std::vector<std::string> index;
    std::string action;

    while (true) {
        std::cout<<"\nInput your action (listindex, addtoindex, removefromindex, exit): ";
        std::cin>>action;

        if (action == "exit") {
            std::cout<<"Exiting..."<<std::endl;
            return 0;
        }
        
        if (action == "listindex") {
            int i = 0;
            if (index.empty()) {
                std::cout<<"No entries yet! Add a new one using 'addtoindex'!";
                continue;
            }
            
            while (i < index.size()) {
                std::cout<<i + 1<<". "<<index[i]<<std::endl;
                i++;
            }
        }
        else if (action == "addtoindex") {
            std::cout<<"Insert position (1 to "<< index.size() + 1 <<"): ";
            int position;
            std::cin>>position;
            inputHandling(position);
            
            if (position >= 1 && position <= index.size() + 1) {
                std::cin.ignore(); // Empty argument consumes 1 char (newline in this case)
                std::cout<<"Input full name: ";
                std::string name;
                std::getline(std::cin, name);
                index.insert(index.begin() + (position - 1), name);
                std::cout<<name<<" added successfully!"<< std::endl;
            } else {
                if (position != -1) {
                    std::cout<<"Invalid position!"<<std::endl;
                }                
            }
        }
        else if (action == "removefromindex") {
            if (index.empty()) {
                std::cout<<"Nothing to remove! Add a new entry using 'addtoindex'!";
                continue;
            } else {
              std::cout<<"Insert position (1 to "<< index.size()<<"): ";
              int position;
              std::cin>>position;
              inputHandling(position);
              if (position >= 1 && position <= index.size()) {
                index.erase(index.begin() + position - 1);
                std::cout<<"Entry deleted successfully!";
            } else {
                std::cout<<"Invalid position!"<<std::endl;
                }
            }
        }
        else {
            std::cout<<"Unknown action. Try again." << std::endl;
        }
    }

    return 0;
}
