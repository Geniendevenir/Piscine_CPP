/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_managment.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:51 by allan             #+#    #+#             */
/*   Updated: 2025/03/31 01:19:35 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.hpp"

int check_input(std::string& input, bool check_empty)
{
	std::getline(std::cin, input);
	
	
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error: Input Error\n" << std::endl;	
		return ERROR;
	}				
	if (check_empty == true && input.empty()) {
		std::cout << "Contact Information can not be empty" << std::endl;		
		std::cout << "Contact has not been saved\n" << std::endl;	
		return EMPTY;
	}	
	return VALID;
}

int	safe_string_to_int(int &nbr, const std::string &str)
{
	std::istringstream iss(str);
	iss >> nbr; 

	if (iss.fail() || !iss.eof()) {
		std::cout << "Error: Index should be a digit between 0 and 7 included\n" << std::endl;	
		return ERROR;
	}
	return SUCCESS;
}
