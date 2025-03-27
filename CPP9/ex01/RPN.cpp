/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:33:57 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 10:19:34 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

double RPN::eval(const std::string &expr)
{
	if (expr.empty())
		throw RPN::InvalidExpression("Empty expression");

	std::string::const_iterator it = expr.begin();
	std::string::const_iterator ite = expr.end();
	while (std::isspace(*it) && it != ite)
		it++;

	if (it == ite)
		throw RPN::InvalidExpression("Empty expression");

	while (std::isspace(*(ite - 1)) && it != (ite - 1))
		ite--;

	std::stack<double, std::list<double> > stack;
	for (; it != ite; it++)
	{
		if (std::isspace(*it))
			continue;
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (stack.size() < 2)
				throw RPN::InvalidExpression("Not enough operands", std::distance(expr.begin(), it));

			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();

			if (*it == '+')
				stack.push(b + a);
			else if (*it == '-')
				stack.push(b - a);
			else if (*it == '*')
				stack.push(b * a);
			else if (*it == '/')
			{
				if (a == 0.0)
					throw RPN::InvalidExpression("Division by zero", std::distance(expr.begin(), it));
				stack.push(b / a);
			}
		}
		else if (std::isdigit(*it))
		{
			stack.push(0.0);
			bool isFraction = false;
			double fractionValue = 1.0;

			while (std::isdigit(*it))
			{
				if (isFraction)
				{
					fractionValue *= 0.1;
					stack.top() += (*it - '0') * fractionValue;
				}
				else
					stack.top() = stack.top() * 10.0 + *it - '0';

				it++;
				while (*it == '.')
				{
					if (isFraction)
						throw RPN::InvalidExpression("Invalid number", std::distance(expr.begin(), it));
					isFraction = true;
					it++;
				}
			}
			it--;
		}
		else
			throw RPN::InvalidExpression("Invalid character", std::distance(expr.begin(), it));
	}

	if (stack.size() != 1)
		throw RPN::InvalidExpression("Too much operands", std::distance(expr.begin(), it) - 1);

	return stack.top();
}

RPN::InvalidExpression::InvalidExpression(void)
	: msg("Invalid Expression"), errorIndex(-1) {}

RPN::InvalidExpression::InvalidExpression(const std::string msg)
	: msg("Invalid Expression: " + msg), errorIndex(-1) {}

RPN::InvalidExpression::InvalidExpression(const std::string msg, int errorIndex)
	: msg("Invalid Expression: " + msg), errorIndex(errorIndex) {}

RPN::InvalidExpression::~InvalidExpression() throw() {}

const char *RPN::InvalidExpression::what() const throw()
{
	return this->msg.c_str();
}

int RPN::InvalidExpression::getErrorIndex(void) const
{
	return errorIndex;
}
