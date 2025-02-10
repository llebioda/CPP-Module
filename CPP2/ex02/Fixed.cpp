/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:15:41 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:14:32 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int intValue) : rawBits(intValue << fractionalBits) {}

Fixed::Fixed(const float floatValue) : rawBits(roundf(floatValue * (1 << fractionalBits))) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		rawBits = other.rawBits;
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& other) const { return rawBits > other.rawBits; }
bool Fixed::operator<(const Fixed& other) const { return rawBits < other.rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return rawBits >= other.rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return rawBits <= other.rawBits; }
bool Fixed::operator==(const Fixed& other) const { return rawBits == other.rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return rawBits != other.rawBits; }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.rawBits == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	rawBits++;
	return temp;
}

Fixed& Fixed::operator--()
{
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
