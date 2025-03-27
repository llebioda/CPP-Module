/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:01:17 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 16:29:09 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
T min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template<typename T>
T max(const T& a, const T& b)
{
	return a > b ? a : b;
}

