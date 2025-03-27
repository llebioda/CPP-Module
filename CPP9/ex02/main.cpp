/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:06:32 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 09:46:53 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <vector>
#include "PmergeMe.hpp"

std::string& strTrimWhitespace(std::string str)
{
	str = str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	return str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
}

bool isPositiveNumber(std::string &str)
{
	if (str.empty())
		return false;

	size_t i = 0;
	if (str[0] == '+')
		i++;

	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool doOverflow(std::string &str)
{
	if (str[0] == '+')
		str.erase(0, 1);
	while (str[0] == '0' && str.length() > 1)
		str.erase(0, 1);
	if (str.length() < 10)
		return false;
	if (str.length() > 10 || str > "2147483647")
		return true;
	return false;
}

void printVector(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << vec[i];
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "usage: " << argv[0] << " nb1 nb2 nb3 ... nbn" << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	for (int i = 1; i < argc; i++)
	{
		std::string str = strTrimWhitespace(argv[i]);
		if (!isPositiveNumber(str))
		{
			std::cerr << "\033[0;31mError: \033[0;37m" << argv[i] << "\033[0;31m is not a positive integer\033[m" << std::endl;
			return 1;
		}

		if (doOverflow(str))
		{
			std::cerr << "\033[0;31mError: \033[0;37m" << argv[i] << "\033[0;31m is too large\033[m" << std::endl;
			return 1;
		}

		numbers.push_back(std::atoi(argv[i]));
	}

	std::cout << "Before: ";
	printVector(numbers);

	double microseconds = PmergeMe::sortAndCalculateTime(numbers);

	std::cout << "After: ";
	printVector(numbers);

	std::cout << "Time to process a range of " << std::fixed << std::setprecision(4) << std::noshowpoint << (argc - 1) << " elements with std::vector : " << microseconds << "µs" << std::endl;

	std::deque<int> dequeNumbers(numbers.begin(), numbers.end());
	microseconds = PmergeMe::sortAndCalculateTime(dequeNumbers);

	std::cout << "Time to process a range of " << std::fixed << std::setprecision(4) << std::noshowpoint << (argc - 1) << " elements with std::deque : " << microseconds << "µs" << std::endl;

	return 0;
}