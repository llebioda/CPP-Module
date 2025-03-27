/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:33:24 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/14 15:11:43 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <list>
#include <stack>
#include <string>

class RPN
{
	private:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

	public:
		static double eval(const std::string &expr);

	class InvalidExpression : public std::exception
	{
		private:
			std::string msg;
			int errorIndex;

		public:
			InvalidExpression(void);
			InvalidExpression(const std::string msg);
			InvalidExpression(const std::string msg, int errorIndex);
			~InvalidExpression() throw();
			const char *what() const throw();

			int getErrorIndex(void) const;
	};
};