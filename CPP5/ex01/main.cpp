/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:45 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:12:05 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat john("John", 140);
	Bureaucrat patrick("Patrick", 65);
	Bureaucrat pdg("PDG", 1);

	std::cout << john << std::endl;
	std::cout << patrick << std::endl;
	std::cout << pdg << std::endl;

	std::cout << std::endl;

	try
	{
		Form error1("error1", 0, 5);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form error2("error2", 3, 151);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	Form budgetForm("budget", 64, 130);
	std::cout << budgetForm << std::endl;

	patrick.signForm(budgetForm);
	std::cout << budgetForm << std::endl;

	patrick.upGrade();
	std::cout << patrick << std::endl;

	patrick.signForm(budgetForm);
	std::cout << budgetForm << std::endl;

	std::cout << std::endl;

	Form contratForm("contrat", 5, 130);
	std::cout << contratForm << std::endl;

	patrick.signForm(contratForm);
	john.signForm(contratForm);
	pdg.signForm(contratForm);

	std::cout << contratForm << std::endl;

	pdg.signForm(contratForm);

	std::cout << std::endl;

	return 0;
}
