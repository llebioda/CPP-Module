/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:14:43 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/04 09:33:38 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string.h>

class Harl
{
	private:
		enum Level { DEBUG, INFO, WARNING, ERROR, INVALID };

		Level str2level(const char* str);

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