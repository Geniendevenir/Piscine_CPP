/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:03:07 by allan             #+#    #+#             */
/*   Updated: 2025/03/31 02:20:43 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.hpp"

Contact::Contact(void) {	
	return ;
}

Contact::~Contact(void) {
	return ;
}

int Contact::create(void) {
	int result;
	
	std::cout << "Contact first name: ";
	result = check_input(this->_first_name, true);
	if (result != SUCCESS)
		return result;
		
	std::cout << "Contact _last_name: ";
	result = check_input(this->_last_name, true);
	if (result != SUCCESS)
		return result;
	
	std::cout << "Contact _nickname: ";
	result = check_input(this->_nickname, true);
	if (result != SUCCESS)
		return result;
	
	std::cout << "Contact darkest secret: ";
	result = check_input(this->_darkest_secret, true);
	if (result != SUCCESS)
		return result;
	
	std::cout << "Contact phone number: ";
	result = check_input(this->_phone_number, true);
	if (result != SUCCESS)
		return result;
	std::cout << std::endl;		
	return SUCCESS;	
}

std::string Contact::getInfo(int info) const {
	if (info == FIRST_NAME)
		return this->_first_name;
	else if (info == LAST_NAME)
		return this->_last_name;
	else if (info == NICKNAME)
		return this->_nickname;
	else if (info == PHONE)
		return this->_phone_number;
	else if (info == SECRET)
		return this->_darkest_secret;
	return "";	
}
