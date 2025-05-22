/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:17:45 by adebert           #+#    #+#             */
/*   Updated: 2025/05/22 17:05:28 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

void ScalarConverter::convert(std::string value) {
	if (value.empty()) {
		std::cout << "Value is empty" << std::endl;
		return;
	}
	if (value.size() == 1 && !isDigit(value[0])) {
		//Char
		//Check if displayable
	}
	else if (isInt(value)) {
		//Int
	}
	char c_value;
	int i_value;
	float f_value;
	double d_value;

	//Char: One displayable character
	//Int: {One -}, {only numbers} //Float: {One -}, {only numbers}, {One .}. {only numbers}, {f}; //double: {One -}, {numbers only}, {one .}, {numbers only}
}

bool isDigit(char c) {
}	

bool isInt(std::string value) {
}

bool isFloat(std::string value) {
}

