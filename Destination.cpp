#include "Destination.h"

void Destination::copy(const Destination& other)
{
	this->setDestination(other.destination);
	this->setGrade(other.grade);
	this->setComment(other.comment);
}

void Destination::destroy()
{
	delete[] this->destination;
	delete[] this->comment;
}

Destination::Destination()
{
	this->setDestination("Default");
	this->setGrade(0);
	this->setComment("Default");
}

Destination::Destination(const Destination& other)
{
	copy(other);
}

Destination& Destination::operator=(const Destination& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Destination::~Destination()
{
	destroy();
}

Destination::Destination(const char* newDestination, Date newTime, int newGrade, const char* newComment)
{
	this->setDestination(newDestination);
	this->setGrade(newGrade);
	this->setComment(newComment);
}

void Destination::setDestination(const char* newDestination)
{
	if (newDestination != NULL)
	{
		delete[] this->destination;
		this->destination = new char[strlen(newDestination) + 1];
		strcpy_s(this->destination, strlen(newDestination) + 1, newDestination);
	}
}

const char* Destination::getDestination() const
{
	return this->destination;
}

void Destination::setGrade(int newGrade)
{
	this->grade = newGrade;
}

int Destination::getGrade() const
{
	return this->grade;
}

void Destination::setComment(const char* newComment)
{
	if (newComment != NULL)
	{
		delete[] this->comment;
		this->comment = new char[strlen(newComment) + 1];
		strcpy_s(this->comment, strlen(newComment) + 1, newComment);
	}
}

const char* Destination::getComment() const
{
	return this->comment;
}
