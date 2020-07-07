#pragma once
#include"Destination.h"
#include"User.h"
#include"Vector.h"
#include<fstream>

class Utility
{
public:
	static size_t numberOfSymbols(char* text, char symbol); //returns the number of how many times a symbol is in a char 
	static char* substring(char* text, int firstPosition, int secondPosition); //returns a part of char between two or more given indexes
	static size_t index(char* text, char symbol); //returns the first inedx of symbol in char
	static size_t theLastIndex(char* text, char symbol);  //returns the last index of symbol in char
	static Vector<char*> split(char* text); //split char by space

	static Vector<User> fillUsers(); //fills the vector with users
	static Vector<Destination> fillDestination(); //fills the vector with destinations
	static size_t checkTheOperation(char* text); //check if the given command is valid
	static void saveUser(Vector<User>& users); //save users in file
	static void saveDestination(Vector<Destination>& destination); //save destinations in file
	static void login(char* name, char* pass, Vector<User> users, User curr); //check if a user is registrated
	static void createDataBaseUser(User& current,Destination& destination); //creates personal file for the user who is registrating
	static void print(Vector<Destination>& dest); //prints all of the destinations
};

