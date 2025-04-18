/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 18:40:49 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


//	-------------------------------------------------	//
// 	-			ScavTrap Constructor 				-	//
//	-------------------------------------------------	//


ScavTrap::ScavTrap() {
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap: Param Constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << "ScavTrap: Copy Constructor called" << std::endl;
	*this = src;
	return ;
}


ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called" << std::endl;
	return ;
}

std::string ScavTrap::getName(void) const {
	return this->_name;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const ScavTrap &i) {
	o << i.getName();
	return o;	
}



//	-------------------------------------------------	//
// 	-			ScavTrap Action Method				-	//
//	-------------------------------------------------	//


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
		std::cout << "Claptrap " << this->_name << " has no Energy Left to repair itself" << std::endl;
		return ;
	}
	while (amount > 0 && this->_hit_points < 100) {
		this->_hit_points += 1;	
		hp_repaired++;
		amount--;
	}
	this->_energy_point--;
	std::cout << "ClapTrap " << this->_name << " repair itself " << hp_repaired << " hitpoints" << std::endl;
	return ;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}