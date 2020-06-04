#pragma once
#include"Date.h"
#include"User.h"
#include"Vector.h"
#include<iostream>

class Destination
{
private:

	char* destination;
	Date time;
	int grade;
	char* comment;
	Vector<char*> photos;

	void copy(const Destination& other);
	void destroy();

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
	void print(Vector<Destination> dest);

	friend std::ostream& operator<<(std::ostream& out, const Destination& current);
	friend std::istream& operator>>(std::istream& in, Destination& current);
};


