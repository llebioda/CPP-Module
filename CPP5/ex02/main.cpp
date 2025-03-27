/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:45 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:25:35 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	//AForm form("test");

	srand(time(NULL));

	Bureaucrat john("John", 22);
	Bureaucrat patrick("Patrick", 73);
	Bureaucrat pdg("PDG", 1);

	std::cout << john << std::endl;
	std::cout << patrick << std::endl;
	std::cout << pdg << std::endl;

	std::cout << std::endl << BLUE_COLOR << "---------- RobotomyRequestForm ---------- " << RESET_COLOR << std::endl << std::endl;

	RobotomyRequestForm robotomy("jean");
	std::cout << robotomy << std::endl;

	patrick.signForm(robotomy);
	std::cout << robotomy << std::endl;

	patrick.upGrade();
	std::cout << patrick << std::endl;

	patrick.signForm(robotomy);
	std::cout << robotomy << std::endl;

	std::cout << std::endl;

	patrick.executeForm(robotomy);
	pdg.executeForm(robotomy);

	std::cout << std::endl << BLUE_COLOR << "---------- PresidentialPardonForm ---------- " << RESET_COLOR << std::endl << std::endl;

	PresidentialPardonForm pardon("Chuck Norris");
	std::cout << pardon << std::endl;

	patrick.signForm(pardon);
	john.signForm(pardon);
	pdg.signForm(pardon);

	std::cout << pardon << std::endl;

	std::cout << std::endl;

	john.executeForm(pardon);
	patrick.executeForm(pardon);
	pdg.executeForm(pardon);

	std::cout << std::endl << BLUE_COLOR << "---------- ShrubberyCreationForm ---------- " << RESET_COLOR << std::endl << std::endl;

	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;

	patrick.executeForm(shrubbery);

	pdg.signForm(shrubbery);

	std::cout << shrubbery << std::endl;

	patrick.executeForm(shrubbery);

	std::cout << std::endl;

	john.signForm(shrubbery);
	patrick.executeForm(shrubbery);

	std::cout << std::endl;

	return 0;
}
