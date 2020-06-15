#include <iostream>
#include <fstream>
#include"Destination.h"
#include"Utility.h"
#include"User.h"
#include"Vector.h"
#include"Date.h"

int main()
{
    char command[128];
    User current("georgi2", "goshoeqk23", "georgi.b@abv.bg");
    
    Utility functions;
 
    Vector<User> users = functions.fillUsers();

    Vector<Destination> dest = functions.fillDestination();

    std::cout << "Welcome to Traveller's app. Choose: registration, login, destinationsList" << std::endl;
    std::cin.getline(command, 246);
    char name[68];
    char pass[68];

    if (functions.checkTheOperation(command) == 1)
    {
        std::cout << "For registration enter username, password and email!" << std::endl;
        User newUser;
        std::cin >> newUser;
        users.push_back(newUser);
        functions.saveUser(users);
        std::cout << "You have successfully registered! " << std::endl;
        std::cout << "Enter your destinations, start and end date, grade, comment" << std::endl;
        Destination destination;
        std::cin >> destination;
        dest.push_back(destination);
        functions.saveDestination(dest);
        functions.createDataBaseUser(newUser, destination);   
    }
    else if (functions.checkTheOperation(command) == 2)
    {
        std::cout << "For login enter your username and password. " << std::endl;
        std::cin >> name;
        std::cin >> pass;

        functions.login(name, pass, users, current);
    }
    else if (functions.checkTheOperation(command) == 5)
    {
        std::ifstream file;
        file.open("destination.txt");
        functions.print(dest);
        file.close();
    }
    else
    {
        std::cout << "Invalid command. Choose again.";
 
    }
}

