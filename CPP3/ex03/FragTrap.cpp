/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 15:39:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "[FragTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[FragTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	*this = other;
	std::cout << "[FragTrap] \033[0;32mA copy of " << name << " joined the battle\033[m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] \033[0;35m" << name << " has been destroyed\033[m" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (health <= 0)
	{
		std::cout << "\033[0;31m" << name << " is dead, " << name << " can't do a High Fives\033[m" << std::endl;
		return ;
	}

	std::cout << "\033[1;34m" << name << " want to do a High Fives with his enemies\033[m" << std::endl;
}

