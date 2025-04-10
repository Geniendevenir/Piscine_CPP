/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:51 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:08:39 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int main(void) {
	
	ScavTrap Henry("Henry");
	Henry.guardGate();
	Henry.takeDamage(INT_MAX);
	Henry.beRepaired(INT_MAX);
	Henry.beRepaired(INT_MAX);
	//Test Energy, should be out of energy for the 51th attempt 
/* 	for (int i = 0; i < 51; i++) {
		Henry.attack("Momo");
	} */
	return 0;
}