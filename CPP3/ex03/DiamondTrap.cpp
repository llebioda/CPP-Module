/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 15:39:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), name("")
{
	std::cout << "[DiamondTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "[DiamondTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name + "_clap_name"), name(other.name)
{
	*this = other;
	std::cout << "[DiamondTrap] \033[0;32mA copy of " << name << " joined the battle\033[m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		ClapTrap::name = other.ClapTrap::name;
		health = other.health;
		energy = other.energy;
		damage = other.damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] \033[0;35m" << name << " has been destroyed\033[m" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[1;34mIm " << name << " and my ClapTrap name is " << ClapTrap::name << "\033[m" << std::endl;
}

