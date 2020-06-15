#pragma once
#include <iostream>
class Date
{
private:
	//data
	size_t startDay, startMonth, startYear, endDay, endMonth, endYear;

public:
	//constructors
	Date();
	Date(size_t newStartDay, size_t newStartMonth, size_t newStartYear, size_t newEndDay, size_t newEndMonth, size_t newEndYear);
	Date& operator=(const Date& other);

	//setters and getters
	void setStartDay(size_t newStartDay);
	size_t getStartDay() const;

	void setStartMonth(size_t newStartMonth);
	size_t getStartMonth() const;

	void setStartYear(size_t newStartYear);
	size_t getStartYear() const;

	void setEndDay(size_t newEndDay);
	size_t getEndDay() const;

	void setEndMonth(size_t newEndMonth);
	size_t getEndMonth() const;

	void setEndYear(size_t newEndYear);
	size_t getEndYear() const;

	//operators for input and output
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>>(std::istream& in, Date& date);
};

