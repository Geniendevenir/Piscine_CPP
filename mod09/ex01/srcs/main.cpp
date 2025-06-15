/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:14 by allan             #+#    #+#             */
/*   Updated: 2025/06/15 20:35:12 by allan            ###   ########.fr       */
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
		
	return SUCCESS;
}