/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:59:04 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:15 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of str : " << &str << std::endl;
	std::cout << "Address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Address held by stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl;

	return 0;
}
