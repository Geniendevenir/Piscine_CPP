/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:04:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/03 14:09:21 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	this->options[0] = "DEBUG";
	this->options[1] = "INFO";
	this->options[2] = "WARNING";
	this->options[3] = "ERROR";
	
	this->mfp_level[0] = &Harl::debug;	
	this->mfp_level[1] = &Harl::info;	
	this->mfp_level[2] = &Harl::warning;	
	this->mfp_level[3] = &Harl::error;	
}

Harl::~Harl() {
}


void Harl::debug(void) {
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL burger. I really do!\n" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (this->options[i] == level) {
			(this->*mfp_level[i])();
			break;
		}
	}
}
