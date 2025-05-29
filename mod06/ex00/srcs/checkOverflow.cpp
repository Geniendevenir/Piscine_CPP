/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkOverflow.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:27:35 by adebert           #+#    #+#             */
/*   Updated: 2025/05/28 13:46:42 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

bool willOverflowInt(std::string str) {
	errno = 0;
	char *end;
	long result = std::strtol(str.c_str(), &end, 10);

	if (errno == ERANGE || result < INT_MIN || result > INT_MAX)
		return true;
		
	return false;	
}

bool isIntOverflow(long value) {
	return (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min());
}


bool willOverflowFloat(std::string str) {
	errno = 0;
	char *end;
	double result = std::strtod(str.c_str(), &end);

	if (errno == ERANGE || result < -FLT_MAX || result > FLT_MAX)
		return true;
		
	return false;	
}

bool willOverflowDouble(std::string str) {
	errno = 0;
	char *end;
	double result = std::strtod(str.c_str(), &end);

	if (errno == ERANGE || result >= HUGE_VAL || result <= -HUGE_VAL)
		return true;
		
	return false;	
}

void printOverflow() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/* bool isScientificNot(std::string value) {
	if (value[0] == '-' && value.size() > 7)
		return true;
	else if (value[0] == '+' && value.size() > 7)
		return true;
	else if (value[0] != '-' && value [0] != '+' && value.size() > 6)
		return true;
	return false;
} */
