/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:22:50 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/06 13:42:34 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");
	ClapTrap x11("x11");

	bob.attack("x11");
	x11.takeDamage(2);

	bob.attack("Bob");
	bob.takeDamage(2);

	x11.beRepaired(5);
	x11.attack("Bob");
	bob.takeDamage(3);

	ClapTrap clappy("Clappy");

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			clappy.attack("Bob");
			bob.takeDamage(3);
		}
		else
		{
			clappy.attack("x11");
			x11.takeDamage(3);
		}
		if (i % 3 == 0)
			clappy.beRepaired(10);
	}

	bob.attack("x11");
	bob.beRepaired(1);

	return 0;
}
