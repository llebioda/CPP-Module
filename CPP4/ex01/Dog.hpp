/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:47:59 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:03:35 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog(void);
		Dog(const Dog& other);
		Dog &operator=(const Dog& other);
		~Dog();

		virtual void makeSound(void) const;
		virtual Brain *getBrain(void) const;
};

#endif