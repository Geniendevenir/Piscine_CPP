/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:51:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 22:13:31 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "str Address: " << &str << std::endl;
	std::cout << "stringPTR Address: " << stringPTR << std::endl;
	std::cout << "stringREF Address: " << &stringREF << std::endl;

	std::cout << std::endl;	
	
	std::cout << "str Value: " << str << std::endl;
	std::cout << "stringPTR Value: " << *stringPTR << std::endl;
	std::cout << "stringREF Value: " << stringREF << std::endl;
	
	return 0;
}
