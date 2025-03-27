/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:39:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:00:14 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", gradeToSign, gradeToExecute), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon", gradeToSign, gradeToExecute), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardon", gradeToSign, gradeToExecute), target(other.target)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return target;
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
