/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:41 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 13:20:53 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Serializer.hpp"

void printData(Data *data)
{
	if (data == NULL)
	{
		std::cout << "null" << std::endl;
		return;
	}

	std::cout << "x = " << data->x << ", y = " << data->y << std::endl;
	std::cout << "value = " << data->value << std::endl;
	std::cout << "str : [" << data->str << "]" << std::endl << std::endl;
}

int main(void)
{
	//Serializer converter;
	//Serializer converter = Serializer();
	//Serializer converter(Serializer());

	Data *data = new Data();

	printData(data);

	data->x = 42;
	data->y = -42;
	data->value = 4.2;
	data->str = "c++";

	printData(data);

    uintptr_t ptr = Serializer::serialize(data);

	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "hex ptr = " << std::hex << ptr << std::dec << std::endl;

    Data *data2 = Serializer::deserialize(ptr);

	std::cout << "data  = " << data << std::endl;
	std::cout << "data2 = " << data2 << std::endl;
	std::cout << std::endl;

	printData(data2);

	delete data;

	data = NULL;

    ptr = Serializer::serialize(data);

	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "hex ptr = " << std::hex << ptr << std::dec << std::endl;

    data2 = Serializer::deserialize(ptr);

	std::cout << "data  = " << data << std::endl;
	std::cout << "data2 = " << data2 << std::endl;
	std::cout << std::endl;

	return 0;
}
