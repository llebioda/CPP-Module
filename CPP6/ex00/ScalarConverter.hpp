/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:16:01 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 13:19:54 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(std::string literal);
};
