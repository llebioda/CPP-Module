/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:41:30 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 14:40:50 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria;

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria &operator=(const AMateria& other);
		virtual ~AMateria();

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#endif
