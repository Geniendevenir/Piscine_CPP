/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:09:38 by allan             #+#    #+#             */
/*   Updated: 2025/04/13 01:22:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	return ;
}


Account::Account(int deposit) : _amount(deposit){
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
	return ;
}


Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}




void Account::makeDeposit( int deposit ) {
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;	
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	
}

bool Account::makeWithdrawal( int withdrawal ) {
	int p_amount = _amount;
	if (withdrawal <= _amount) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return 0;
	}
	else {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
		return 1;
	}
	return 0;
}

int	 Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}


void Account::_displayTimestamp( void ) {
	std::time_t now;
	std::time(&now);
	
	std::tm* localTime = std::localtime(&now);
	
	std::ostringstream os;
	os << "["
		<< std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << (localTime->tm_mday)
		<< "_"
		<< std::setw(2) << std::setfill('0') << (localTime->tm_hour)
		<< std::setw(2) << std::setfill('0') << (localTime->tm_min)
		<< std::setw(2) << std::setfill('0') << (localTime->tm_sec)
		<< "]";
	std::cout << os.str();	
}
