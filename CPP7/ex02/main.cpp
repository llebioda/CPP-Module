/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:33:23 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 11:26:38 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define INT_NB 5

int main()
{
	std::srand(std::time(NULL));

	{
		Array<int> arr1;
		std::cout << arr1.size() << std::endl;

		Array<size_t> arr2(INT_NB);
		std::cout << arr2.size() << std::endl;
	}

	// try
	// {
	// 	Array<size_t> arr3(-1);
	// 	std::cout << arr3.size() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	std::cout << std::endl;

	{
		Array<int> arr1(INT_NB);
		for (int i = 0; i < INT_NB; i++)
			arr1[i] = std::rand() % 256;
		std::cout << "arr1 > " << arr1.size() << " : " << arr1 << std::endl;

		Array<int> arr2 = arr1;
		std::cout << "arr2 > " << arr2.size() << " : " << arr2 << std::endl;
		for (int i = 0; i < INT_NB; i++)
			arr2[i] = arr2[i] * 2;
		std::cout << "arr2 > " << arr2.size() << " : " << arr2 << std::endl;
		std::cout << "arr1 > " << arr1.size() << " : " << arr1 << std::endl;

		Array<int> arr3;
		arr3 = arr1;
		std::cout << "arr3 > " << arr3.size() << " : " << arr3 << std::endl;
		arr3 = arr2;
		std::cout << "arr3 > " << arr3.size() << " : " << arr3 << std::endl;

		std::cout << std::endl;
	}

	{
		Array<int> arr(INT_NB);
		for (int i = 0; i < INT_NB; i++)
			arr[i] = i;
		std::cout << "arr > " << arr.size() << " : " << arr << std::endl;

		const Array<int> constArr = arr;
		std::cout << "constArr > " << constArr.size() << " : " << constArr << std::endl;

		for (int i = 0; i < INT_NB; i++)
			arr[i] = i * 4;
		std::cout << "arr > " << arr.size() << " : " << arr << std::endl;

		int sum = 0;
		for (int i = 0; i < INT_NB; i++)
			sum += constArr[i];
		std::cout << "sum = " << sum << std::endl;

		std::cout << std::endl;
	}

	Array<int> arr(2);
	arr[0] = 0;
	arr[1] = 5;
	std::cout << arr.size() << " : " << arr << std::endl;
	arr[-1] = -64;
	std::cout << arr.size() << " : " << arr << std::endl;
	arr[-2]++;
	std::cout << arr.size() << " : " << arr << std::endl;

	std::cout << std::endl;

	try
	{
		arr[42] = 42;
		std::cout << "\033[0;31mError 1 should have been catched\033[m" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error 1 catched : " << e.what() << std::endl;
	}

	try
	{
		arr[2] = -456;
		std::cout << "\033[0;31mError 2 should have been catched\033[m" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error 2 catched : " << e.what() << std::endl;
	}

	try
	{
		arr[-3] = 949;
		std::cout << "\033[0;31mError 3 should have been catched\033[m" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error 3 catched : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
