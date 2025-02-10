/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:35:07 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/10 12:55:57 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include "Color.hpp"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(const Brain& other);
		Brain &operator=(const Brain& other);
		~Brain();

		std::string getIdeas(int index) const;
		void setIdeas(int index, std::string idea);
};

#endif