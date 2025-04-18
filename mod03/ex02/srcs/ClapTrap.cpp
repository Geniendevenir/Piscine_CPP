/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 18:30:07 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	-------------------------------------------------	//
// 	-			ClapTrap Constructor 				-	//
//	-------------------------------------------------	//


ClapTrap::ClapTrap() {
	std::cout << "ClapTrap: Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_point(10), _attack_damage(10) {
	std::cout << "ClapTrap: Constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap: Copy Constructor called" << std::endl;
	*this = src;
	return ;
}


ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const ClapTrap &i) {
	o << i.getName();
	return o;	
}




//	-------------------------------------------------	//
// 	-			ClapTrap Actions Method				-	//
//	-------------------------------------------------	//


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