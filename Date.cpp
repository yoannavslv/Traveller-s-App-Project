#include "Date.h"
#include"Utility.h"

Date::Date()
{
	this->setStartDay(1);
	this->setStartMonth(1);
	this->setStartYear(1970);
	this->setEndDay(2);
	this->setEndMonth(1);
	this->setEndYear(1970);
}

Date::Date(size_t newStartDay, size_t newStartMonth, size_t newStartYear, size_t newEndDay, size_t newEndMonth, size_t newEndYear)
{
	this->setStartDay(newStartDay);
	this->setStartMonth(newStartMonth);
	this->setStartYear(newStartYear);
	this->setEndDay(newEndDay);
	this->setEndMonth(newEndMonth);
	this->setEndYear(newEndYear);
}

Date& Date::operator=(const Date& other)
{
	this->setStartDay(other.startDay);
	this->setStartMonth(other.startMonth);
	this->setStartYear(other.startYear);
	this->setEndDay(other.endDay);
	this->setEndMonth(other.endMonth);
	this->setEndYear(other.endYear);
	return *this;
}

void Date::setStartDay(size_t newStartDay)
{
	this->startDay = newStartDay;
}

size_t Date::getStartDay() const
{
	return this->startDay;
}

void Date::setStartMonth(size_t newStartMonth)
{
	this->startMonth = newStartMonth;
}

size_t Date::getStartMonth() const
{
	return this->startMonth;
}

void Date::setStartYear(size_t newStartYear)
{
	this->startYear = newStartYear;
}

size_t Date::getStartYear() const
{
	return this->startYear;
}

void Date::setEndDay(size_t newEndDay)
{
	this->endDay = newEndDay;
}

size_t Date::getEndDay() const
{
	return this->endDay;
}

void Date::setEndMonth(size_t newEndMonth)
{
	this->endMonth = newEndMonth;
}

size_t Date::getEndMonth() const
{
	return this->endMonth;
}

void Date::setEndYear(size_t newEndYear)
{
	this->endYear = newEndYear;
}

size_t Date::getEndYear() const
{
	return this->endYear;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if (date.startYear < date.endYear)
	{
		
		if (date.startDay < 10)
		{
			out << 0;
		}
		out << date.startDay << '.';
		if (date.startMonth < 10)
		{
			out << 0;
		}
		out << date.startMonth << '.' << date.startYear << std::endl;
		
		if (date.endDay < 10)
		{
			out << 0;
		}
		out << date.endDay << '.';
		if (date.endMonth < 10)
		{
			out << 0;
		}
		out << date.endMonth << '.' << date.endYear << std::endl;
	}
	if (date.startYear == date.endYear)
	{
		if (date.startMonth < date.endMonth)
		{
			
			if (date.startDay < 10)
			{
				out << 0;
			}
			out << date.startDay << '.';
			if (date.startMonth < 10)
			{
				out << 0;
			}
			out << date.startMonth << '.' << date.startYear << std::endl;
			
			if (date.endDay < 10)
			{
				out << 0;
			}
			out << date.endDay << '.';
			if (date.endMonth < 10)
			{
				out << 0;
			}
			out << date.endMonth << '.' << date.endYear << std::endl;
		}
		if (date.startMonth > date.endMonth)
		{
			std::cout << "Invalid date. Try again!" << std::endl;
		}
		if (date.startMonth == date.endMonth)
		{
			if (date.startDay < date.endDay)
			{
				
				if (date.startDay < 10)
				{
					out << 0;
				}
				out << date.startDay << '.';
				if (date.startMonth < 10)
				{
					out << 0;
				}
				out << date.startMonth << '.' << date.startYear << std::endl;
				
				if (date.endDay < 10)
				{
					out << 0;
				}
				out << date.endDay << '.';
				if (date.endMonth < 10)
				{
					out << 0;
				}
				out << date.endMonth << '.' << date.endYear << std::endl;
			}
			if (date.startDay > date.endDay)
			{
				std::cout << "Invalid date. Try again!" << std::endl;
			}
			if (date.startDay == date.endDay)
			{
				std::cout << "Invalid date. Try again!" << std::endl;
			}
		}
	}
	if (date.startYear > date.endYear)
	{
		std::cout << "Invalid date. Try again!" << std::endl;
	}

	return out;

}
std::istream& operator>>(std::istream& in, Date& date)
{
	in >> date.startDay;
	in.ignore();
	in >> date.startMonth;
	in.ignore(); 
	in >> date.startYear;
	in >> date.endDay;
	in.ignore(); 
	in >> date.endMonth;
	in.ignore();
	in >> date.endYear;
	return in;
}