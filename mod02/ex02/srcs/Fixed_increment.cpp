/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_increment.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:03:07 by allan             #+#    #+#             */
/*   Updated: 2025/04/08 23:19:12 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed& Fixed::operator++(void) {
	if (_fpn == INT_MAX)
		throw std::overflow_error("Error: Operation Instance ++a is going to overflow");
	this->_fpn++;
	return *this;
}

Fixed Fixed::operator++(int) {
	if (_fpn == INT_MAX)
		throw std::overflow_error("Error: Operation Instance a++ is going to overflow");
	Fixed old = *this;
	this->_fpn++;
	return old;
}

Fixed& Fixed::operator--(void) {
	if (_fpn == INT_MIN)
		throw std::overflow_error("Error: Operation Instance --a is going to overflow");
	this->_fpn--;
	return *this;
}

Fixed Fixed::operator--(int) {
	if (_fpn == INT_MIN)
		throw std::overflow_error("Error: Operation Instance a-- is going to overflow");
	Fixed old = *this;
	this->_fpn--;
	return old;
}

