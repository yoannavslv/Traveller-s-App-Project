#pragma once
#include"timePeriod.h"
#include"User.h"
#include"Vector.h"

class Destination
{
private:

	char* destination;
	Date time;
	int grade;
	char* comment;
	Vector<User> attendedUser;
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
};

