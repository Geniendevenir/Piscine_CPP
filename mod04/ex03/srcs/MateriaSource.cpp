/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:29:52 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 16:20:24 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
	//std::cout << "MateriaSource: Default Constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	return ;
}


MateriaSource::MateriaSource(const MateriaSource &src) {
	//std::cout << "MateriaSource: Copy Constructor" << std::endl;
	*this = src;
	return ;
}


MateriaSource::~MateriaSource() {
	//std::cout << "MateriaSource: Destructor" << std::endl;
	_empty_inventory();	
	return ;
}


MateriaSource& MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		_empty_inventory();			
		_clone_inventory(rhs);
	}
	return *this;
}
