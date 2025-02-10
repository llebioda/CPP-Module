/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:42:24 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:45:48 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("")
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return type;
}
