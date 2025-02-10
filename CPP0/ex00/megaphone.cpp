/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:15:35 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/23 23:30:07 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];

			for (size_t j = 0; j < str.length(); j++)
			{
				str[j] = std::toupper(str[j]);
			}

			if (i > 1)
				std::cout << " ";

			std::cout << str;
		}

		std::cout << std::endl;
	}
	return 0;
}
