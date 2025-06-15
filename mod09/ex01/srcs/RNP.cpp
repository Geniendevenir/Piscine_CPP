/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:56:15 by allan             #+#    #+#             */
/*   Updated: 2025/06/15 21:07:13 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

RNP::RNP() : _stackSize(0) {
	return ;
}

RNP::RNP(const std::string& str) : _stackSize(0), _input(str) {
	return ;
}


/* RNP::RNP(const RNP &src) {
	*this = src;
	return ;
} */


RNP::~RNP() {
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

/* RNP& RNP::operator=(const RNP &rhs) {
	//define behavior: instA = instB;
	//if (this != &rhs)
		//copy value;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const RNP &i) {
	//define behavior: std::cout << instance;
	return o;
} */

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

bool RNP::isOperator(char c) const {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

bool RNP::parseInput() {
	if (_input.size() < 5) {
		std::cerr << "Error: Input must have at least 2 digits and one operator" << std::endl;
		return ERROR;
	}
	if (!isdigit(_input[0]) || _input[1] != ' ' || !isdigit(_input[2])) {
		std::cerr << "Error: Input must follow that pattern: '1 2 + ...'" << std::endl;
		return ERROR;
	}
	if (!isOperator(_input[_input.size() - 1])) {
		std::cerr << "Error: Input must end with an operator" << std::endl;
		return ERROR;
	}
	
	for (std::size_t i = 0; i < _input.size(); i++) {
		if (i % 2 == 0) {
			if (isdigit(_input[i]))
				_stackSize++;
			else if (isOperator(_input[i]))
				_stackSize--;
			else {
				std::cerr << "Error: Input must contain only positive digits, space or operator (+, -, / or *)" << std::endl;
				return ERROR;
			}
		}
		else if (i % 2 == 1 && _input[i] != ' ') {
			std::cerr << "Error: Inputs must be seperated by one space (only)" << std::endl;
			return ERROR;
		}
	}
	if (_stackSize != 1) {
		std::cerr << "Error: Input doesnt have a valid number of digits/operator" << std::endl;
		
	}
	
	return SUCCESS;
}