/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:39:35 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 12:10:38 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>
# include "Color.hpp"

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal &operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif