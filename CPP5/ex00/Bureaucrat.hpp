/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:27 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 13:43:20 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName(void) const;
		int getGrade(void) const;

		void upGrade(void);
		void downGrade(void);

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
