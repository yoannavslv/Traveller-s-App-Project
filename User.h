#pragma once
#include<iostream>
#include "Vector.h"
#include "Destination.h"

class User
{
private:
	//data
	char* userName;
	char* password;
	char* email;

	void copy(const User& other);
	void destroy();

public:
	//constructors
	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();
	User(const char* newUserName, const char* newPassword, const char* newEmail);
	
	//setters and getters
	void setUserName(const char* newUsername);
	const char* getUserName() const;

	void setPassword(const char* newPassword);
	const char* getPassword() const;

	void setEmail(const char* newEmail);
	const char* getEmail() const;

	//operators for input and output
	friend std::ostream& operator<<(std::ostream& out, const User& current);
	friend std::istream& operator>>(std::istream& in, User& current);
};


