/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:20:50 by adebert           #+#    #+#             */
/*   Updated: 2025/06/27 15:24:18 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <climits>

#define SUCCESS 0
#define ERROR 1

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);
		const std::vector<int>& getInputs(void) const;
		bool checkInputs(int size, char **inputs);

	private:
		std::vector<int> toSort;
		int jacobsthal[13];
		bool isValidInt(const std::string &input);
};

std::ostream &operator<<(std::ostream &o, const PmergeMe &i);

#endif