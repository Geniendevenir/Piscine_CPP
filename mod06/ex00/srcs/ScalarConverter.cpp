/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:17:45 by adebert           #+#    #+#             */
/*   Updated: 2025/05/23 19:02:09 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "checkType.hpp"

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

void ScalarConverter::convert(std::string str) {
	bool flag = 0;
	if (str.empty()) {
		std::cout << "Value is empty" << std::endl;
		return ;
	}
		
	if (str.size() == 1 && !std::isdigit(str[0]))
		return printFormChar(str[0]);
		
	if (isLongOverflow(str)) {
		std::cout << "LONG OVERFLOW" << std::endl;
		return printOverflow();
	}
		
	long long i = isInt(str, flag);
	if (flag == true) {
		std::cout << "INT" << std::endl;
		return printFormInt(str, i);
	}
		
	float f = isFloat(str, flag);
	if (flag == true) {
		std::cout << "FLOAT" << std::endl;
		return printFormFloat(str, f);
	}
		
	double d = isDouble(str, flag);	
	if (flag == true) {
		std::cout << "DOUBLE" << std::endl;
		return printFormDouble(str, d);
	}
	
	std::cout << "Invalid input" << std::endl;		
	return ;
}



