/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:46:51 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:21 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << "[want TRUE] > tmp is null : " << (src->createMateria("cure") == NULL ? "true" : "false") << std::endl;

	src->learnMateria(new Cure());

	for (int i = 0; i < 8; i++)
		src->learnMateria(new Ice());

	std::cout << "[want TRUE] > tmp is null : " << (src->createMateria("cure") == NULL ? "true" : "false") << std::endl;

	src->learnMateria(new Cure());

	tmp = src->createMateria("cure");
	std::cout << "[want FALSE] > tmp is null : " << (tmp == NULL ? "true" : "false") << std::endl;
	delete tmp;

	std::cout << std::endl;

	me->equip(src->createMateria("cure"));

	ICharacter* bob = new Character("bob");
	bob->equip(src->createMateria("cure"));
	AMateria* tmp2 = src->createMateria("ice");
	bob->equip(tmp2);
	bob->equip(src->createMateria("cure"));
	bob->equip(src->createMateria("ice"));

	tmp = src->createMateria("cure");
	bob->equip(tmp); // should not be added to inventory
	delete tmp;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl << "[CURE -> ICE -> CURE -> ICE]" << std::endl << std::endl;
	for (int i = -2; i < 6; i++)
	{
		std::cout << "materia id : " << i << std::endl;
		bob->use(i, *me);
	}

	bob->unequip(1);
	delete tmp2;

	std::cout << std::endl << "[CURE -> NULL -> CURE -> ICE]" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "materia id : " << i << std::endl;
		bob->use(i, *me);
	}

	bob->equip(src->createMateria("cure"));
	std::cout << std::endl << "[CURE -> CURE -> CURE -> ICE]" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "materia id : " << i << std::endl;
		bob->use(i, *me);
	}

	delete bob;
	delete me;
	delete src;

	return 0;
}
