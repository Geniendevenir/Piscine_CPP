/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:03 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:40:18 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat() {
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}


WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound(void) const {
	std::cout << "Wrong Miaaaaaaaaew" << std::endl;
	return ;
}

std::string WrongCat::getType(void) const {
	return this->type;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs) {
	this->type = rhs.type;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const WrongCat &i) {
	o << i.getType();
	return o;
}
