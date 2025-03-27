/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:02:09 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/13 09:47:59 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <list>
#include <vector>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() { return "Element not found"; }
};

template<typename T>
typename T::value_type &easyfind(T& container, int value)
{
	typename T::iterator itEnd = container.end();
	for (typename T::iterator it = container.begin(); it != itEnd; it++)
	{
		if (*it == value)
			return *it;
	}
	throw NotFoundException();
}
