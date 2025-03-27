/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:07 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 15:54:05 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Identifier.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

int main(void)
{
	srand(time(NULL));
	for (size_t i = 0; i < 5; i++)
	{
		Base* obj = generate();
		Identifier::identify(obj);
		Identifier::identify(*obj);
		std::cout << std::endl;

		delete obj;
	}
	return 0;
}
