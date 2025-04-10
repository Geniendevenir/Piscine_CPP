/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:12 by allan             #+#    #+#             */
/*   Updated: 2025/04/07 23:22:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}


/* 
_fractional_bits = 8;

int a = 42;

int binaire a = 				00000000 00000000 00000000 00101010

int a -> fixed_point a =		*Shift all bits by fractional bits (8) to the right and fill the rest with 0*
								*Each time we shift a bit number to the right it's like multiplying it's decimal representation by 2*
								*So if we shift * bits to the right it's like doing decimal_repr * 2 tot he power of 8; (256)*
								
								fixed a = int a << 8;
								00000000 00000000 00101010 00000000 = 10752; 

fixed_point a -> int a =		The inverse:
								int a = fixed a >> 8;

int a = 42.42;
								
float a -> fixed_point a =		roundf(float a * (1 << fractional_bits));		
								1 => 								00000000 00000000 00000000 00000001
								(1 << fractional_bits) => 			00000000 00000000 00000001 00000000	
								float a 42.42 =>					01000010 00101001 10101110 00010100	
								42.42 * (1 << fractional_bits) => 	01000010 00101001 10101111 00010100	=> 42.420975;
								roundf(float a * (1 << fractional bits)

fixed_point a => float a = Don't have to do it		



OVERFLOW ISSUES (for Conversion to Fixed with 8 fractional Bits):

Int to Fixed:
	-> If nbr < 



All the same:
_fpn << _fractional_bits;
_fnp * (1 << _fractional_bits);			=> Same as first but used with roundf so it needs to be done like that
_fnp * 256								=> Straigthfoward but not clear that where are shifting bits	

*/