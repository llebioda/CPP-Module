/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:35:15 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:43:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    Point inside(5.0f, 5.0f);
    Point vertex(0.0f, 0.0f);
    Point edge(5.0f, 0.0f);
    Point outside(5.0f, 11.0f);

    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;

    std::cout << "Point inside the triangle " << inside << ": " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point on the vertex of the triangle " << vertex << ": " << bsp(a, b, c, vertex) << std::endl;
    std::cout << "Point on the edge of the triangle " << edge << ": " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Point outside the triangle " << outside << ": " << bsp(a, b, c, outside) << std::endl;

	return 0;
}
