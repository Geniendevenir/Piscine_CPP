/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:21 by adebert           #+#    #+#             */
/*   Updated: 2025/05/23 19:05:20 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkType.hpp"

/* bool isNumeric(const std::string &str) {
	std::istringstream iss(str);
	double d;
	iss >> d;
	return iss.eof() && !iss.fail();
} */

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
	float f = 0.0f;
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


/* Type detectType(const std::string &str, bool &flag) {
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return TYPE_CHAR;
	else if (isInt(str))
		return TYPE_INT;
	else if (isFloat(str))
		return TYPE_FLOAT;
	else if (isDouble(str))
		return TYPE_DOUBLE;

	return TYPE_INVALID;	
} */
