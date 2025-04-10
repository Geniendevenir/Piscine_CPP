/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:49:54 by allan             #+#    #+#             */
/*   Updated: 2025/04/08 23:19:45 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <stdexcept>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(int const nbr);
		Fixed(float const nbr);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		
		float toFloat(void) const;	
		int toInt(void) const;	

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		Fixed &operator=(const Fixed &rhs);
		
		bool operator>(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

	private:
		int _fpn;	
		static const int _fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif