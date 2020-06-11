#include <iostream>
#include "Utility.h"
#include<string>
#include <fstream>

char command[5][18] = { "registration", "login", "friendsList", "averageGrades", "destinationsList"};

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
	std::ifstream file;
	file.open("destination.txt", std::ios::app);
	Destination curr;
	if (file.is_open())
	{
		destinations.push_back(curr);
	}
	/*
	while (dest >> curr)
	{
		destinations.push_back(curr);
	}*/
	file.close();
	return destinations;
}

/*
Vector<Destination> Utility::open(char* path)
{
	Vector<Destination> destination;
	std::ifstream file(path);
	Destination current;
	while (file >> current)
	{
		destination.push_back(current);
	}
	file.close();
	return destination;
}
*/
size_t Utility::checkTheOperation(char* text)
{
	Vector<char*> part = split(text);
	for (size_t i = 0; i < 5; i++)
	{
		if (strcmp(part[0], command[i]) == 0)
		{
			return i + 1;
		}
	}
	return -1;
}
/*
void Utility::save(char* fileName, Vector<Destination>& destinations)
{
	std::ofstream file(fileName);
	for (size_t i = 0; i < destinations.length(); i++)
	{
		file << destinations[i];
	}
	file.close();
}
*/
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
	std::string buff;
	if (file.is_open())
	{
		while (getline(in, buff))
		{
			newDest = destination;
			file << newDest;
		}
		file.close();
	}
	else
	{
		std::cout << "unable to open file";
	}
}

void Utility::print(Vector<Destination> dest)
{
	for (size_t i = 0; i < dest.length(); i++)
	{
		std::cout << "Destination: " << dest[i].getDestination() << std::endl;
		std::cout << "Date: " << dest[i].getTime() << std::endl;
		std::cout << "Grade: " << dest[i].getGrade() << std::endl;
		std::cout << "Comment: " << dest[i].getComment() << std::endl;
	}
}

/*
void Utility::addFriend(const User& cuurent, Vector<User> friends)
{
	friends.push_back(cuurent);
}

/*
bool Utility::wasVisited(Destination& current, Vector<User> friends, Vector<Destination> newPersonalDestinations)
{
	for (size_t user = 0; user < friends.length(); user++)
	{
		for (size_t destinations = 0; destinations < friends[user].newPersonalDestinations.length(); destinations++)
		{
			if (current == friends[user].[destinations])
			{
				std::cout << "User: " << friends[user].userName << std::endl;
				std::cout << "Comment: " << friends[user].visited[destinations].getComment() << std::endl;
				std::cout << "Grade: " << friends[user].visited[destinations].getGrade();
			}
		}
	}
}
*/