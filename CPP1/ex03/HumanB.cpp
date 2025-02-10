/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:28 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:30 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::HumanB(const HumanB &other)
{
	*this = other;
}

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void) const
{
	if (weapon == NULL)
		std::cout << name << " attacks with their fist" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
