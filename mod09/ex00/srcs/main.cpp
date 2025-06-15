/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:15:59 by allan             #+#    #+#             */
/*   Updated: 2025/06/14 14:15:15 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (ERROR);
	}
	try {
		BitcoinExchange exchange(argv[1]);
		exchange.parseAmountFile();	
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
