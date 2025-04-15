/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_action.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:32:14 by allan             #+#    #+#             */
/*   Updated: 2025/04/15 20:46:16 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m->clone();
			delete m;
			//std::cout << "Materia has been equiped to slot " << i << std::endl;
			return ;
		}
	}
	//std::cout << "Inventory is full" << std::endl; //Messages should be deleted
	return ;
}

void Character::unequip(int idx) {
	if (_inventory[idx]) {
		_add_to_floor(_inventory[idx]);
		//std::cout << _name << ": has dropped " << _inventory[idx] << " on the floor" << std::endl;
		_inventory[idx] = NULL;
		return ;
	}
	//std::cout << _name << ": no materia to drop on the floor" << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	if (_inventory[idx]) {
		_inventory[idx]->use(target);
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
	return ;
}

void Character::_empty_inventory() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	//std::cout << _name << ": Inventory has been emptied" << std::endl;	
	return ;
}

void Character::_clone_inventory(const Character &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i]) {
				_inventory[i] = rhs._inventory[i]->clone();
			}
		}
	}
	//std::cout << _name << ": Has clone " << rhs._name << " inventory" << std::endl;
	return ;
}

void Character::_add_to_floor(AMateria *materia) {
	Floor *n = new Floor(materia);
	n->_next = _floor;
	_floor = n;
}

void Character::_delete_floor() {
	while (_floor) {
		delete _floor->_old_materia;
		Floor *temp = _floor;
		_floor = _floor->_next;
		delete temp;
		temp = NULL;
	}
	_floor = NULL;
}

/* void Character::_clone_floor(const Character &rhs) {
	Floor *curr = rhs._floor;
	while (curr) {
		_add_to_floor(curr->_old_materia);	
		curr = curr->_next;	
	}
} */