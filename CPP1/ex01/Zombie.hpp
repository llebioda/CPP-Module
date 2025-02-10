/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:56:38 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:35:06 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &other);
		Zombie &operator=(const Zombie &other);
		~Zombie();

		void announce( void );
};

Zombie* zombieHorde(int N, std::string name);

#endif