/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:17:49 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 14:00:17 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const static int gradeToSign = 25;
		const static int gradeToExecute = 5;

		const std::string target;

		virtual void executeForm(void) const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string getTarget(void) const;
};
