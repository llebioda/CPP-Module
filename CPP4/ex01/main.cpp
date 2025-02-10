/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:50:11 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:37:53 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define ANIMAL_COUNT 10

int main(void)
{
	Animal* dog = new Dog();
	Cat* cat = new Cat();

	std::cout << "type => " << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << "type => " << cat->getType() << std::endl;
	cat->makeSound();

	delete dog;

	cat->getBrain()->setIdeas(5, "2 + 2 = 4");
	cat->getBrain()->setIdeas(34, "i² = -1");

	Cat *new_cat = new Cat();
	*new_cat = *cat;

	std::cout << "idea 34 of cat : '" << cat->getBrain()->getIdeas(34) << "'" << std::endl;

	new_cat->getBrain()->setIdeas(82, "nothing");

	std::cout << "idea 82 of cat : '" << cat->getBrain()->getIdeas(82) << "'" << std::endl;
	std::cout << "idea 82 of new_cat : '" << new_cat->getBrain()->getIdeas(82) << "'" << std::endl;

	delete cat;

	std::cout << "type => " << new_cat->getType() << std::endl;
	new_cat->makeSound();

	std::cout << "idea 5 of new_cat : '" << new_cat->getBrain()->getIdeas(5) << "'" << std::endl;
	std::cout << "idea 34 of new_cat : '" << new_cat->getBrain()->getIdeas(34) << "'" << std::endl;

	delete new_cat;

	std::cout << std::endl << YELLOW_COLOR << " ----- Animals generator : " << ANIMAL_COUNT << " -----" << RESET_COLOR << std::endl << std::endl;

	Animal *animals[ANIMAL_COUNT];
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << YELLOW_COLOR << "id : " << i << RESET_COLOR << std::endl;
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << YELLOW_COLOR << "id : " << i << RESET_COLOR << std::endl;
		delete animals[i];
	}

	return 0;
}
