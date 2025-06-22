/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:14 by allan             #+#    #+#             */
/*   Updated: 2025/06/22 17:36:12 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Program takes one Argument" << std::endl;
		return ERROR;
	}
	
	RNP rnp(argv[1]);
	if (rnp.parseInput())
		return ERROR;
	if (rnp.createStack())
		return ERROR;	
		
	std::cout << std::fixed << std::setprecision(0) << rnp.getResult() << std::endl;
	return SUCCESS;
}