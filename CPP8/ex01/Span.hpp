/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:02:52 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 11:09:45 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int capacity;
		std::vector<int> values;

	public:
		Span(void);
		Span(unsigned int capacity);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		unsigned int getCapacity(void) const;
		std::vector<int> getValues(void) const;

		void addNumber(int nb);

		template<typename T>
		void addRange(T& iterator);

		long shortestSpan(void) const;
		long longestSpan(void) const;

	class FullException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NotEnoughValuesException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

template<typename T>
void Span::addRange(T& iterator)
{
	if (values.size() + iterator.size() > capacity)
		throw FullException();
	values.insert(values.end(), iterator.begin(), iterator.end());
}

std::ostream &operator<<(std::ostream &os, const Span &span);
