/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:32 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:23:49 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Color.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
	std::cout << GREEN_COLOR << "Bureaucrat '" << name << "' with grade " << grade << " joined the team" << RESET_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN_COLOR << "Bureaucrat '" << name << "' with grade " << grade << " joined the team" << RESET_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << PURPLE_COLOR << "Bureaucrat '" << name << "' left the team" << RESET_COLOR << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::upGrade(void)
{
	if (grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::downGrade(void)
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "'" << getName() << "' signed '" << form.getName() << "'" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "'" << getName() << "' couldn’t sign '" << form.getName() << "' because " << RED_COLOR << e.what() << RESET_COLOR << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "'" << getName() << "' executed '" << form.getName() << "'" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "'" << getName() << "' couldn’t execute '" << form.getName() << "' because " << RED_COLOR << e.what() << RESET_COLOR << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}
