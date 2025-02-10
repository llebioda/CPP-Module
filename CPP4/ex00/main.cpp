/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:50:11 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 12:12:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "type => " << j->getType() << std::endl;
	std::cout << "type => " << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;

	Animal *cat = new Cat();//Dog();
	*cat = *i;

	delete i;

	std::cout << "type => " << cat->getType() << std::endl;
	cat->makeSound();

	delete cat;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "type => " << wrongAnimal->getType() << std::endl;
	std::cout << "type => " << wrongCat->getType() << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
