/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:38:02 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


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
