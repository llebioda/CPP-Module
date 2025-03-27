/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:29:33 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:50:52 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		enum FormType { INVALID, PRESIDENTIAL_PARDON_FORM, ROBOTOMY_REQUEST_FORM, SHRUBBERY_CREATION_FORM };

		FormType str2FormType(const char* str) const;

	public:
		Intern(void);
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);
		~Intern();

		AForm *makeForm(std::string formName, std::string target) const;
};
