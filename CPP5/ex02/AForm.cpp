/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:40:01 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:15:32 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Color.hpp"

AForm::AForm() : name(""), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
}

AForm::AForm(const std::string name) :
	name(name), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) :
	name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
	if (gradeToSign <= 0 || gradeToExecute <= 0)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName(void) const
{
	return name;
}

int AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

int AForm::getIsSigned(void) const
{
	return isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	if (isSigned)
		throw AlreadySignedForm();
	isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	if (!isSigned)
		throw UnsignedForm();
	executeForm();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form '" << form.getName()
		<< "', grade to sign = " << form.getGradeToSign()
		<< ", grade to execute = " << form.getGradeToExecute()
		<< ", is signed = " << (form.getIsSigned() ? "true" : "false") << ".";
	return os;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char *AForm::AlreadySignedForm::what() const throw()
{
	return "AlreadySignedForm";
}

const char *AForm::UnsignedForm::what() const throw()
{
	return "UnsignedForm";
}
