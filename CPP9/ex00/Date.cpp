/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:18:19 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/14 13:04:55 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : year(0), month(0), day(0) {}

Date::Date(int year, int month, int day)
	: year(year), month(month), day(day) {}

Date::Date(std::string &str) : year(0), month(0), day(0)
{
	if (!Date::isValidDateFormat(str))
		throw InvalidDateFormat(str);

	year = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 2).c_str());
	day = std::atoi(str.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
		throw InvalidDate(str);
}

Date::Date(const Date &other)
{
	*this = other;
}

Date &Date::operator=(const Date &other)
{
	if (this != &other)
	{
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
	}
	return *this;
}

Date::~Date() {}

int Date::getYear(void) const { return year; }
int Date::getMonth(void) const { return month; }
int Date::getDay(void) const { return day; }

bool Date::operator==(const Date &other) const
{
	return this->year == other.year
		&& this->month == other.month
		&& this->day == other.day;
}

bool Date::operator!=(const Date &other) const
{
	return this->year != other.year
		|| this->month != other.month
		|| this->day != other.day;
}

bool Date::operator<(const Date &other) const
{
	if (this->year != other.year)
		return this->year < other.year;
	if (this->month != other.month)
		return this->month < other.month;
	return this->day < other.day;
}

bool Date::operator>(const Date &other) const
{
	if (this->year != other.year)
		return this->year > other.year;
	if (this->month != other.month)
		return this->month > other.month;
	return this->day > other.day;
}

bool Date::operator<=(const Date &other) const
{
	if (this->year != other.year)
		return this->year < other.year;
	if (this->month != other.month)
		return this->month < other.month;
	return this->day <= other.day;
}

bool Date::operator>=(const Date &other) const
{
	if (this->year != other.year)
		return this->year > other.year;
	if (this->month != other.month)
		return this->month > other.month;
	return this->day >= other.day;
}

Date &Date::operator++()
{
	day++;
	if (day > daysInMonth(month, year))
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	return *this;
}

Date &Date::operator--()
{
	day--;
	if (day < 1)
	{
		month--;
		if (month < 1)
		{
			month = 12;
			year--;
		}
		day = daysInMonth(month, year);
	}
	return *this;
}

bool Date::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year)
{
	static const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		return 29;
	return daysPerMonth[month - 1];
}

bool Date::isValidDateFormat(std::string &str)
{
	if (str.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				return false;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}

	return true;
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
	os << std::setfill('0')
		<< std::setw(4) << date.getYear() << "-"
		<< std::setw(2) << date.getMonth() << "-"
		<< std::setw(2) << date.getDay();
	return os;
}

Date::InvalidDateFormat::InvalidDateFormat(const std::string input) : msg("Invalid Date Format: " + input) {}

Date::InvalidDateFormat::~InvalidDateFormat() throw() {}

const char *Date::InvalidDateFormat::what() const throw()
{
	return this->msg.c_str();
}

Date::InvalidDate::InvalidDate(const std::string input) : msg("Invalid Date: " + input) {}

Date::InvalidDate::~InvalidDate() throw() {}

const char *Date::InvalidDate::what() const throw()
{
	return this->msg.c_str();
}
