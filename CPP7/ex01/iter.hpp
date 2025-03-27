/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:10:40 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 11:02:45 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template<typename T>
void iter(T *array, size_t length, void (*f)(T element))
{
	if (array == NULL || length == 0 || f == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void iter(T *array, size_t length, void (*f)(T& element))
{
	if (array == NULL || length == 0 || f == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void iter(T *array, size_t length, void (*f)(const T element))
{
	if (array == NULL || length == 0 || f == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void iter(T *array, size_t length, void (*f)(const T& element))
{
	if (array == NULL || length == 0 || f == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}
