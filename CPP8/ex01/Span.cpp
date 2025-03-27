/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:49:18 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 15:14:10 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : capacity(0), values(std::vector<int>(0)) {}

Span::Span(unsigned int capacity)
 : capacity(capacity), values(std::vector<int>(0)) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		capacity = other.capacity;
		values = other.values;
	}
	return *this;
}

Span::~Span() {}

unsigned int Span::getCapacity(void) const { return capacity; }

std::vector<int> Span::getValues(void) const { return std::vector<int>(values); }

void Span::addNumber(int nb)
{
	if (values.size() >= capacity)
		throw FullException();
	values.push_back(nb);
}

long Span::shortestSpan(void) const
{
	if (values.size() <= 1)
		throw NotEnoughValuesException();
	std::vector<int> sorted(values);
	std::sort(sorted.begin(), sorted.end());
	long min = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		long diff = static_cast<long>(sorted[i + 1]) - static_cast<long>(sorted[i]);
		if (diff == 0)
			return 0;
		if (diff < min)
			min = diff;
	}
	return min;
}

long Span::longestSpan(void) const
{
	if (values.size() <= 1)
		throw NotEnoughValuesException();
	return static_cast<long>(*(std::max_element(values.begin(), values.end())))
		- static_cast<long>(*(std::min_element(values.begin(), values.end())));
}

const char *Span::FullException::what() const throw()
{
	return "Span is full, no more empty space available";
}

const char *Span::NotEnoughValuesException::what() const throw()
{
	return "There are not enough values stored in the span";
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	std::vector<int> values = span.getValues();
	os << "[";
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (i > 0)
			os << ", ";
		os << values[i];
	}
	os << "]";
	return os;
}
