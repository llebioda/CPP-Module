/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:27 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:11:36 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExecute;

		bool isSigned;

	public:
		Form();
		Form(const std::string name);
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		int getIsSigned(void) const;

		void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class AlreadySignedForm : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
