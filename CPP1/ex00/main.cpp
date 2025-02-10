/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:59:04 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/30 14:50:01 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include "Zombie.hpp"

#define ZOMBIE_NB 5

int main(void)
{
	randomChump("random1");
	randomChump("random2");

	Zombie *zombies[ZOMBIE_NB];

	for (size_t i = 0; i < ZOMBIE_NB; i++)
	{
		char name[50];
		sprintf(name, "Michel %lu", i + 1);
		zombies[i] = newZombie(name);
		if (i % 2 == 1)
			zombies[i]->announce();
	}

	for (size_t i = 0; i < ZOMBIE_NB; i++)
	{
		if (i % 2 == 0)
			zombies[i]->announce();
		delete zombies[i];
	}

	randomChump("zb");

	delete newZombie("Instant");

	Zombie z = Zombie();
	z.announce();

	return 0;
}
