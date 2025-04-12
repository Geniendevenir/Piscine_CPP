/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:03 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 21:21:15 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() {
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";	
	this->_brain = new Brain();
	return ;
}


Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	return ;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void Cat::makeSound(void) const {
	std::cout << "Miaaaaaaaaew" << std::endl;
	return ;
}

std::string Cat::getType(void) const {
	return this->type;
}

Brain* Cat::getBrain(void) const {
	return this->_brain;
}

Cat& Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;

		Animal::operator=(rhs)	;
		
		Brain* new_brain = new Brain(*rhs._brain);
		delete this->_brain;
		this->_brain = new_brain;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Cat &i) {
	o << i.getType();
	return o;
}
