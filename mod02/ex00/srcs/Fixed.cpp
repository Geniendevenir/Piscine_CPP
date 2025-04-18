/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:20:58 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 12:15:36 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _fpn(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}


Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return ;
}


Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpn = rhs.getRawBits();
	return *this;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpn;
}


void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpn = raw;
	return ;
}

std::ostream &operator<<(std::ostream &o, const Fixed &i) {
	o << "The value of _nfp = " << i.getRawBits() << std::endl;
	return o;
}
