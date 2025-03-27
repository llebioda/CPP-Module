/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:31:14 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 10:20:55 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "usage: " << argv[0] << " \"[EXPRESSION]\"" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << std::endl;

		try
		{
			double result = RPN::eval(argv[i]);
			std::cout << result << std::endl;
		}
		catch(const RPN::InvalidExpression& e)
		{
			std::cerr << "\033[0;31mError: " << e.what() << "\033[m" << std::endl;
			int errorIndex = e.getErrorIndex();
			if (errorIndex >= 0)
			{
				std::cerr << argv[i] << std::endl;
				for (int j = 0; j < errorIndex; j++)
					std::cerr << " ";
				std::cerr << "\033[0;95m^\033[m" << std::endl;
			}
		}
	}

	return 0;
}
