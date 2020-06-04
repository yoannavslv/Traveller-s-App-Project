#include <iostream>
#include<fstream>
#include"Destination.h"
#include"Utility.h"
#include"User.h"
#include"Vector.h"
#include"Date.h"

int main()
{
    char command[246];

    User newUser("boris", "leminera2121", "lemineraco@gmail.com");
    Date newDate(2, 10, 1999, 2, 10, 2000);
    
    Utility functions;
 
    Vector<User> users = functions.fillUsers();
    //std::cout << users;

    Vector<Destination> dest = functions.fillDestination();

    std::cout << dest;
    std::cout << "Welcome to Traveller's app. Choose: registration, login, friendsList, averageGrades, destinationsList" << std::endl;
    std::cin.getline(command, 2460);
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
        std::cout << "Enter your destinations, start and end date, grade, comment and photos." << std::endl;
        std::cout << "To save the file and exit please enter EXIT " << std::endl;
        Destination destination;
        std::cin >> destination;
        functions.createDataBaseUser(newUser, destination);
        dest.push_back(destination);
        functions.saveDestination(dest); 
    }
    else if (functions.checkTheOperation(command) == 2)
    {
        std::cout << "For login enter your username and password. " << std::endl;
        std::cin >> name;
        std::cin >> pass;

        functions.login(name, pass, users, newUser);
    }
    else if (functions.checkTheOperation(command) == 3)
    {
        
    }
    else if (functions.checkTheOperation(command) == 4)
    {
      
    }
    else if (functions.checkTheOperation(command) == 5)
    {
        std::ofstream file;
        file.open("destinations.txt");
        //Destination print(dest);
    }
    else
    {
        std::cout << "Invalid command. Choose again.";
    }
}
