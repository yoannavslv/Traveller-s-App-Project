#include "User.h"
#include<fstream>

void User::copy(const User& other)
{
	this->setUserName(other.userName);
	this->setPassword(other.password);
	this->setEmail(other.email);
}


User::User() : userName(nullptr), password(nullptr), email(nullptr)
{
	this->setUserName("Unknown");
	this->setPassword("Default");
	this->setEmail("Unknown");
}

User::User(const User& other) : userName(nullptr), password(nullptr), email(nullptr)
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

User::~User()
{
	delete[] this->userName;
	//delete[] this->password;
	delete[] this->email;
}

User::User(const char* newUserName, const char* newPassword, const char* newEmail) : userName(nullptr), password(nullptr), email(nullptr)
{
	this->setUserName(newUserName);
	this->setPassword(newPassword);
	this->setEmail(newEmail);
}

void User::setUserName(const char* newUsername)
{
	if (newUsername != nullptr)
	{
		delete[] this->userName;
		this->userName = new char[strlen(newUsername) + 1];
		strcpy_s(this->userName, strlen(newUsername) + 1, newUsername);
	}
}

const char* User::getUserName() const
{
	return this->userName;
}

void User::setPassword(const char* newPassword)
{
	if (newPassword != nullptr)
	{
		delete[] this->password;
		this->password = new char[strlen(newPassword) + 1];
		strcpy_s(this->password, strlen(newPassword) + 1, newPassword);
	}
}

const char* User::getPassword() const
{
	return this->password;
}

void User::setEmail(const char* newEmail)
{
	if (newEmail != nullptr)
	{
		delete[] this->email;
		this->email = new char[strlen(newEmail) + 1];
		strcpy_s(this->email, strlen(newEmail) + 1, newEmail);
	}
}

const char* User::getEmail() const
{
	return this->email;
}

std::ostream& operator<<(std::ostream& out, const User& current)
{
	out << current.userName << std::endl
		<< current.password << std::endl
		<< current.email << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, User& current)
{
	char text[128];
	in >> text;
	current.setUserName(text);
	in >> text;
	current.setPassword(text);
	in >> text;
	current.setEmail(text);

	return in;
}
