/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:29:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:22 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(const HumanA &other);
		HumanA &operator=(const HumanA &other);
		~HumanA();

		void attack(void) const;
};

#endif