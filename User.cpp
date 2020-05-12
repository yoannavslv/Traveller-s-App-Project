#include "User.h"

void User::copy(const User& other)
{
	this->setUserName(other.userName);
	this->setPassword(other.password);
	this->setEmail(other.email);
}

void User::destroy()
{
	delete[] this->userName;
	delete[] this->password;
	delete[] this->email;
}

User::User()
{
	this->setUserName("Unknown");
	this->setPassword("Default");
	this->setEmail("Unknown");
}

User::User(const User& other)
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
	destroy();
}

User::User(const char* newUserName, const char* newPassword, const char* newEmail) : userName(nullptr), password(nullptr), email(nullptr)
{
	this->setUserName(newUserName);
	this->setPassword(newPassword);
	this->setEmail(newEmail);
}

void User::setUserName(const char* newUsername)
{
	if (newUsername != NULL)
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
	if (newPassword != NULL)
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
	if (newEmail != NULL)
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
	out << "Username: " << current.userName << std::endl
		<< "Password: " << current.password << std::endl
		<< "Email: " << current.email << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, User& current)
{
	std::cout << "Username: ";
	in.get();
	in.getline(current.userName, 128);

	std::cout << "Password: ";
	in.get();
	in.getline(current.password, 128);

	std::cout << "Email: ";
	in.get();
	in.getline(current.email, 128);

	return in;
}
