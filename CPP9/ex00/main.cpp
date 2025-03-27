/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:03:56 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/14 09:36:22 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include "BitcoinExchange.hpp"
#include "Date.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "usage: " << argv[0] << " <filepath>" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cerr << "\033[0;31mError opening file: " << argv[1] << "\033[m" << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange;

	try
	{
		btcExchange.loadData("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[0;31mError: " << e.what() << "\033[m" << std::endl;
		file.close();
		return 1;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::string::size_type pos = line.find(" | ");
		if (pos == std::string::npos || pos == 0 || pos == line.size() - 3)
		{
			std::cerr << "\033[0;31mError: Invalid input: " << line << "\033[m" << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, pos);
		if (!Date::isValidDateFormat(dateStr))
		{
			Date::InvalidDateFormat e(dateStr);
			std::cerr << "\033[0;31mError: " << e.what() << "\033[m" << std::endl;
			continue;
		}

		std::string valueStr = line.substr(pos + 3);
		try
		{
			Date date(dateStr);
			double value = BitcoinExchange::getDoubleValue(valueStr);
			if (value > 1000.0)
				throw std::invalid_argument("Value too large: " + valueStr);
			double exchangeRate = btcExchange.getExchangeRate(date);
			std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[0;31mError: " << e.what() << "\033[m" << std::endl;
		}
	}

	file.close();

	return 0;
}
