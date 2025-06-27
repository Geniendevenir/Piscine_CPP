/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:18:53 by adebert           #+#    #+#             */
/*   Updated: 2025/06/27 15:25:41 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char**argv) {

	if (argc < 2) {
		std::cerr << "Error: At least one argument needed" << std::endl;
		return ERROR;
	} 
	
	PmergeMe johnson;
	if (johnson.checkInputs(argc - 1, argv + 1)) {
		std::cerr << "Error" << std::endl;
		return ERROR;
	}
	std::cerr << "Success" << std::endl;
	return SUCCESS;
}