/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:13:03 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/14 13:04:49 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data(std::map<Date, float>()) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(std::string dataFilename)
{
	std::ifstream file(dataFilename.c_str());
	if (!file)
		throw std::invalid_argument("Unable to load file: " + dataFilename);

	std::string line;
	if (!std::getline(file, line))
	{
		file.close();
		throw std::runtime_error("Empty file: " + dataFilename);
	}

	while (std::getline(file, line))
	{
		std::string::size_type pos = line.find(",");
		if (pos == std::string::npos || pos == 0 || pos == line.size() - 1)
			throw std::runtime_error("Invalid input: " + line);

		std::string dateStr = line.substr(0, pos);
		if (!Date::isValidDateFormat(dateStr))
			throw std::runtime_error("Invalid date format: " + dateStr);

		Date date(dateStr);
		double value = BitcoinExchange::getDoubleValue(line.substr(pos + 1));
		data[date] = value;
	}

	file.close();
}

double BitcoinExchange::getExchangeRate(const Date &date) const
{
	std::map<Date, float>::const_iterator it = data.find(date);

    if (it == data.end() && it->first != date)
    {
        it = data.lower_bound(date);
        if (it == data.begin())
            throw std::runtime_error("No exchange rate available for the given date or any earlier date.");
		--it;
    }
    return it->second;
}

double BitcoinExchange::getDoubleValue(const std::string& str)
{
	double value;

	std::istringstream iss(str);
	iss >> value;
	if (!iss.eof() || iss.fail())
		throw std::invalid_argument("Invalid value: " + str);

	if (value < 0)
		throw std::invalid_argument("Value is negative: " + str);

	return value;
}
