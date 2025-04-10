/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:26 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 14:53:11 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() {
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_point(10), _attack_damage(10) {
	std::cout << "Constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return ;
}


ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
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
