/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:09:44 by adebert           #+#    #+#             */
/*   Updated: 2025/05/23 19:28:53 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

void printOverflow() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void printFormChar(char value) {
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	
	if (!std::isprint(value))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: " << value << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void printFormInt(std::string value, long long i) {
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
		
	if (i < 0 || i > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: " << c << std::endl;
		
	if (isIntOverflow(i) == INT_OVERFLOW)
		std::cout << "int: impossible" << std::endl;
	else		
		std::cout << "int: " << i << std::endl;

		
	if (i == 0) {
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return ;
	}
	
	if (isScientificNot(value))	
		std::cout << "float: " << f << std::endl;
	else	
		std::cout << "float: " << f << ".0f" << std::endl;

	if (isScientificNot(value))	
		std::cout << "double: " << d << std::endl;
	else	
		std::cout << "double: " << d << ".0" << std::endl;
	
}

void printFormFloat(std::string value, float f) {
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	std::string d = value.substr(0, value.size() - 1);
	
	if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << value << std::endl;
	std::cout << "double: " << d << std::endl;
}

//ADD DOUBLE OVERFLOW in printFLOAT and printDOUBLE
//ADD FLOAT OVERFLOW in printFLOAT
//ADD INT OVERFLOW in printFLOAT and printDOUBLE 
void printFormDouble(std::string value, double d) {
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
		
	if (i < 0 || i > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	if (isFloatOverflow(d) == FLOAT_OVERFLOW)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}