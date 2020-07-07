#include <iostream>
#include <fstream>
#include"Destination.h"
#include"Utility.h"
#include"User.h"
#include "Vector.h"
#include"Date.h"

int main()
{
    char command[128];
    User current("georgi2", "goshoeqk23", "georgi.b@abv.bg");

    Utility f;

    Vector<User> users = f.fillUsers();
    Vector<Destination> dest = f.fillDestination();
    User newUser;
    Destination destination;
    std::ifstream file;

    char name[68];
    char pass[68];
    bool exit = 1;

    std::cout << "Welcome to Traveller's app. ";
    std::cout << "Choose: registration, login, destinationsList" << std::endl;

    do 
    {
        std::cin.getline(command, 64);

        switch (f.checkTheOperation(command))
        {
        case 1:
            std::cout << "For registration enter username, password and email!" << std::endl;
            
            std::cin >> newUser;
            users.push_back(newUser);
            f.saveUser(users);
            std::cout << "You have successfully registered! " << std::endl;
            std::cout << "Enter your destinations, start and end date, grade, comment" << std::endl;

            std::cin >> destination;
            dest.push_back(destination);
            f.saveDestination(dest);
            f.createDataBaseUser(newUser, destination);
            std::cout << std::endl;
            break;

        case 2:
            std::cout << "For login enter your username and password. " << std::endl;
            std::cin >> name;
            std::cin >> pass;

            f.login(name, pass, users, current);
            std::cout << std::endl;
            break;

        case 3:
           
            file.open("destination.txt");
            f.print(dest);
            file.close();
            std::cout << std::endl;
            break;
            
        case 4:
            exit = 0;
            std::cout << "You are closing the program." << std::endl;
            break;

        default: std::cout << "Invalid command" << std::endl; 
          break;

        }

    } while (exit);
    
}

