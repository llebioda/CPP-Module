/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:29:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:34 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMBNB_HPP
# define HUMBNB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name);
		HumanB(const HumanB &other);
		HumanB &operator=(const HumanB &other);
		~HumanB();

		void attack(void) const;
		void setWeapon(Weapon &weapon);
};

#endif