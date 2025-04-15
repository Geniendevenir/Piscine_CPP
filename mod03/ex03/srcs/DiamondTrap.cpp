/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 17:47:16 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap: Default Constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name), _hit_points(10), _energy_point(10), _attack_damage(10) {
	std::cout << "DiamondTrap: Constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	std::cout << "DiamondTrap: Copy Constructor called" << std::endl;
	*this = src;
	return ;
}


DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return ;
}

std::string DiamondTrap::getName(void) const {
	return this->_name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_point = rhs._energy_point;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const DiamondTrap &i) {
	o << i.getName();
	return o;	
}
