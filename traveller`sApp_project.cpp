#include <iostream>
#include"Destination.h"
#include"HelpFunctions.h"
#include"User.h"
#include<fstream>
#include"Vector.h"
#include"timePeriod.h"

int main()
{
    char text[128];

    User newUser("yoanna", "yoannavslv", "mitko69@gmail.com"); //user class - working
    std::ofstream file;
    file.open("output.txt");
    file << newUser;
    file.close();
    

    
    Date d(3, 10, 2005);
    std::cout << d;

}
