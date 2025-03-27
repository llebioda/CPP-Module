/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:02:43 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 16:45:11 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	std::srand(std::time(NULL));

	{
		Span sp = Span(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		sp.addNumber(2147483647);
		sp.addNumber(-2147483648);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		Span emptySpan;
		emptySpan.addNumber(42);
		std::cout << "error error error error error" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span emptySpan;
		long v = emptySpan.longestSpan();
		std::cout << "the longest span is " << v << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	{
		Span span(5);

		std::cout << span << std::endl;

		try
		{
			long v = span.shortestSpan();
			std::cout << "the shortest span is " << v << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;

		for (int i = 0; i < 8; i++)
		{
			try
			{
				span.addNumber(i);
				std::cout << "added " << i << " to span" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		std::cout << span << std::endl;

		std::cout << std::endl;

		try
		{
			long v = span.shortestSpan();
			std::cout << "the shortest span is " << v << std::endl;
			v = span.longestSpan();
			std::cout << "the longest span is " << v << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	{
		Span span(100000);

		try
		{
			while (true)
				span.addNumber(std::rand());
		}
		catch(const std::exception& e)
		{
			std::cout << "span filled" << std::endl;
		}

		//std::cout << span << std::endl;

		try
		{
			long v = span.shortestSpan();
			std::cout << "the shortest span is " << v << std::endl;
			v = span.longestSpan();
			std::cout << "the longest span is " << v << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
	}

	{
		Span span(10);
        span.addNumber(6);
        span.addNumber(3);

		std::cout << span << std::endl;

		long v = span.shortestSpan();
		std::cout << "the shortest span is " << v << std::endl;
		v = span.longestSpan();
		std::cout << "the longest span is " << v << std::endl;

		std::cout << std::endl;

        std::vector<int> numbers(0);
		numbers.push_back(176);
		numbers.push_back(6415);
		numbers.push_back(31);
		numbers.push_back(-566);
		numbers.push_back(0);
        span.addRange(numbers);

		std::cout << span << std::endl;

		v = span.shortestSpan();
		std::cout << "the shortest span is " << v << std::endl;
		v = span.longestSpan();
		std::cout << "the longest span is " << v << std::endl;
	}

	return 0;
}
