/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap_actions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:51:41 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:05:37 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void ScavTrap::attack(const std::string& target) {
	if (this->_energy_point	<= 0) {
		std::cout << "ScavTrap " << this->_name << " has no Energy Left to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;	
	this->_energy_point--;
}

void ScavTrap::beRepaired(unsigned int amount) {
	int hp_repaired = 0;
	
	if (this->_energy_point	<= 0) {
		std::cout << "ScavTrap " << this->_name << " has no Energy Left to repair itself" << std::endl;
		return ;
	}
	while (amount > 0 && this->_hit_points < 100) {
		this->_hit_points += 1;	
		hp_repaired++;
		amount--;
	}
	this->_energy_point--;
	std::cout << "ScavTrap " << this->_name << " repair itself " << hp_repaired << " hitpoints" << std::endl;
	return ;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}