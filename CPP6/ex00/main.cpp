/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:16:07 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 10:16:39 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	//ScalarConverter converter;
	//ScalarConverter converter = ScalarConverter();
	//ScalarConverter converter(ScalarConverter());

	if (argc == 1)
	{
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << std::endl;
    	ScalarConverter::convert(argv[i]);
	}

	return 0;
}
