/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:49:18 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 11:25:29 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
inline Array<T>::Array() : length(0), elements(NULL)
{
}

template <typename T>
inline Array<T>::Array(unsigned int length) : length(length), elements(new T[length])
{
}

template <typename T>
inline Array<T>::Array(const Array<T> &other) : length(0), elements(NULL)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (elements != NULL)
		{
			delete[] elements;
			elements = NULL;
		}

		length = other.length;
		if (length > 0)
		{
			elements = new T[length];
			for (size_t i = 0; i < length; i++)
				elements[i] = other.elements[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (elements != NULL)
	{
		delete[] elements;
		elements = NULL;
	}
}

template <typename T>
inline unsigned int Array<T>::size(void) const { return length; }

template <typename T>
T &Array<T>::operator[](long index)
{
	if (index < 0)
		index = length + index;
	if (index < 0 || index >= length)
		throw IndexError();
	return elements[index];
}

template <typename T>
T Array<T>::operator[](long index) const
{
	if (index < 0)
		index = length + index;
	if (index < 0 || index >= length)
		throw IndexError();
	return elements[index];
}

template <typename T>
inline const char *Array<T>::IndexError::what() const throw()
{
	return "IndexError : index out of range";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array)
{
    os << "[";
	for (unsigned int i = 0; i < array.size(); i++)
	{
		if (i > 0)
        	os << ", ";
        os << array[i];
	}
    os << "]";
    return os;
}