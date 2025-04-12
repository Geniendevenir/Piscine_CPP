/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:03 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:38:48 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() {
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	return ;
}


Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	return ;
}

void Cat::makeSound(void) const {
	std::cout << "Miaaaaaaaaew" << std::endl;
	return ;
}

std::string Cat::getType(void) const {
	return this->type;
}

Cat& Cat::operator=(const Cat &rhs) {
	this->type = rhs.type;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Cat &i) {
	o << i.getType();
	return o;
}
