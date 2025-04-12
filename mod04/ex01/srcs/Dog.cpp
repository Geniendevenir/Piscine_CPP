/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:03 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 21:20:57 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() {
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Default Copy called" << std::endl;
	this->_brain = new Brain(*src._brain);
	return ;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void Dog::makeSound(void) const {
	std::cout << "BAAAARK" << std::endl;
	return ;
}

std::string Dog::getType(void) const {
	return this->type;
}

Brain* Dog::getBrain(void) const {
	return this->_brain;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;

		Animal::operator=(rhs)	;
		
		Brain* new_brain = new Brain(*rhs._brain);
		delete this->_brain;
		this->_brain = new_brain;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Dog &i) {
	o << i.getType();
	return o;
}
