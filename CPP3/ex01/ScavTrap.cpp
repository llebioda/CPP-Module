/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 15:40:04 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "[ScavTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
	*this = other;
	std::cout << "[ScavTrap] \033[0;32mA copy of " << name << " joined the battle\033[m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		health = other.health;
		energy = other.energy;
		damage = other.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] \033[0;35m" << name << " has been destroyed\033[m" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (health <= 0)
	{
		std::cout << "\033[0;31m" << name << " is dead, " << name << " cannot attack\033[m" << std::endl;
		return ;
	}

	if (energy <= 0)
	{
		std::cout << "\033[0;31m" << name << " is exhausted, " << name << " cannot attack\033[m" << std::endl;
		return ;
	}

	energy--;

	std::cout << "\033[0;36mThe ScavTrap " << name << " attacks " << target << " dealing " << damage << " points of damage! (" << energy << " energy left)\033[m" << std::endl;
}

void ScavTrap::guardGate()
{
	if (health <= 0)
	{
		std::cout << "\033[0;31m" << name << " is dead, " << name << " cannot switch to Gate keeper mode\033[m" << std::endl;
		return ;
	}

	std::cout << "\033[1;34m" << name << " switch to Gate keeper mode\033[m" << std::endl;
}

