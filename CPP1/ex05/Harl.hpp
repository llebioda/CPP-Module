/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:14:43 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/31 17:08:25 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	struct HarlAction
	{
		std::string level;
		void (Harl::*func)(void);
	};

	private:
		HarlAction actions[4];

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		Harl(const Harl &other);
		Harl &operator=(const Harl &other);
		~Harl();

		void complain(std::string level);
};

#endif