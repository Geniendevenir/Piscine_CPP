/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 19:02:32 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//	-------------------------------------------------	//
// 	-			FragTrap Constructor 				-	//
//	-------------------------------------------------	//

FragTrap::FragTrap() {
	std::cout << "FragTrap: Default Constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap: Constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap: Copy Constructor called" << std::endl;
	*this = src;
	return ;
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called" << std::endl;
	return ;
}

std::string FragTrap::getName(void) const {
	return this->_name;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const FragTrap &i) {
	o << i.getName();
	return o;	
}




//	-------------------------------------------------	//
// 	-			FragTrap Actions Method				-	//
//	-------------------------------------------------	//


void FragTrap::attack(const std::string& target) {
	if (this->_energy_point	<= 0) {
		std::cout << "ClapTrap " << this->_name << " has no Energy Left to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;	
	this->_energy_point--;
}

void FragTrap::beRepaired(unsigned int amount) {
	int hp_repaired = 0;
	
	if (this->_energy_point	<= 0) {
		std::cout << "ClapTrap " << this->_name << " has no Energy Left to repair itself" << std::endl;
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

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " wants to highfive you" << std::endl;
}