/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 14:45:40 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""), health(10), energy(10), damage(0)
{
	std::cout << "[ClapTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), damage(0)
{
	std::cout << "[ClapTrap] \033[0;32m" << name << " joined the battle\033[m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "[ClapTrap] \033[0;32mA copy of " << name << " joined the battle\033[m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] \033[0;35m" << name << " has been destroyed\033[m" << std::endl;
}

void ClapTrap::attack(const std::string &target)
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

	std::cout << "\033[0;36m" << name << " attacks " << target << " causing " << damage << " points of damage! (" << energy << " energy left)\033[m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (health <= 0)
	{
		std::cout << "\033[0;31m" << name << " is already dead, he can't take more damage\033[m" << std::endl;
		return ;
	}

	health -= amount;
	if (health < 0)
		health = 0;

	std::cout << "\033[0;33m" << name << " receive " << amount << " points of damage, \033[0;37m" << name << " has now " << health << " hp\033[m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health <= 0)
	{
		std::cout << "\033[0;31m" << name << " is dead, " << name << " cannot repair itself\033[m" << std::endl;
		return ;
	}

	if (energy <= 0)
	{
		std::cout << "\033[0;31m" << name << " is exhausted, " << name << " cannot repair itself\033[m" << std::endl;
		return ;
	}

	health += amount;
	energy--;

	std::cout << "\033[0;36m" << name << " restored " << amount << " hp, \033[0;37m" << name << " has now " << health << " hp \033[0;36m(" << energy << " energy left)\033[m" << std::endl;
}
