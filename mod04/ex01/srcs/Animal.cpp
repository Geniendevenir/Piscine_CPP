/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:26:23 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 21:32:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : type("Animal") {
	std::cout << "Animal Default Constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
	return ;
}

Animal& Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "*Animals don't make sound*" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;	
}

Brain* Animal::getBrain(void) const {
	return NULL;
}

std::ostream &operator<<(std::ostream &o, const Animal &i) {
	o << i.getType();
	return o;
}
