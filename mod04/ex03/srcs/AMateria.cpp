/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:14:50 by allan             #+#    #+#             */
/*   Updated: 2025/04/15 20:43:44 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Materia") {
	//std::cout << "AMateria: Default Constructor" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	//std::cout << "AMateria: Type Constructor" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria &src) {
	//std::cout << "AMateria: Copy Constructor" << std::endl;
	*this = src;
	return ;
}

AMateria::~AMateria() {
	//std::cout << "AMateria: Destructor" << std::endl;
	return ;
}

AMateria& AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const AMateria &i) {
	o << i.getType();
	return o;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* A Materia without a type does nothing to " << target.getName() << " *" << std::endl;
}
