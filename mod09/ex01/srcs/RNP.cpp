/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:56:15 by allan             #+#    #+#             */
/*   Updated: 2025/06/22 17:44:35 by allan            ###   ########.fr       */
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


RNP::RNP(const RNP &src) {
	*this = src;
	return ;
}


RNP::~RNP() {
	return ;
}


//////////////////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR / GETTER					//
/////////////////////////////////////////////////////////////////////

RNP& RNP::operator=(const RNP &rhs) {
	if (this != &rhs) {
		while (!_rnp.empty())
			_rnp.pop();
		_rnp = 	rhs._rnp;
		_stackSize = rhs._stackSize;
	}
	return *this;
}


double RNP::getResult(void) const {
	return _rnp.top();
}

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
		std::cerr << "Error: Input must follow that pattern: 'Digit Digit (...) Operator (...)'" << std::endl;
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
		return ERROR;
	}
	
	return SUCCESS;
}

bool RNP::createStack() {
	for (std::size_t i = 0; i < _input.size(); i++) {
		if (isdigit(_input[i])) {
			_rnp.push(_input[i] - '0');
		} else if (isOperator(_input[i])) {
			if (doOperation(_input[i]) == ERROR)
				return ERROR;
		}
	}
	return SUCCESS;
}
bool RNP::doOperation(char sign) {
	if (sign == '-')
		return doSubstraction();
	else if (sign == '+')
		return doAddition();
	else if (sign == '*')
		return doMultiplication();
	else if (sign == '/')
		return doDivision();
	return ERROR;
}

bool RNP::doSubstraction() {
	double nbr = _rnp.top();
	_rnp.pop();
	_rnp.top() -= nbr;
	if (checkIntOverflow())
		return ERROR;
	return SUCCESS;
}

bool RNP::doAddition() {
	double nbr = _rnp.top();
	_rnp.pop();
	_rnp.top() += nbr;
	if (checkIntOverflow())
		return ERROR;
	return SUCCESS;
}

bool RNP::doMultiplication() {
	double nbr = _rnp.top();
	_rnp.pop();
	_rnp.top() *= nbr;
	if (checkIntOverflow())
		return ERROR;
	return SUCCESS;
}

bool RNP::doDivision() {
	double nbr = _rnp.top();
	if (nbr == 0) {
		std::cerr << "An Operation is trying to divide by 0" << std::endl;
		return ERROR;
	}
	_rnp.pop();
	_rnp.top() /= nbr;
	if (checkIntOverflow())
		return ERROR;
	return SUCCESS;
}

bool RNP::checkIntOverflow() const {
	if (_rnp.top() < std::numeric_limits<int>::min()) {
		std::cerr << "An Operation led to a result Overflowing an Int" << std::endl;
		return ERROR;
	}
	if (_rnp.top() > std::numeric_limits<int>::max()) {
		std::cerr << "An Operation led to a result Overflowing an Int" << std::endl;
		return ERROR;
	}
	return SUCCESS;
}
