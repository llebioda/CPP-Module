/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:39:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 13:52:41 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", gradeToSign, gradeToExecute), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", gradeToSign, gradeToExecute), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreation", gradeToSign, gradeToExecute), target(other.target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return target;
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::cout << "Created file '" << target << "_shrubbery' in the working directory." << std::endl;
	std::cout << "Writing an ASCII trees inside it ..." << std::endl;
	std::cout << "ASCII trees finished." << std::endl;
}
