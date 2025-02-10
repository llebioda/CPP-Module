/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:15:41 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:40:11 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	*this = other;
}

Point &Point::operator=(const Point &other)
{
    if (this != &other) {}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
