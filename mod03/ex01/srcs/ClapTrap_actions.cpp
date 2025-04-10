/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_actions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:51:41 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 14:32:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


void ClapTrap::attack(const std::string& target) {
	if (this->_energy_point	<= 0) {
		std::cout << "ClapTrap " << this->_name << " has no Energy Left to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;	
	this->_energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	int damage_taken = 0;
	
	while (amount > 0 && this->_hit_points > 0) {
		this->_hit_points -= 1;	
		damage_taken++;
		amount--;
	}
	std::cout << "ClapTrap " << this->_name << " has taken " << damage_taken << " damages" << std::endl;	
	if (this->_hit_points == 0)
		std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount) {
	int hp_repaired = 0;

	if (this->_energy_point	<= 0) {
		std::cout << "ClapTrap " << this->_name << " has no Energy Left to repair itself" << std::endl;
		return ;
	}
	while (amount > 0 && this->_hit_points < 10) {
		this->_hit_points += 1;	
		hp_repaired++;
		amount--;
	}
	this->_energy_point--;
	std::cout << "ClapTrap " << this->_name << " repair itself " << hp_repaired << " hitpoints" << std::endl;
	return ;
}