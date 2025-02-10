/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:28 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:27 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
}

HumanA::HumanA(const HumanA &other) : weapon(other.weapon)
{
	*this = other;
}

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
