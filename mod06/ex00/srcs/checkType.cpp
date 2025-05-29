/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:21 by adebert           #+#    #+#             */
/*   Updated: 2025/05/28 13:22:14 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

bool isSpecialCase(const std::string &str) {
	if (str == "+inff" || str == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (1);
	} else if (str == "-inff" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	} else if (str == "nanf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}
	return (0);
}

bool isNumeric(const std::string &str) {
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;	
	}
	return true;
}

long long isInt(const std::string &str, bool &flag) {
	std::istringstream iss(str);
	long long i = 0;
	iss >> std::noskipws >> i;
	flag = iss.eof() && !iss.fail();
	return i;
}

float isFloat(const std::string &str, bool &flag) {
	float f = 0.0;
	if (str.empty() || str[str.size() -1] != 'f') {
		flag = false;
		return f;
	}
	
	std::string noF = str.substr(0, str.size() - 1);	
	std::istringstream iss(noF);
	iss >> std::noskipws >> f;
	flag = iss.eof() && !iss.fail();
	return f;
}

double isDouble(const std::string &str, bool &flag) {
	double d = 0.0;
	if (str.empty() || str[str.size() -1] == 'f') {
		flag = false;	
		return d;
	}
	
	std::istringstream iss(str);
	iss >> std::noskipws >> d;
	flag = iss.eof() && !iss.fail();
	return d;
}

int getDecimalNbr(const std::string &str) {
	int i = 0;
	int dec = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		return 0;	
	i++;
	while (str[i] && str[i] != 'f') {
		i++;
		dec++;
	}
	return dec;
}

