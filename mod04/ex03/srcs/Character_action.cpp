/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_action.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:32:14 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 16:19:33 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m->clone();
			//std::cout << "Materia " << *m << ": has been equiped to slot " << i << std::endl;
			delete m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl; //Messages should be deleted
	delete m;
	return ;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3 &&_inventory[idx]) {
		std::cout << _name << ": has dropped " << *_inventory[idx] << " on the floor" << std::endl;
		_add_to_floor(_inventory[idx]);
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << _name << ": no materia to drop on the floor" << std::endl;
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

void Character::showFloor() const {
	Floor *curr = _floor;

	while (curr) {
		if (curr->_old_materia)
			std::cout << *(curr->_old_materia) << std::endl;
		curr = curr->_next;		
	}
}

void Character::showItems() const {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			std::cout << this->getName() << ": Inventory: Slot[" << i << "]: " << *(_inventory[i]) << std::endl;
		else
			std::cout << this->getName() << ": Inventory: Slot[" << i << "]: " << "Empty" << std::endl;
	}
}
