/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_calcul.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:52:19 by allan             #+#    #+#             */
/*   Updated: 2025/04/08 16:41:57by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed Fixed::operator+(const Fixed &rhs) const {
	long long result = static_cast<long long>(this->_fpn) + rhs._fpn;
	if (result > INT_MAX || result < INT_MIN) 
		throw std::overflow_error("Error: Instance a + b will overflow");
	return Fixed(static_cast<int>(result));
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	long long result = static_cast<long long>(this->_fpn) - rhs._fpn;
	if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Error: Instance a - b will overflow");
	return Fixed(static_cast<int>(result));
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	long long result = static_cast<long long>(this->_fpn) * rhs._fpn;
	result >>= _fractional_bits;
    if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Error: Instance a * b will overflow");
	Fixed out;	
	out.setRawBits(static_cast<int>(result));
	return out;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs._fpn == 0)
        throw std::overflow_error("Division by zero");
    // Scale up numerator to preserve precision
    long long dividend = static_cast<long long>(_fpn) << _fractional_bits;
    long long result = dividend / rhs._fpn;
    // Round to nearest
    result += (dividend % rhs._fpn) >= (rhs._fpn / 2) ? 1 : 0;
    if (result > INT_MAX || result < INT_MIN)
        throw std::overflow_error("Division overflow");
    return Fixed(static_cast<int>(result));
}
