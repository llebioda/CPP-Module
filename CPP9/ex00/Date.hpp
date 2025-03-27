/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:17:44 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/14 10:22:36 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <exception>
#include <iostream>
#include <iomanip>
#include <string>

class Date
{
	private:
		int year;
		int month;
		int day;

	public:
		Date(void);
		Date(int year, int month, int day);
		Date(std::string &str);
		Date(const Date &other);
		Date &operator=(const Date &other);
		~Date();

		int getYear(void) const;
		int getMonth(void) const;
		int getDay(void) const;

		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>=(const Date& other) const;

		Date &operator++();
		Date &operator--();

		static bool isLeapYear(int year);
		static int daysInMonth(int month, int year);
		static bool isValidDateFormat(std::string &str);

	class InvalidDateFormat : public std::exception
	{
		private:
			std::string msg;

		public:
			InvalidDateFormat(const std::string input);
			~InvalidDateFormat() throw();
			const char *what() const throw();
	};

	class InvalidDate : public std::exception
	{
		private:
			std::string msg;

		public:
			InvalidDate(const std::string input);
			~InvalidDate() throw();
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Date &date);
