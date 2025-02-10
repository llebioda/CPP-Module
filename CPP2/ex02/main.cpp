/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:15:43 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/05 11:16:43 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

    std::cout << std::endl << std::endl;

    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e(a + c * b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    std::cout << std::endl;

    a = Fixed(1175.05f);
    std::cout << "a: " << a << std::endl;

    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > e: " << (b > e) << std::endl;
    std::cout << "b < e: " << (b < e) << std::endl;
    std::cout << "b > d: " << (b > d) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;
    std::cout << "b >= a: " << (b >= a) << std::endl;

    std::cout << std::endl;

    std::cout << "a < a: " << (a < a) << std::endl;
    std::cout << "a > a: " << (a > a) << std::endl;
    std::cout << "a == a: " << (a == a) << std::endl;
    std::cout << "a / Fixed(5f): " << (a / Fixed(5)) << std::endl;
    std::cout << "Fixed(235.012f) == (a / Fixed(5f)): " << (Fixed(235.012f) == (a / Fixed(5))) << std::endl;

    std::cout << std::endl;

    std::cout << "b + c: " << (b + c) << std::endl;
    std::cout << "b - c: " << (b - c) << std::endl;
    std::cout << "b * c: " << (b * c) << std::endl;
    std::cout << "b / c: " << (b / c) << std::endl;
    std::cout << "e / 0: " << (e / Fixed(0)) << std::endl;

    std::cout << std::endl;

    std::cout << "b++: " << b++ << std::endl;
    std::cout << "++b: " << ++b << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "--b: " << --b << std::endl;

    std::cout << std::endl;

    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

	return 0;
}
