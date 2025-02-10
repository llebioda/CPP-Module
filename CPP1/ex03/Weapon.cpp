/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:28 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:40 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("fist")
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::Weapon(const Weapon &other)
{
	*this = other;
}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
