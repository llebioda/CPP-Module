/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:12:51 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/13 16:21:38 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float> data;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadData(std::string dataFilename);
		double getExchangeRate(const Date &date) const;
		static double getDoubleValue(const std::string& str);
};
