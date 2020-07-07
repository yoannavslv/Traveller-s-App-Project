#include "Destination.h"

void Destination::copy(const Destination& other)
{
	this->setDestination(other.destination);
	this->setTime(other.time);
	this->setGrade(other.grade);
	this->setComment(other.comment);

}

Destination::Destination() : destination(nullptr), comment(nullptr)
{
	this->setDestination("Default");
	this->setGrade(1);
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
	//delete[] this->destination;
	//delete[] this->comment;
}

Destination::Destination(const char* newDestination, Date newTime, int newGrade, const char* newComment) : destination(nullptr), comment(nullptr)
{
	this->setDestination(newDestination);
	this->setTime(newTime);
	this->setGrade(newGrade);
	this->setComment(newComment);
}

void Destination::setDestination(const char* newDestination)
{
	if (newDestination != nullptr)
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
	if (newComment != nullptr)
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

void Destination::setTime(Date newTime)
{
	this->time = newTime;
}

Date Destination::getTime() const
{
	return this->time;
}

std::ostream& operator<<(std::ostream& out, const Destination& current)
{
	out << current.destination << std::endl;
	out << current.time;
	out << current.grade << std::endl;
	out << current.comment << std::endl;
	
	return out;
}

std::istream& operator>>(std::istream& in, Destination& current)
{
	char txt[48];
	in >> txt;
	current.setDestination(txt);

	in >> current.time;
	
	in >> current.grade;

	in.get();
	in.getline(txt, 48);
	current.setComment(txt);

	return in;
}
