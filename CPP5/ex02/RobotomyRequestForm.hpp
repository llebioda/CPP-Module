/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:17:49 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/03 13:51:54 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const static int gradeToSign = 72;
		const static int gradeToExecute = 45;

		const std::string target;

		virtual void executeForm(void) const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string getTarget(void) const;
};
