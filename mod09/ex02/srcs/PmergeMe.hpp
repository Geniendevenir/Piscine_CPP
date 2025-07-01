/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:20:50 by adebert           #+#    #+#             */
/*   Updated: 2025/07/01 20:13:07 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>
#include <set>

#define SUCCESS false
#define ERROR true


template <typename T>
class PmergeMe {
	public:
		PmergeMe() {}
		
		PmergeMe(const PmergeMe &src) {
			*this = src;
		}
		
		~PmergeMe() {}

		PmergeMe &operator=(const PmergeMe &rhs) {
			if (this != &rhs)
				toSort = rhs.toSort;
			return *this;
		}
		
		const T& getInputs(void) const {
			return toSort;
		}
		
		bool checkInputs(int size, char **inputs) {
			for (int i = 0; i < size; ++i) {
				if (!isValidInt(static_cast<std::string>(inputs[i]))) {
					std::cerr << "Error: Invalid Input Found" << std::endl;
					return ERROR;
				}
			}
			if (hasDuplicate()) {
				std::cerr << "Error: Duplicates Integer Found" << std::endl;
				return ERROR;
			}
			return SUCCESS;
		}

		T fordJohsonSort(const T& toPairUp) {
			T larger;
			T smaller;

			//Pair up / Sort into larger or smaller
			typename T::const_iterator it = toPairUp.begin();
			while(it != toPairUp.end()) {
				typename T::const_iterator next = it;
				std::advance(next, 1);

				if (next == toPairUp.end()) {
					//Left Over
					smaller.push_back(*it);
					break;
				}

				if (*it > *next) {
					larger.push_back(*it);
					smaller.push_back(*next);
				} else {
					larger.push_back(*next);
					smaller.push_back(*it);
				}
				
				std::advance(it, 2);
			}

			//Recursif Call
			larger = fordJohsonSort(larger);	

			//Insert smaller into larger using Jacobstal + Binary Search
			T insertionOrder = getJacobsthalIndex(smaller.size());
			
			for (typename T::const_iterator it = insertionOrder.begin(); it != insertionOrder.end(); ++it) {
				std::size_t i = *it;
				if (i >= smaller.size()) continue;
				typename T::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
				larger.insert(pos, smaller[i]);
			}
			return larger; 
		}

		void printContainer(const T& toPrint) const {
			for (typename T::const_iterator it = toPrint.begin(); it != toPrint.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;	
		}

	private:
		T toSort;

		bool isValidInt(const std::string &input) {
			errno = 0;
			char *end;
			long result = std::strtol(input.c_str(), &end, 10);

			if (*end != '\0' || errno == ERANGE || result < INT_MIN || result > INT_MAX)
				return false;
				
			toSort.push_back(result);	
			return true;	
		}

		bool hasDuplicate() const {
			std::set<int> seen;
			for (typename T::const_iterator it = toSort.begin(); it != toSort.end(); ++it) {
				if (!seen.insert(*it).second)
					return true;	
			}
			return false;
		}

		T getJacobsthalIndex(int size) {
			T result;

			int j0 = 0, j1 = 1;
			while (j1 < size) {
				result.push_back(j1);
				int j2 = j1 + 2 * j0;
				j0 = j1;
				j1 = j2;
			}

			T used;
			for (int i = 0; i < size; ++i)
				used.push_back(0); // 0 = false

			for (typename T::const_iterator it = result.begin(); it != result.end(); ++it) {
				if (*it < size)
					used[*it] = 1; // mark as used (true)
			}

			for (int i = 0; i < size; ++i) {
				if (used[i] == 0)
					result.push_back(i);
			}

			return result;
		}
	

};

template <typename T>
std::ostream &operator<<(std::ostream &o, const PmergeMe < T > &i) {
	const T& inputs = i.getInputs();
	for (typename T::const_iterator it = inputs.begin(); it != inputs.end(); ++it) {
		o << *it << " ";
	}
	o << std::endl;
	return o;
}

#endif