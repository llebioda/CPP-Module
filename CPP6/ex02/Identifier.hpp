/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:25:27 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 15:51:18 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Identifier
{
	private:
		Identifier(void);
		Identifier(const Identifier& other);
		Identifier &operator=(const Identifier& other);
		~Identifier();

	public:
		static void identify(Base* p);
		static void identify(Base& p);
};
