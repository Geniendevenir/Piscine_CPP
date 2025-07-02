/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:23:14 by allan             #+#    #+#             */
/*   Updated: 2025/07/02 14:56:31 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(const std::string &amountFileName) {
	_rateFile.open("data.csv");
	if (!_rateFile)
		throw std::invalid_argument("Error: File data.csv couldnt open");
		
	_amountFile.open(amountFileName.c_str());
	if (!_amountFile)
		throw std::invalid_argument("Error: File " + amountFileName + " couldnt open");
	rateCsvToMap();
	return ;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
	return ;
}


BitcoinExchange::~BitcoinExchange() {
	if (_rateFile)
		_rateFile.close();
		
	if (_amountFile)
		_amountFile.close();
		
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_rateData = rhs._rateData;
	}
		
	return *this;
}

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////

void BitcoinExchange::rateCsvToMap() {
	std::string line;

	std::getline(_rateFile, line);
	while (std::getline(_rateFile, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		
		std::getline(ss, date, ',');
		std::getline(ss, valueStr);

		float value;
		std::istringstream(valueStr) >> value;
		_rateData[date] = value;
	}
}

void BitcoinExchange::parseAmountFile() {
	std::string line;
	std::getline(_amountFile, line);
	
	while (std::getline(_amountFile, line)) {
		checkLine(line);
	}
}

bool BitcoinExchange::checkLine(const std::string &line) {
	std::string::size_type sep = line.find(" | ");
	if (sep == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ERROR;
	}
		
	std::string date = line.substr(0, sep);
	std::string amount_str = line.substr(sep + 3);
	if (checkDate(date) == ERROR) {
		std::cout << "Error: Date has the wrong format => " << line << std::endl;
		return ERROR;
	}
	
	float value = 0.0;
	if (checkAmount(amount_str, value, line) == ERROR)
		return ERROR;

	printDataLine(date, value); 
	return SUCCESS;
}

bool BitcoinExchange::checkDate(const std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return ERROR;
	
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return ERROR;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 2000 || year > 2025)
		return ERROR;
	if (month <= 0 || month > 12)
		return ERROR;
	if (day <= 0 || day > 31)
		return ERROR;
	return SUCCESS;
}

bool BitcoinExchange::checkAmount(const std::string &amount, float &value, const std::string &line) {
	std::string trueAmount;
	trueAmount = amount;
	if (amount[amount.size() - 1] == 'f')
		trueAmount = amount.substr(0, amount.size() - 1);
		
	std::istringstream ss (trueAmount);
	
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		std::cout << "Error: Amount has the wrong format => " << line << std::endl;
		return ERROR;
	}
	
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return ERROR;
	}

	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return ERROR;
	}
	
	return SUCCESS;
}

void BitcoinExchange::printDataLine(const std::string &date, double amount) {
	double rate = findRate(date);	
	
	double price = rate * amount;
	std::cout << date << " => " << amount << " = " << price << std::endl;
}

float BitcoinExchange::findRate(const std::string &date) {
	std::map<std::string, float>::const_iterator it = _rateData.upper_bound(date);
	if (it != _rateData.begin())
		--it;	
		
	return it->second;		
}
