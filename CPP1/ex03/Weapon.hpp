/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:29:48 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:51 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		Weapon(const Weapon& other);
		Weapon &operator=(const Weapon& other);
		~Weapon();

		const std::string& getType() const;
		void setType(std::string type);
};

#endif