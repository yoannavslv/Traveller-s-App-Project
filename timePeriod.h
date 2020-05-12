#pragma once
#include <iostream>

struct Date
{
private:
	size_t day, month, year;

public:
	Date();
	Date(size_t newDay, size_t newMonth, size_t newYear);
	Date& operator=(const Date& other);

	void setDay(size_t newDay);
	size_t getDay() const;

	void setMonth(size_t newMonth);
	size_t getMonth() const;

	void setYear(size_t newYear);
	size_t getYear() const;

	friend std::ostream& operator<<(std::ostream& out, const Date& date);

};
