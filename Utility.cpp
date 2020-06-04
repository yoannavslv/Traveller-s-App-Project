#include "Utility.h"
#include<cstring>
#include <iostream>
#include"Vector.h"
#include"User.h"
#include <fstream>

char command[5][18] = { "registration", "login", "friendsList", "averageGrades", "destinationsList"};

Vector<User> fillUsers()
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
	file.open("destinations.txt", std::ios::app);
	Destination curr;
	char buff[20];
	if (file.is_open())
	{
		Destination current("Tailand", Date(2, 3, 2019, 5, 3, 2019), 4, "mn qko");
		destinations.push_back(current);
	}
	file.close();
	return destinations;
}

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

void Utility::save(char* fileName, Vector<Destination>& destinations)
{
	std::ofstream file(fileName);
	for (size_t i = 0; i < destinations.length(); i++)
	{
		file << destinations[i];
	}
	file.close();
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
	std::ofstream file("destinations.txt");
	for (size_t i = 0; i < destination.length(); i++)
	{
		file << destination[i];
	}
	file.close();
}

int Utility::averageGrade()
{
	return 0;
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

	file.open(dbFile, std::ios::app);
		char buff[20];
	if (file.is_open())
	{
		newDest = destination;
		//Destination current("Tailand", Date(2, 3, 2019, 5, 3, 2019), 4, "mn qko");
		file << newDest;
	}
	
	file.close();
}

/*
void Utility::addFriend(const User& cuurent, Vector<User> friends)
{
	friends.push_back(cuurent);
}

bool Utility::wasVisited(Destination& current, Vector<User> friends)
{
	for (size_t user = 0; user < friends.length(); user++)
	{
		for (size_t destinations = 0; destinations < friends[user].visited.length(); destinations++)
		{
			if (current == friends[user].visited[destinations])
			{
				std::cout << "User: " << friends[user].userName << std::endl;
				std::cout << "Comment: " << friends[user].visited[destinations].getComment() << std::endl;
				std::cout << "Grade: " << friends[user].visited[destinations].getGrade();
			}
		}
	}
}
*/