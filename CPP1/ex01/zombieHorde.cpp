/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:18:51 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/30 15:09:15 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	char zombie_name[strlen(name.c_str()) + 20];
	for (int i = 0; i < N; i++)
	{
		sprintf(zombie_name, "%s %d", name.c_str(), i + 1);
		zombies[i] = Zombie(zombie_name);
	}
	return zombies;
}
