/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:06:34 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/17 09:46:51 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <vector>

class PmergeMe
{
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	public:
		template<typename Container>
		static double sortAndCalculateTime(Container &container);

		template<typename Container>
		static void mergeInsertSort(Container &container);
};

template<typename Container>
double PmergeMe::sortAndCalculateTime(Container &container)
{
	struct timespec	start_time;
	clock_gettime(CLOCK_MONOTONIC, &start_time);

	mergeInsertSort(container);

	struct timespec	end_time;
	clock_gettime(CLOCK_MONOTONIC, &end_time);

	double elapsedMicroseconds =
		static_cast<double>(end_time.tv_sec - start_time.tv_sec) * 1e3 +
		static_cast<double>(end_time.tv_nsec - start_time.tv_nsec) / 1e6;

	return elapsedMicroseconds;
}

template<typename Container>
void PmergeMe::mergeInsertSort(Container &container)
{
	typedef typename Container::iterator Iterator;
	typedef typename Container::const_iterator ConstIterator;

	if (container.size() <= 1)
		return;

	Iterator middle = container.begin() + container.size() / 2;
	Container left(container.begin(), middle);
	Container right(middle, container.end());

	mergeInsertSort(left);
	mergeInsertSort(right);

	Iterator leftIt = left.begin();
	ConstIterator leftEnd = left.end();
	Iterator rightIt = right.begin();
	ConstIterator rightEnd = right.end();
	Iterator outputIt = container.begin();

	while (leftIt != leftEnd && rightIt != rightEnd)
	{
		if (*leftIt < *rightIt)
			*outputIt++ = *leftIt++;
		else
			*outputIt++ = *rightIt++;
	}

	while (leftIt != leftEnd)
		*outputIt++ = *leftIt++;

	while (rightIt != rightEnd)
		*outputIt++ = *rightIt++;
}
