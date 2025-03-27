/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:40 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 16:31:06 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

class TestClass1
{
	public:
		int v1;
		double v2;

		TestClass1(int v1, double v2) {this->v1 = v1; this->v2 = v2;}
};

std::ostream &operator<<(std::ostream &os, const TestClass1 &testClass1)
{
	os << "TestClass1(v1 = " << testClass1.v1 << ", v2 = " << testClass1.v2 << ")";
	return os;
}

class TestClass2
{
	public:
		int v1;
		double v2;

		TestClass2(int v1, double v2) {this->v1 = v1; this->v2 = v2;}
		bool operator>(const TestClass2& other) const { return (v1 * v2) > (other.v1 * other.v2); }
		bool operator<(const TestClass2& other) const { return (v1 * v2) < (other.v1 * other.v2); }
};

std::ostream &operator<<(std::ostream &os, const TestClass2 &testClass2)
{
	os << "TestClass2(v1 = " << testClass2.v1 << ", v2 = " << testClass2.v2 << ")";
	return os;
}

int main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;

	// ::swap(c, a);

	// {
	// 	TestClass1 c1(42, 84.6);
	// 	TestClass1 c2(5, 1973.03);

	// 	::swap(c1, c2);
	// 	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	// 	std::cout << "min( c1, c2 ) = " << ::min( c1, c2 ) << std::endl;
	// 	std::cout << "max( c1, c2 ) = " << ::max( c1, c2 ) << std::endl;

	// 	std::cout << std::endl;
	// }

	{
		TestClass2 c1(42, 84.6);
		TestClass2 c2(5, 1973.03);

		::swap(c1, c2);
		std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
		std::cout << "min( c1, c2 ) = " << ::min( c1, c2 ) << std::endl;
		std::cout << "max( c1, c2 ) = " << ::max( c1, c2 ) << std::endl;

		std::cout << std::endl;
	}

	return 0;
}
