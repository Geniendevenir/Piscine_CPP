/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:20:58 by allan             #+#    #+#             */
/*   Updated: 2025/04/04 01:55:59by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _fpn(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//Constructor: Int to Fixed
Fixed::Fixed(int const nbr) {
	if (nbr > (INT_MAX >> _fractional_bits) || nbr < (INT_MIN >> _fractional_bits)) 
		throw std::overflow_error("Error: nbr int constructor is going to overflow"); 
	_fpn = nbr << _fractional_bits;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

//Constructor: Float to Fixed
Fixed::Fixed(float const nbr) {
	float rounded = nbr	* (1 << _fractional_bits);
	if (rounded > INT_MAX || rounded < INT_MIN)
		throw std::overflow_error("Error: nbr float constructor is going to overflow");
	_fpn = roundf(rounded);
	std::cout << "Float constructor called" << std::endl;
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




//Fixed to Float
float Fixed::toFloat(void) const {
	return static_cast<float>(_fpn) / (1 << _fractional_bits);
}

//Fixed to Int
int Fixed::toInt(void) const {
	return this->_fpn >> this->_fractional_bits;
}


Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpn = rhs._fpn;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &i) {
	o << i.toFloat();
	return o;
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
