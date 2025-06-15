/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:23:14 by allan             #+#    #+#             */
/*   Updated: 2025/06/14 15:09:25 by allan            ###   ########.fr       */
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


/* BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
	return ;
}
*/

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

/* BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	//define behavior: instA = instB;
	//if (this != &rhs)
		//copy value;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i) {
	//define behavior: std::cout << instance;
	return o;
} */


//////////////////////////////////////////////////////////
//					 GETTER/SETTER						//
//////////////////////////////////////////////////////////

/* std::string BitcoinExchange::getSomething(void) const {
	//return this->something;
}

void BitcoinExchange::setSomething(std::string new_value) {
	//if (new_value >= x)
	//this->something = new_value;
	return ;
} */


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


void BitcoinExchange::printSmart(float value) const {
    // Treat very small values as 0
    if (std::fabs(value) < 1e-10) {
        std::cout << 0;
        return;
    }

    // If value is "effectively" an integer (e.g., 42.0)
    if (std::fabs(value - std::floor(value)) < 1e-10) {
        std::cout << static_cast<long>(value);  // cast to int for clean display
    } else {
        std::cout << std::fixed << std::setprecision(6) << value;
        
        // Optionally strip trailing zeros:
        std::string out;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(6) << value;
        out = oss.str();

        // Remove trailing zeros and decimal point if necessary
        while (!out.empty() && out[out.size() - 1] == '0') out.erase(out.size() - 1);
        if (!out.empty() && out[out.size() - 1] == '.') out.erase(out.size() - 1);

        std::cout << out;
    }
}

void BitcoinExchange::printDataLine(const std::string &date, float amount) { //HEEEEEERE
	float rate = findRate(date);	
	
	float price = rate * amount;
	std::cout << date << " => " << amount << " = ";
	printSmart(price);
	std::cout << std::endl;
}

float BitcoinExchange::findRate(const std::string &date) {
	std::map<std::string, float>::const_iterator it = _rateData.upper_bound(date);
	if (it != _rateData.begin())
		--it;	
		
	return it->second;		
}
