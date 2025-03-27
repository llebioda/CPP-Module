/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:39:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:13:54 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", gradeToSign, gradeToExecute), target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest", gradeToSign, gradeToExecute), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequest", gradeToSign, gradeToExecute), target(other.target)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return target;
}

void RobotomyRequestForm::executeForm(void) const
{
	std::cout << "rizzz, bzzzzzz, riiiizzzz, bzzzzzzzzz" << std::endl;
	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy on " << target << " failed" << std::endl;
}
