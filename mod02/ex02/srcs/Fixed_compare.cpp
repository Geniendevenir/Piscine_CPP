/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_compare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:48:36 by allan             #+#    #+#             */
/*   Updated: 2025/04/08 02:50:59by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

bool Fixed::operator>(const Fixed &rhs) const {
	if (this->_fpn > rhs._fpn)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	if (this->_fpn >= rhs._fpn)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &rhs) const {
	if (this->_fpn < rhs._fpn)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	if (this->_fpn <= rhs._fpn)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &rhs) const {
	if (this->_fpn == rhs._fpn)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	if (this->_fpn != rhs._fpn)
		return true;
	return false;
}