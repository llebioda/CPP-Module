/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:27 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 15:01:16 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExecute;

		bool isSigned;

	protected:
		virtual void executeForm(void) const = 0;

	public:
		AForm();
		AForm(const std::string name);
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		int getIsSigned(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;

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

	class UnsignedForm : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
