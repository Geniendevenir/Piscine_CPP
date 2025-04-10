/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 18:34:19 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() {
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap: Constructor called" << std::endl;
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
