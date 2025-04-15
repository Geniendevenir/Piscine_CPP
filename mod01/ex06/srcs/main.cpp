/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:58:45 by allan             #+#    #+#             */
/*   Updated: 2025/04/13 09:37:24 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char**argv) {
	if (argc != 2) {
		std::cout << "Error: One parameter required" << std::endl;
		return 1;
	}
	std::string level = argv[1];
	Harl harl; 
	harl.complain(level);
	return 0;
}