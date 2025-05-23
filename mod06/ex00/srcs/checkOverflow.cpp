/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkOverflow.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:27:35 by adebert           #+#    #+#             */
/*   Updated: 2025/05/23 19:23:07 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

bool isCharOverflow(long long value) {
	if (value < 0 || value > 255)
		return true;
	return false;
}

bool isLongOverflow(std::string value) {
	bool flag = 0;
	isInt(value, flag);
	if (flag == false && isNumeric(value))
		return true;
	return false;	
}

int isIntOverflow(long long i) {
	if (i < -std::numeric_limits<int>::min()
		|| i > std::numeric_limits<int>::max())
		return INT_OVERFLOW;
		
	if (i < std::numeric_limits<double>::min()
		|| i > std::numeric_limits<double>::max())
		return DOUBLE_OVERFLOW;
		
	if (i < std::numeric_limits<float>::min()
		|| i > std::numeric_limits<float>::max())
		return FLOAT_OVERFLOW;	
		
		
	return NO_OVERFLOW;
}

int isFloatOverflow(double f) {
	if (f < -std::numeric_limits<float>::max()
		|| f > std::numeric_limits<float>::max())
		return FLOAT_OVERFLOW;	
	return NO_OVERFLOW;	
}

bool isScientificNot(std::string value) {
	if (value[0] == '-' && value.size() > 7)
		return true;
	else if (value[0] == '+' && value.size() > 7)
		return true;
	else if (value[0] != '-' && value [0] != '+' && value.size() > 6)
		return true;
	return false;
}

/* bool isFloatOverflow(long long i) {
	
} */