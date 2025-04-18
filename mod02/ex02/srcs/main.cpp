/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:12 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 14:01:51 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	try {
		//a == b	
		Fixed a(42);
		Fixed b = a;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		//a - b
		std::cout << "a - b = " << a - b << std::endl;

		//c < d
		Fixed c(100.5f);
		Fixed d(100.0f);
		
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "min is " << Fixed::min(c, d) << std::endl;

		//e / f
		Fixed e(1000); 
		Fixed f(2.0f);
		
		std::cout << "e = " << e << std::endl;
		std::cout << "f = " << f << std::endl;
		std::cout << "e / f = " <<  e / f;
		std::cout << std::endl;


		//g INT MAX, h INT MIN
		Fixed g(INT_MAX);
		//Fixed h(INT_MIN);
		std::cout << "g = " << g << std::endl;
		//std::cout << "h = " << h << std::endl;
		
		
	} catch (const std::overflow_error&e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
		return 2;
	}
	return 0;
}

/* int main( void ) {
	try {
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	} catch (const std::overflow_error&e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
		return 2;
	}
	return 0;
} */