/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:50 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:01 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap bob("Bob");
	ClapTrap x11("x11");

	bob.attack("x11");
	x11.takeDamage(2);

	bob.attack("Bob");
	bob.takeDamage(2);

	x11.beRepaired(5);
	x11.attack("Bob");
	bob.takeDamage(3);

	ScavTrap clappy("Clappy");
	ScavTrap proto("Proto");

	proto.guardGate();

	for (int i = 0; i < 25; i++)
	{
		if (i % 2 == 0)
		{
			clappy.attack("Bob");
			bob.takeDamage(3);
			if (i % 5 == 0)
			{
				clappy.attack("Bob");
				bob.takeDamage(20);
				clappy.attack("Proto");
				proto.takeDamage(i * 5);
				clappy.takeDamage(i * 2);

				proto.beRepaired(5);
			}
		}
		else
		{
			clappy.attack("x11");
			x11.takeDamage(2);
		}
		clappy.beRepaired(3 - (i % 4));
	}

	clappy.guardGate();
	bob.attack("x11");
	bob.beRepaired(1);

	return 0;
}
