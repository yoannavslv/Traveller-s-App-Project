#include "Destination.h"
#include"Vector.h"
#include"Date.h"

void Destination::copy(const Destination& other)
{
	this->setDestination(other.destination);
	this->setTime(other.time);
	this->setGrade(other.grade);
	this->setComment(other.comment);

}

void Destination::destroy()
{
	delete[] this->destination;
	delete[] this->comment;
}

Destination::Destination() : destination(nullptr), comment(nullptr)
{
	this->setDestination("Default");
	this->setGrade(1);
	this->setComment("Default");
}

Destination::Destination(const Destination& other) : destination(nullptr), comment(nullptr)
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
		//delete[] this->comment;
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

bool Destination::operator==(const Destination& another)
{
	return strcmp(this->destination, another.destination) == 0;
}

void Destination::print(Vector<Destination> dest)
{
	std::cout << "Destination: " << this->getDestination() << std::endl;
	std::cout << "Date: " << this->getTime() << std::endl;
	std::cout << "Grade: " << this->getGrade() << std::endl;
	std::cout << "Comment: " << this->getComment() << std::endl;
	std::cout << "Photos: " << photos << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Destination& current)
{
	out << current.destination << std::endl;
	out << current.time;

	if (current.grade >= 1 && current.grade <= 5)
	{
		out << current.grade << std::endl;
	}
	else
	{
		std::cout << "Invalid grade. Try a grade between 1 and 5!" << std::endl;
	}
	//out << current.grade << std::endl;
	out << current.comment << std::endl;
	out << current.photos;
	return out;
}

std::istream& operator>>(std::istream& in, Destination& current)
{

	in.get();
	in.getline(current.destination, 128);

	in >> current.time;

    in >> current.grade;

	in.get();
	in.getline(current.comment, 128);

	char text[64];
	while (in >> text)
	{
		if (strcmp(text, "EXIT") == 0)
		{
			break;
		}
		else
		{
			current.photos.push_back(text);
		}
	}

	return in;
}
