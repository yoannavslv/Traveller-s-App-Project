#pragma once
#include"Destination.h"
#include"User.h"
#include"Vector.h"
#include<fstream>

class Utility
{
public:
	size_t numberOfSymbols(char* text, char symbol);
	char* substring(char* text, int firstPosition, int secondPosition);
	size_t index(char* text, char symbol);
	size_t theLastIndex(char* text, char symbol);
	Vector<char*> split(char* text);

	Vector<User> fillUsers();
	Vector<Destination> fillDestination();
	//Vector<Destination> open(char* path);
	size_t checkTheOperation(char* text);
	//void save(char* fileName, Vector<Destination>& destinations);
	void saveUser(Vector<User>& users);
	void saveDestination(Vector<Destination>& destination);
	void login(char* name, char* pass, Vector<User> users, User curr);
	void createDataBaseUser(User& current, Destination& destination);
	void print(Vector<Destination> dest);

    void addFriend(const User& cuurent, Vector<User> friends);
	bool wasVisited(Destination& current, Vector<User> friends, Vector<Destination> visited);

};

