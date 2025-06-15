/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:05:11 by allan             #+#    #+#             */
/*   Updated: 2025/06/14 15:07:06 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib> //for std::atoi()
#include <iomanip> //std::setprecision()
#include <cmath>

/* 
1 - Check nbr of arguments: OK
2 - Try opening the data.csv: OK
4 - Try opening the other file: OK
3 - Put its content in a map
5 - Parse that file
6 - Put its content in a map
7 - Do the search/Print


function:
-> std::atoi
-> std::getline(), std::string::npos == error
-> str_name.substr()
-> std_name.length()
-> std::isstringstream ss(std::string); ss.fail() || !ss.eof()
-> std::isdigit

continue
*/

#define SUCCESS 0
#define ERROR 1

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		
		std::ifstream _rateFile;
		std::ifstream _amountFile;
		std::map<std::string, float> _rateData;
		
		void rateCsvToMap();
		
		//PARSER
		bool checkLine(const std::string &line);
		bool checkDate(const std::string &date);
		bool checkAmount(const std::string &amount, float &value, const std::string&line);

		//FINDER
		void printSmart(float value) const;
		void printDataLine(const std::string &date, float amount);
		float findRate(const std::string &date);
		
	public:
		BitcoinExchange(const std::string &amountFileName);
		~BitcoinExchange();

/* 		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		std::string getSomething(void) const;
		void setSomething(std::string new_value); */

		//PARSER
		void parseAmountFile();
};

//std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);

#endif