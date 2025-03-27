/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:52:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 10:47:44 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <exception>
#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int length;
		T *elements;

	public:
		Array();
		Array(unsigned int length);
		Array(const Array<T>& other);
		Array<T> &operator=(const Array<T>& other);
		~Array();

		unsigned int size(void) const;

		T &operator[](long index);
		T operator[](long index) const;

	class IndexError : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array);

#include "Array.tpp"