/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:51 by allan             #+#    #+#             */
/*   Updated: 2025/04/16 15:25:47 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int main(void) {
	
	FragTrap Henry("Henry");
	Henry.takeDamage(INT_MAX);
	Henry.beRepaired(INT_MAX);
	Henry.beRepaired(INT_MAX);
	Henry.takeDamage(INT_MIN);
	//Test Energy, should be out of energy for the 51th attempt 
/* 	for (int i = 0; i < 51; i++) {
		Henry.attack("Momo");
	} */
	return 0;
}