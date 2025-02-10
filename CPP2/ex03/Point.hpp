/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:15:39 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:40:08 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point &operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& fixed);

#endif