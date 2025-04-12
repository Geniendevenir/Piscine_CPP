/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:03 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:39:19 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() {
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	return ;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Default Copy called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

void Dog::makeSound(void) const {
	std::cout << "BAAAARK" << std::endl;
	return ;
}

std::string Dog::getType(void) const {
	return this->type;
}

Dog& Dog::operator=(const Dog &rhs) {
	this->type = rhs.type;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Dog &i) {
	o << i.getType();
	return o;
}
