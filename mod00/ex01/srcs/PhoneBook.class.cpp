/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:34:54 by allan             #+#    #+#             */
/*   Updated: 2025/03/29 14:23:11y allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++) {
		this->_occupied[i] = false;
	}
	this->_contact_count = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::add(Contact& new_contact)
{
	int index;

	//add contact if arr not full
	for (int i = 0; i < 8; i++) {
		if (this->_occupied[i] == false) {
			this->_contact[i] = new_contact;
			this->_occupied[i] = true;
			this->_contact_count++;
			return ;
		}
	}
	//add contact / overwrite the oldest
	index = this->_contact_count % 8;
	this->_contact[index] = new_contact;
	this->_contact_count++;
	return ;
}

int PhoneBook::search(void) const
{
	std::string index;
	int i;

	PhoneBook::_print_contact_tab();
	
	//get Contact Index and Convert it to an int
	std::cout << "\nEnter Contact Index: ";	
	if (check_input(index, false) == ERROR)
		return ERROR;
	std::cout << std::endl;	
	i = 0;
	if (safe_string_to_int(i, index) == ERROR)	
		return ERROR;	
	
	//check if contact exists and add it
	if (!this->_occupied[i]) {
		std::cout << "No Contact Found at this Index\n" << std::endl;
		return NOT_FOUND;		
	}
	_print_contact(this->_contact[i]);	
	return FOUND;
}

void PhoneBook::_print_contact_tab(void) const
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (this->_occupied[i] == true) {
			std::cout << "|" << std::setw(10) << i;
			_print_truncate(this->_contact[i].getInfo(FIRST_NAME));	
			_print_truncate(this->_contact[i].getInfo(LAST_NAME));	
			_print_truncate(this->_contact[i].getInfo(NICKNAME));			
			std::cout << "|" << std::endl;
		}
	}	
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
	return ;
}

void PhoneBook::_print_truncate(const std::string &info) const
{
	std::cout << "|";

	int lenght = info.length();

	int spaces = 10 - lenght;
	if (spaces > 0) {
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
	}

	for (int i = 0; i < 10 - spaces; i++) {
		if (lenght >= 10 && i == 9) {
			std::cout << ".";
			break ;
		}
		else
			std::cout << info[i]; 
	}
}

void PhoneBook::_print_contact(const Contact &contact) const {
	std::cout << "First Name: " << contact.getInfo(FIRST_NAME) << std::endl;
	std::cout << "Last Name: " << contact.getInfo(LAST_NAME) << std::endl;
	std::cout << "Nickname: " << contact.getInfo(NICKNAME) << std::endl;
	std::cout << "Phone Number: " << contact.getInfo(PHONE) << std::endl;
	std::cout << "Darkest Secret: " << contact.getInfo(SECRET) << std::endl;
	std::cout << std::endl;
}
