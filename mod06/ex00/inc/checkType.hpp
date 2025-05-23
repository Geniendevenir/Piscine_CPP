/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:46 by adebert           #+#    #+#             */
/*   Updated: 2025/05/23 19:16:19 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKTYPE_HPP
#define CHECKTYPE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

#define NO_OVERFLOW 0
#define INT_OVERFLOW 1
#define FLOAT_OVERFLOW 2
#define DOUBLE_OVERFLOW 3

/* enum Type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
}; */

long long isInt(const std::string &str, bool &flag);
float isFloat(const std::string &str, bool &flag);
double isDouble(const std::string &str, bool &flag);

void printOverflow();
void printFormChar(char value);
void printFormInt(std::string value, long long i);
void printFormFloat(std::string value, float f);
void printFormDouble(std::string value, double d);

bool isCharOverflow(long long value);
bool isLongOverflow(std::string value);
int isIntOverflow(long long i);
int isFloatOverflow(double f);


bool isScientificNot(std::string value);


bool isNumeric(const std::string &str);



#endif