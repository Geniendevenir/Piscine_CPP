/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:09:44 by adebert           #+#    #+#             */
/*   Updated: 2025/05/26 15:37:08by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

void convertFromChar(char value) {
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	
	if (!std::isprint(value))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertFromInt(std::string value, long long i) {
	if (willOverflowInt(value)) {
		printOverflow();
		return ;
	}

	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
		
	if (i < 0 || i > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: '" << c << "'" << std::endl;
		
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void convertFromFloat(std::string value, float f) {
	if (willOverflowFloat(value)) {
		printOverflow();
		return ;
	}
	
	char c = static_cast<char>(f);
	long l = static_cast<long>(f); //To Check F/I overflow
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	
	if (f < 0 || f > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: '" << c << "'" << std::endl;

	if (isIntOverflow(l))	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	int dec = getDecimalNbr(value);
	if (dec == 0)
		dec = 1;

	std::cout << "float: " << std::fixed << std::setprecision(dec) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(dec) << d << std::endl;
}

void convertFromDouble(std::string value, double d) {
	if (willOverflowDouble(value)) {
		printOverflow();
		return ;
	}
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
		
	if (d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayble" << std::endl;
	else	
		std::cout << "char: '" << c << "'" << std::endl;
	if (willOverflowInt(value))	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	int dec = getDecimalNbr(value);
	if (dec == 0)
		dec = 1;

	if (willOverflowFloat(value))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(dec) << d << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(dec) << d << std::endl;
}