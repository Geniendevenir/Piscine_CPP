/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:17:45 by adebert           #+#    #+#             */
/*   Updated: 2025/05/28 15:57:58 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "checkType.hpp"

//////////////////////////////////////////////////////////
//						 CONSTRUCTOR					//
//////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter() {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
	return ;	
}

ScalarConverter::~ScalarConverter() {
	return ;
}


//////////////////////////////////////////////////////////
//						 OPERATOR						//
//////////////////////////////////////////////////////////

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this != &rhs) {
		return *this;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &o, const ScalarConverter &i) {
	o << &i << std::endl;
	return o;
}

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

void ScalarConverter::convert(std::string str) {
	bool flag = 0;
	if (str.empty()) {
		std::cout << "Value is empty" << std::endl;
		return ;
	}
		
	if (isSpecialCase(str))
		return ;
	
	if (str.size() == 1 && !std::isdigit(str[0])) {
		std::cout << "CHAR" << std::endl;	
		return convertFromChar(str[0]);
	}
		
	long long i = isInt(str, flag);
	if (flag == true) {
		std::cout << "INT" << std::endl;
		return convertFromInt(str, i);
	}
		
	float f = isFloat(str, flag);
	if (flag == true) {
		std::cout << "FLOAT" << std::endl;
		return convertFromFloat(str, f);
	}
		
	double d = isDouble(str, flag);	
	if (flag == true) {
		std::cout << "DOUBLE" << std::endl;
		return convertFromDouble(str, d);
	} else if (willOverflowDouble(str)) {
		printOverflow();
		return ;
	}
	
	std::cout << "Error: Invalid input" << std::endl;		
	return ;
}



