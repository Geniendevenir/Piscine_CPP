/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource_action.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:52 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 16:20:00 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


void MateriaSource::learnMateria(AMateria* to_learn) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = to_learn;
			//std::cout << "MateriaSource has learned " << to_learn->getType() << std::endl;
			return ;
		}
	}
	//std::cout << "MateriaSource Inventory is full" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			if (type == "ice")
				return new Ice();
			else if (type == "cure")
				return new Cure();	
		}
	}
	std::cout << "No Materia of type " << type << " has been learned" << std::endl;
	return NULL;
}

void MateriaSource::_empty_inventory() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	//std::cout << "Materia Source: Inventory has been emptied" << std::endl;	
	return ;
}

void MateriaSource::_clone_inventory(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i]) {
				_inventory[i] = rhs._inventory[i]->clone();
			}
		}
	}
	//std::cout << "Materia Source: Has clone another Materia Source" << std::endl;
	return ;
}