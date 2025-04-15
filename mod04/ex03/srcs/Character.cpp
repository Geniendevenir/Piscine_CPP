/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:32:14 by allan             #+#    #+#             */
/*   Updated: 2025/04/15 20:43:53 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character() {
	//std::cout << "Character: Default Constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_floor = NULL;	
	return ;
}

Character::Character(std::string name) : _name(name) {
	//std::cout << "Character: Name Constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_floor = new Floor(NULL);	
	return ;
}

Character::Character(const Character &src) {
	//std::cout << "Character: Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Character::~Character() {
	//std::cout << "Character: Destructor" << std::endl;
	_empty_inventory();
	_delete_floor();
	return ;
}


std::string const & Character::getName() const {
	return _name;
}

Character& Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		_empty_inventory();	
		_clone_inventory(rhs);
		//_delete_floor();
		//_clone_floor();	
		_name = rhs._name;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Character &i) {
	o << i.getName();
	return o;
}
