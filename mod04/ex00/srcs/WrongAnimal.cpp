/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:26:23 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:41:06 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "Wrong Animal Default Constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "Wrong Animal Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal Destructor called" << std::endl;
	return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs) {
	this->type = rhs.type;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "*WrongAnimals don't make sound*" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;	
}

std::ostream &operator<<(std::ostream &o, const WrongAnimal &i) {
	o << i.getType();
	return o;
}
