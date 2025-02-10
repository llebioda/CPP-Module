/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:59:04 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/30 15:11:46 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie *horde1 = zombieHorde(20, "Joseph");
	for (size_t i = 0; i < 20; i++)
	{
		horde1[i].announce();
	}
	delete [] horde1;

	Zombie *horde2 = zombieHorde(5, "fleshy boy");
	for (size_t i = 0; i < 5; i++)
	{
		horde2[i].announce();
	}
	delete [] horde2;

	return 0;
}
