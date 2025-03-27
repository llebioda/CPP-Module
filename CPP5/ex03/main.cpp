/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:45 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 15:04:55 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	//AForm form("test");

	srand(time(NULL));

	Intern intern = Intern();

	Bureaucrat john("John", 22);
	Bureaucrat patrick("Patrick", 73);
	Bureaucrat pdg("PDG", 1);

	std::cout << john << std::endl;
	std::cout << patrick << std::endl;
	std::cout << pdg << std::endl;

	std::cout << std::endl << BLUE_COLOR << "---------- RobotomyRequestForm ---------- " << RESET_COLOR << std::endl << std::endl;

	AForm &robotomy = *intern.makeForm("robotomy request", "jean");
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

	delete &robotomy;

	std::cout << std::endl << BLUE_COLOR << "---------- PresidentialPardonForm ---------- " << RESET_COLOR << std::endl << std::endl;

	AForm &pardon = *intern.makeForm("presidential pardon", "Chuck Norris");
	std::cout << pardon << std::endl;

	patrick.signForm(pardon);
	john.signForm(pardon);
	pdg.signForm(pardon);

	std::cout << pardon << std::endl;

	std::cout << std::endl;

	john.executeForm(pardon);
	patrick.executeForm(pardon);
	pdg.executeForm(pardon);

	delete &pardon;

	std::cout << std::endl << BLUE_COLOR << "---------- ShrubberyCreationForm ---------- " << RESET_COLOR << std::endl << std::endl;

	AForm &shrubbery = *intern.makeForm("shrubbery creation", "home");
	std::cout << shrubbery << std::endl;

	patrick.executeForm(shrubbery);

	pdg.signForm(shrubbery);

	std::cout << shrubbery << std::endl;

	patrick.executeForm(shrubbery);

	std::cout << std::endl;

	john.signForm(shrubbery);
	patrick.executeForm(shrubbery);

	delete &shrubbery;

	std::cout << std::endl << BLUE_COLOR << "---------- InvalidForm ---------- " << RESET_COLOR << std::endl << std::endl;

	AForm *invalid = intern.makeForm("paid leave", "me");
	std::cout << "ptr addr : " << invalid << std::endl;

	AForm *tippo = intern.makeForm("shrubbery creatoin", "me");
	std::cout << "ptr addr : " << tippo << std::endl;

	std::cout << std::endl;

	return 0;
}
