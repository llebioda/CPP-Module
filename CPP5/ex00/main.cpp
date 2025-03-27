/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:45 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/13 09:43:10 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat john("John", 140);
	Bureaucrat patrick("Patrick", 65);
	Bureaucrat pdg("PDG", 1);

	std::cout << john << std::endl;
	std::cout << patrick << std::endl;
	std::cout << pdg << std::endl;

	patrick.upGrade();
	std::cout << patrick << std::endl;

	try
	{
		Bureaucrat error1("error1", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat error2("error2", 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat error3("error3", 151);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		for (size_t i = 0; i < 15; i++)
		{
			john.downGrade();
			std::cout << "downGraded : " << john << std::endl;
		}
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		pdg.upGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
