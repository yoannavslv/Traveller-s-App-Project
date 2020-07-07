#include <iostream>
#include "Utility.h"
#include<string>
#include <fstream>

char command[4][17] = { "registration", "login", "destinationsList", "exit"};


size_t Utility::numberOfSymbols(char* text, char symbol)
{
	size_t counter = 0;
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

char* Utility::substring(char* text, int firstPosition, int secondPosition)
{
	size_t lenght = strlen(text);
	char* substring = new char[lenght - firstPosition + 1];
	for (size_t i = 0; i < secondPosition - firstPosition; i++)
	{
		substring[i] = text[i + firstPosition];
	}
	substring[secondPosition - firstPosition] = 0;
	return substring;
}

size_t Utility::index(char* text, char symbol)
{
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

size_t Utility::theLastIndex(char* text, char symbol)
{
	int lenght = strlen(text);
	for (int i = lenght; i >= 0; i--)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

Vector<char*> Utility::split(char* text)
{
	Vector<char*> newSpace;
	while (numberOfSymbols(text, ' '))
	{
		newSpace.push_back(substring(text, 0, index(text, ' ')));
		text = substring(text, index(text, ' ') + 1, strlen(text) + 1);
	}
	newSpace.push_back(text);
	return newSpace;
}

Vector<User> Utility::fillUsers()
{
	Vector<User> users;
	std::ifstream file("users.db.txt");
	User current;
	while (file >> current)
	{
		users.push_back(current);
	}
	file.close();
	return users;
}

Vector<Destination> Utility::fillDestination()
{
	Vector<Destination> destinations;
	std::ifstream file("destination.txt");
	Destination current;
	while (file >> current)
	{
		destinations.push_back(current);
	}
	file.close();
	return destinations;
}

size_t Utility::checkTheOperation(char* text)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (strcmp(text, command[i]) == 0)
		{
			return i + 1;
		}
	}
	return -1;
}

void Utility::saveUser(Vector<User>& users)
{
	std::ofstream file("users.db.txt");
	for (size_t i = 0; i < users.length(); i++)
	{
		file << users[i];
	}
	file.close();
}

void Utility::saveDestination(Vector<Destination>& destination)
{
	std::ofstream file("destination.txt");
	for (size_t i = 0; i < destination.length(); i++)
	{
		file << destination[i];
	}
	file.close();
}

void Utility::login(char* name, char* pass, Vector<User> users, User curr)
{
	for (size_t i = 0; i < users.length(); i++)
	{
		if (strcmp(name, users[i].getUserName()) == 0 && strcmp(pass, users[i].getPassword()) == 0)
		{
			std::cout << "Welcome: " << name;
			curr = users[i];
			return;

		}
	}
 
	std::cout << "Wrong username or password. Try again!" << std::endl;
	return;
}

void Utility::createDataBaseUser(User& current, Destination& destination)
{
	Destination newDest;
	char* dbFile = new char(strlen(current.getUserName() + 5));
	strcpy_s(dbFile, strlen(current.getUserName()) + 1, current.getUserName());
	dbFile[strlen(current.getUserName())] = '.';
	dbFile[strlen(current.getUserName()) + 1] = 't';
	dbFile[strlen(current.getUserName()) + 2] = 'x';
	dbFile[strlen(current.getUserName()) + 3] = 't';
	dbFile[strlen(current.getUserName()) + 4] = '\0';

	std::ofstream file;
	std::ifstream in("destination.txt");
	file.open(dbFile, std::ios::app);
	if (file.is_open())
	{
		newDest = destination;
		file << newDest;
		file.close();
	}
}

void Utility::print(Vector<Destination>& dest)
{
	for (size_t i = 0; i < dest.length(); i++)
	{
		std::cout << "Destination: ";
		std::cout << dest[i].getDestination() << std::endl;
		std::cout << "Date: "<<  std::endl;
		std::cout << dest[i].getTime();
		std::cout << "Grade: " << dest[i].getGrade() << std::endl;
		std::cout << "Comment: " << dest[i].getComment() << std::endl;
	}
}