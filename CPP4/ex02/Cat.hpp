/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:47:59 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 13:14:28 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);
		Cat(const Cat& other);
		Cat &operator=(const Cat& other);
		~Cat();

		virtual void makeSound(void) const;
		virtual Brain *getBrain(void) const;
};

#endif