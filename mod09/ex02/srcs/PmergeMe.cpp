/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:21:08 by adebert           #+#    #+#             */
/*   Updated: 2025/06/27 15:37:17 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

PmergeMe::PmergeMe() {
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;
	jacobsthal[2] = 5;
	jacobsthal[3] = 11;
	jacobsthal[4] = 21;
	jacobsthal[5] = 43;
	jacobsthal[6] = 85;
	jacobsthal[7] = 171;
	jacobsthal[8] = 341;
	jacobsthal[9] = 683;
	jacobsthal[10] = 1365;
	jacobsthal[11] = 2731;
	jacobsthal[12] = 5461;
}


PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}


PmergeMe::~PmergeMe() {
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs)
		toSort = rhs.toSort;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const PmergeMe &i) {
	std::vector<int> inputs = i.getInputs();
	o << "Input Vector Content:" << std::endl;
	for (std::vector<int>::iterator it = inputs.begin(); it != inputs.end(); ++it) {
		o << *it << " ";
	}
	o << std::endl;
	return o;
}


//////////////////////////////////////////////////////////
//					 GETTER/SETTER						//
//////////////////////////////////////////////////////////

const std::vector<int>& PmergeMe::getInputs(void) const {
	return toSort;
}

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

bool PmergeMe::checkInputs(int size, char**inputs) {
	for (int i = 0; i < size; ++i) {
		if (!isValidInt(static_cast<std::string>(inputs[i]))) {
			std::cerr << "Error: Invalid Input Found" << std::endl;
			return ERROR;
		}
	}
	return SUCCESS;
}

bool PmergeMe::isValidInt(const std::string &input) {

	for (size_t i = 0; i < input.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;	
	}
	
	errno = 0;
	char *end;
	long result = std::strtol(input.c_str(), &end, 10);

	if (errno == ERANGE || result < INT_MIN || result > INT_MAX)
		return false;
		
	toSort.push_back(result);	
	return true;	
}
