/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:10:43 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/06 09:41:24 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "iter.hpp"

#pragma region TestUtils
class EmptyClass
{
	public:
		long v1;
		char v2;
		bool b[7];
		EmptyClass(void) :v1(0), v2(0) {}
};

std::ostream &operator<<(std::ostream &os, const EmptyClass &emptyClass)
{
	(void)emptyClass;
	os << "EmptyClass";
	return os;
}

class TestClass
{
	public:
		int v1;
		double v2;
		size_t hash;

		TestClass(void) : v1(std::rand()), hash(0)
		{
			size_t *ptr = (size_t *)(&v2);
			*ptr = (((size_t)std::rand()) << 32) | std::rand();
		}

		static void calculateHash(TestClass &testClass)
		{
			size_t *ptr = (size_t *)(&testClass.v2);
			testClass.hash = *ptr;
			testClass.hash = testClass.hash ^ ((((size_t)testClass.v1) << 32) | testClass.v1);
		}

		static void print(TestClass &testClass);
};

std::ostream &operator<<(std::ostream &os, const TestClass &testClass)
{
	os << "TestClass(v1 = " << testClass.v1 << ", v2 = " << testClass.v2 << ", hash = " << testClass.hash << ")";
	return os;
}

void TestClass::print(TestClass &testClass) {std::cout << testClass << std::endl;}

void printInt(int nb) { std::cout << "nb is : " << nb << std::endl; }
void increment(int &nb) { nb++; }
void abs(int& v) { v = v < 0 ? -v : v; }

template<typename T>
void printBits(T& v)
{
	const size_t numBits = sizeof(T) * 8;
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&v);

    std::cout << sizeof(T) << " : 0b";
    for (size_t i = 0; i < numBits; ++i)
    {
        size_t byteIndex = i / 8;
        size_t bitIndex = 8 - 1 - (i % 8);
        std::cout << ((bytes[byteIndex] >> bitIndex) & 1);
    }
    std::cout << std::endl;
}
#pragma endregion

#define INT_NB 7
#define CLASS_NB 4

int main(void)
{
	std::srand(std::time(NULL));

	{
		std::cout << std::endl << " ----- int -----" << std::endl;

		int a[INT_NB];

		for (int i = 0; i < INT_NB; i++)
			a[i] = std::rand() % 256;

		iter(a, INT_NB, printInt);

		std::cout << std::endl << " ----- increment -----" << std::endl;

		iter(a, INT_NB, increment);

		iter(a, INT_NB, printInt);

		std::cout << std::endl;

		iter(a, INT_NB, printBits);

		std::cout << std::endl << " ----- abs -----" << std::endl;

		iter(a, INT_NB, abs);

		iter(a, INT_NB, printInt);

		std::cout << std::endl;

		iter(a, INT_NB, printBits);

		std::cout << std::endl;
	}

	{
		std::cout << std::endl << " ----- TestClass -----" << std::endl;

		TestClass classes[CLASS_NB];

		iter(classes, CLASS_NB, TestClass::print);

		std::cout << std::endl << " ----- TestClass::calculateHash -----" << std::endl;

		iter(classes, CLASS_NB, TestClass::calculateHash);

		iter(classes, CLASS_NB, TestClass::print);

		std::cout << std::endl;

		iter(classes, CLASS_NB, printBits);

		std::cout << std::endl;
	}

	{
		std::cout << std::endl << " ----- EmptyClass -----" << std::endl;

		//new EmptyClass();

		EmptyClass classes[CLASS_NB];

		for (size_t i = 0; i < CLASS_NB; i++)
		{
			for (size_t j = 0; j < sizeof(classes[i].b); j++)
				classes[i].b[j] = i == 2;
		}

		iter(classes, CLASS_NB, printBits);

		std::cout << std::endl;
	}

	return 0;
}