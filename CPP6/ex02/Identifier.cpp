/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:25:01 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 15:53:26 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Identifier::Identifier() {}

Identifier::Identifier(const Identifier &other)
{
	*this = other;
}

Identifier &Identifier::operator=(const Identifier &other)
{
	(void)other;
	return *this;
}

Identifier::~Identifier() {}

void Identifier::identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void Identifier::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception&) {}
}
