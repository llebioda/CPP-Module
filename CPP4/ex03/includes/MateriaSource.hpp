/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:57:47 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 14:23:14 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int	index;
		AMateria *materias[4];

		void clearMaterias(void);

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource &operator=(const MateriaSource& other);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
