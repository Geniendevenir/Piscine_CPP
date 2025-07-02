/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:05:11 by allan             #+#    #+#             */
/*   Updated: 2025/07/02 14:52:14 by adebert          ###   ########.fr       */
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
		void printDataLine(const std::string &date, double amount);
		float findRate(const std::string &date);
		
	public:
		BitcoinExchange(const std::string &amountFileName);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		//PARSER
		void parseAmountFile();
};

#endif