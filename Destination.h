#pragma once
#include<iostream>
#include"Vector.h"
#include "Date.h"

class Destination
{
private:

	char* destination;
	Date time;
	int grade;
	char* comment;
	//Vector<char*> photos;

	void copy(const Destination& other);

public:
	Destination();
	Destination(const Destination& other);
	Destination& operator=(const Destination& other);
	~Destination();
	Destination(const char* newDestination, Date newTime, int newGrade, const char* newComment);

	void setDestination(const char* newDestination);
	const char* getDestination() const;

	void setGrade(int newGrade);
	int getGrade() const;

	void setComment(const char* newComment);
	const char* getComment() const;

	void setTime(Date newTime);
	Date getTime() const;

	bool operator==(const Destination& another);

	friend std::ostream& operator<<(std::ostream& out, const Destination& current);
	friend std::istream& operator>>(std::istream& in, Destination& current);
};


