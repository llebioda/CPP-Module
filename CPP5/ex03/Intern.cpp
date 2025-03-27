/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:32 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:52:07 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Color.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern()
{
}

Intern::FormType Intern::str2FormType(const char* str) const
{
    return strcmp(str, "presidential pardon") == 0 ? PRESIDENTIAL_PARDON_FORM :
           strcmp(str, "robotomy request") == 0 ? ROBOTOMY_REQUEST_FORM :
           strcmp(str, "shrubbery creation") == 0 ? SHRUBBERY_CREATION_FORM :
           INVALID;
}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
	AForm *form = NULL;

	switch (str2FormType(formName.c_str()))
	{
		case PRESIDENTIAL_PARDON_FORM:
			form = new PresidentialPardonForm(target);
			break;

		case ROBOTOMY_REQUEST_FORM:
			form = new RobotomyRequestForm(target);
			break;

		case SHRUBBERY_CREATION_FORM:
			form = new ShrubberyCreationForm(target);
			break;

		default:
			std::cout << "The form '" << formName << "' doesn't exist." << std::endl;
			break;
	}

	if (form != NULL)
		std::cout << "Intern created " << form->getName() << "." << std::endl;

	return form;
}
