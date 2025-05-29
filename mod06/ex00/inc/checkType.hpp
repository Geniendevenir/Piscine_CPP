/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:29:46 by adebert           #+#    #+#             */
/*   Updated: 2025/05/28 13:42:16 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKTYPE_HPP
#define CHECKTYPE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cerrno>
#include <climits>
#include <cstdlib> //strtod
#include <cfloat>
#include <cmath> //Huge_val

#define NO_OVERFLOW 0
#define INT_OVERFLOW 1
#define FLOAT_OVERFLOW 2
#define DOUBLE_OVERFLOW 3

long long isInt(const std::string &str, bool &flag);
float isFloat(const std::string &str, bool &flag);
double isDouble(const std::string &str, bool &flag);

void printOverflow();
void convertFromChar(char value);
void convertFromInt(std::string value, long long i);
void convertFromFloat(std::string value, float f);
void convertFromDouble(std::string value, double d);

bool isSpecialCase(const std::string &str);
bool willOverflowInt(std::string str);
bool willOverflowFloat(std::string str);
bool willOverflowDouble(std::string str);

bool isIntOverflow(long value);

int getDecimalNbr(const std::string &str);

bool isNumeric(const std::string &str);



#endif