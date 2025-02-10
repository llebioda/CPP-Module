/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:47:59 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 11:24:32 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Color.hpp"

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string name);
		Animal(const Animal& other);
		Animal &operator=(const Animal& other);
		virtual ~Animal();

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif