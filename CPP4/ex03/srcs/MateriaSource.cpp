/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:42:24 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 14:26:08 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : index(0)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		index = other.index;
		clearMaterias();
		for (int i = 0; i < 4; i++)
		{
			if (other.materias[i] != NULL)
				materias[i] = other.materias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	clearMaterias();
}

void MateriaSource::clearMaterias(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
		{
			delete materias[i];
			materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (materias[index] != NULL)
		delete materias[index];
	materias[index] = m;
	index = (index + 1) % 4;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return (NULL);
}
