/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:42:24 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 14:49:05 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		clearInventory();
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
}

void Character::clearInventory(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
}
