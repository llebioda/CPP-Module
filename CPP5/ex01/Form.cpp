/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:30:32 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 10:08:55 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Color.hpp"

Form::Form() : name(""), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
}

Form::Form(const std::string name) : 
	name(name), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
	name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
	if (gradeToSign <= 0 || gradeToExecute <= 0)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
}

std::string Form::getName(void) const
{
	return name;
}

int Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

int Form::getIsSigned(void) const
{
	return isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	if (isSigned)
		throw AlreadySignedForm();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form '" << form.getName()
		<< "', grade to sign = " << form.getGradeToSign()
		<< ", grade to execute = " << form.getGradeToExecute()
		<< ", is signed = " << (form.getIsSigned() ? "true" : "false") << ".";
	return os;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *Form::AlreadySignedForm::what() const throw()
{
	return "AlreadySignedForm";
}
