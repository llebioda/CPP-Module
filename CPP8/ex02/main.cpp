/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:09:27 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/13 11:25:24 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::srand(std::time(NULL));

	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		mstack.pop();

		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(42);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << std::endl;

		std::stack<int> s(mstack);

		std::cout << "s top : " << s.top() << std::endl;
		s.pop();
		std::cout << "s top : " << s.top() << std::endl;

		std::cout << std::endl;
	}

	{
		MutantStack<int> mstack;

		std::cout << "is empty : " << (mstack.empty() ? "true" : "false") << std::endl;

		for (size_t i = 0; i < 20; i++)
			mstack.push(std::rand() % 256);

		std::cout << "is empty : " << (mstack.empty() ? "true" : "false") << std::endl;
		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		MutantStack<int>::iterator ite = mstack.end();

		for (MutantStack<int>::iterator it = mstack.begin(); it != ite; it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;
	}

	{
		MutantStack<char> mstack;

		std::string str = "Hello World !";

		for (size_t i = 0; i < str.length(); i++)
			mstack.push(str[i]);

		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		MutantStack<char>::iterator ite = mstack.end();

		for (MutantStack<char>::iterator it = mstack.begin(); it != ite; it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;
	}

	{
		MutantStack<char> mstack;

		std::string str = "Hello World !";

		for (size_t i = 0; i < str.length(); i++)
			mstack.push(str[i]);

		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		MutantStack<char>::reverse_iterator ite = mstack.rend();

		for (MutantStack<char>::reverse_iterator it = mstack.rbegin(); it != ite; it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;
	}

	return 0;
}
