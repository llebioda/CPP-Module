/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:02:11 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 15:21:11 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i);

	for (int i = -2; i < 8; i++)
	{
		try
		{
			int v = easyfind(vec, i);
			std::cout << "Element found in vector: " << v << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 7; i++)
		lst.push_front(i);

	for (int i = -2; i < 10; i++)
	{
		try
		{
			int v = easyfind(lst, i);
			std::cout << "Element found in list: " << v << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::vector<long> vec2;
	for (long i = -3; i < 10; i += 2)
		vec2.push_back(i);

	for (long i = -5; i < 13; i++)
	{
		try
		{
			long v = easyfind(vec2, i);
			std::cout << "Element found in vector: " << v << std::endl;
		}
		catch (const NotFoundException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	return 0;
}
