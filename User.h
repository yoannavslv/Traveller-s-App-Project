#pragma once
#include<iostream>
#include "Vector.h"
#include "Destination.h"

class User
{
private:
	char* userName;
	char* password;
	char* email;
	Vector<Destination> personalDestinations;

	void copy(const User& other);
	void destroy();

public:
	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();
	User(const char* newUserName, const char* newPassword, const char* newEmail, Vector<Destination> newPersonalDestinations);
	User(const char* newUserName, const char* newPassword, const char* newEmail);
	

	void setUserName(const char* newUsername);
	const char* getUserName() const;

	void setPassword(const char* newPassword);
	const char* getPassword() const;

	void setEmail(const char* newEmail);
	const char* getEmail() const;

	friend std::ostream& operator<<(std::ostream& out, const User& current);
	friend std::istream& operator>>(std::istream& in, User& current);

};


