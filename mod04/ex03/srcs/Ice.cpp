/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:14:50 by allan             #+#    #+#             */
/*   Updated: 2025/04/14 01:24:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice") {
	//std::cout << "Ice: Default Constructor" << std::endl;
	return ;
}

Ice::Ice(std::string const & type) : _type(type) {
	//std::cout << "Ice: Type Constructor" << std::endl;
	return ;
}

Ice::Ice(const Ice &src) : AMateria(src), _type("ice") {
	//std::cout << "Ice: Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Ice::~Ice() {
	//std::cout << "Ice: Destructor" << std::endl;
	return ;
}



Ice& Ice::operator=(const Ice &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}
std::string const & Ice::getType() const {
	return this->_type;
}

std::ostream &operator<<(std::ostream &o, const Ice &i) {
	o << i.getType();
	return o;
}



void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria* new_Materia = new Ice();
	return new_Materia;
}
