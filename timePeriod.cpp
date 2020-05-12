#include "timePeriod.h"
#include"HelpFunctions.h"

Date::Date()
{
	this->setDay(1);
	this->setMonth(1);
	this->setYear(1970);
}

Date::Date(size_t newDay, size_t newMonth, size_t newYear)
{
	this->setDay(newDay);
	this->setMonth(newMonth);
	this->setYear(newYear);
}

Date& Date::operator=(const Date& other)
{
	this->setDay(other.day);
	this->setMonth(other.month);
	this->setYear(other.year);
	return *this;
}

void Date::setDay(size_t newDay)
{
	this->day = newDay;
}

size_t Date::getDay() const
{
	return this->day;
}

void Date::setMonth(size_t newMonth)
{
	this->month = newMonth;
}

size_t Date::getMonth() const
{
	return this->month;
}

void Date::setYear(size_t newYear)
{
	this->year = newYear;
}

size_t Date::getYear() const
{
	return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if (date.day < 10)
	{
		out << 0;
	}
	out << date.day << '.';
	if (date.month < 10)
	{
		out << 0;
	}
	out << date.month << '.' << date.year << std::endl;
	return out;

}

size_t charToInt(char* text)
{
	size_t sum = 0;
	for (size_t i = 0; i < strlen(text); i++)
	{
		sum += (text[i] - '0');
		sum *= 10;
	}
	return sum / 10;
}


