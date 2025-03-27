/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:09:23 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/13 11:24:36 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }

		const_iterator begin(void) const { return this->c.begin(); }
		const_iterator end(void) const { return this->c.end(); }

		reverse_iterator rbegin(void) { return this->c.rbegin(); }
		reverse_iterator rend(void) { return this->c.rend(); }

		const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
		const_reverse_iterator rend(void) const { return this->c.rend(); }
};
