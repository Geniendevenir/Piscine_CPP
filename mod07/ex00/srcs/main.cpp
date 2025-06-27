/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:31:58 by allan             #+#    #+#             */
/*   Updated: 2025/06/11 10:36:14 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

struct test {
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream &o, const test& rhs) {
	o << "name = " << rhs.name << std::endl
		<< "age = " << rhs.age << std::endl;
	return o;	
}

int main( void ) {
	//SUBJECT MAIN
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	//TESTS THAT SHOULD FAIL
	
	//Different Types
/* 	float f = 42.0;
	std::string str = "Hello";
	::swap(f, str); */

	//EXTRA TESTS
	//Swap Structs
/* 	test a;
	a.age = 42;
	a.name = "Henry";
	
	test b;
	b.age = 10;
	b.name = "Thierry";
	
	std::cout << "Before Swap:" << std::endl;
	std::cout << "A:" << std::endl << a << std::endl;
	std::cout << "B:" << std::endl << b << std::endl;
	
	::swap(a, b);	
	std::cout << "After Swap:" << std::endl;
	std::cout << "A:" << std::endl << a << std::endl;
	std::cout << "B:" << std::endl << b << std::endl; */
	
	//Types which doesnt support comparaison
	//::min(a, b); //Shouldnt Work
	
	return 0;
}