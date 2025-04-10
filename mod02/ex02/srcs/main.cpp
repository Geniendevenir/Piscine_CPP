/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:19:12 by allan             #+#    #+#             */
/*   Updated: 2025/04/08 23:17:19 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	try {
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		//Fixed c( Fixed(INT_MAX) * Fixed(1));
	
		//std::cout << c << std::endl;
		
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
}