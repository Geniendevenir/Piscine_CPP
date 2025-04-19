/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:14:50 by allan             #+#    #+#             */
/*   Updated: 2025/04/14 01:24:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : _type("cure") {
	//std::cout << "Cure: Default Constructor" << std::endl;
	return ;
}

Cure::Cure(std::string const & type) : _type(type) {
	//std::cout << "Cure: Type Constructor" << std::endl;
	return ;
}

Cure::Cure(const Cure &src) : AMateria(src), _type("cure") {
	//std::cout << "Cure: Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Cure::~Cure() {
	//std::cout << "Cure: Destructor" << std::endl;
	return ;
}



Cure& Cure::operator=(const Cure &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}
std::string const & Cure::getType() const {
	return this->_type;
}

std::ostream &operator<<(std::ostream &o, const Cure &i) {
	o << i.getType();
	return o;
}



void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria* new_Materia = new Cure();
	return new_Materia;
}
