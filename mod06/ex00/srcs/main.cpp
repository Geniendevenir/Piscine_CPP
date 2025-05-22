/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:42:34 by adebert           #+#    #+#             */
/*   Updated: 2025/05/22 12:48:19 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char**argv) {
	if (argc != 2) {
		std::cerr << "Error: Must provide one argument" << std::endl;	
		return 1;
	}
	ScalarConverter converter;
	converter.convert(static_cast<std::string>(argv[1]));
	return 0;
}