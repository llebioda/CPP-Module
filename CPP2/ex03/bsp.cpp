/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:28:10 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:43:00 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed determinant(Point const &p1, Point const &p2, Point const &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		 - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;

    d1 = determinant(point, a, b);
    d2 = determinant(point, b, c);
    d3 = determinant(point, c, a);

    if (d1 == 0 || d2 == 0 || d3 == 0) return false;

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}