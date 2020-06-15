#pragma once
#include"Destination.h"
#include"User.h"
#include"Vector.h"
#include<fstream>

class Utility
{
public:
	size_t numberOfSymbols(char* text, char symbol); //returns the number of how many times a symbol is in a char 
	char* substring(char* text, int firstPosition, int secondPosition); //returns a part of char between two or more given indexes
	size_t index(char* text, char symbol); //returns the first inedx of symbol in char
	size_t theLastIndex(char* text, char symbol);  //returns the last index of symbol in char
	Vector<char*> split(char* text); //split char by space

	Vector<User> fillUsers(); //fills the vector with users
	Vector<Destination> fillDestination(); //fills the vector with destinations
	size_t checkTheOperation(char* text); //check if the given command is valid
	void saveUser(Vector<User>& users); //save users in file
	void saveDestination(Vector<Destination>& destination); //save destinations in file
	void login(char* name, char* pass, Vector<User> users, User curr); //check if a user is registrated
	void createDataBaseUser(User& current, Destination& destination); //creates personal file for the user who is registrating
	void print(Vector<Destination> dest); //prints all of the destinations
};

