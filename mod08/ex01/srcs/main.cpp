/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:34:45 by allan             #+#    #+#             */
/*   Updated: 2025/06/10 14:38:45 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	//Test addNumber and throw exceptions when trying to add > N elements
	std::cout << "BASIC TEST 1" << std::endl;
	Span basic = Span(3);
	try {
		basic.addNumber(0);
		basic.addNumber(1);
		basic.addNumber(2);
		basic.addNumber(3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std:: cout << basic << std::endl;
	std::cout << std::endl;

	//Test that shortestSpan() and longestSpan() throw and error if called on a vector which size is 0 or 1;
	std::cout << "BASIC TEST 2" << std::endl;
	Span basic2 = Span(10);
	try {
		//0 Element
		basic2.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	basic2.addNumber(42);
	try {
		//1 Element
		basic2.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	//Test that shortest and longest Span work for very small vector size;
	std::cout << "BASIC TEST 3" << std::endl;
	//Subject Test
	Span basic3 = Span(5);
	basic3.addNumber(6);
	basic3.addNumber(3);
	basic3.addNumber(17);
	basic3.addNumber(9);
	basic3.addNumber(11);
	std::cout << basic3.shortestSpan() << std::endl;
	std::cout << basic3.longestSpan() << std::endl;
	std::cout << std::endl;
	
	std::cout << "BASIC TEST 4" << std::endl;
	//Test with negative value
	Span basic4 = Span(5);
	basic4.addNumber(-6);
	basic4.addNumber(3);
	basic4.addNumber(-17);
	basic4.addNumber(9);
	basic4.addNumber(-11);
	std::cout << basic4.shortestSpan() << std::endl; //-11 -(-6) = 5
	std::cout << basic4.longestSpan() << std::endl; //9 -(-17) = 26
	std::cout << std::endl;

	
	std::cout << "BASIC TEST 5" << std::endl;
	//Test with Limits
	Span basic5 = Span(5);
	basic5.addNumber(-2147483648);
	basic5.addNumber(3);
	basic5.addNumber(-17);
	basic5.addNumber(2147483647);
	basic5.addNumber(-11);
	std::cout << basic5.shortestSpan() << std::endl; //-11 -(-17) = 6
	std::cout << basic5.longestSpan() << std::endl; //INT_MAX -(-INT_MIN) = 4294967295
	std::cout << std::endl;
	
	std::cout << "BASIC TEST 6" << std::endl;
	//Test with Limits 2
	Span basic6 = Span(5);
	basic6.addNumber(0);
	basic6.addNumber(0);
	std::cout << basic6.shortestSpan() << std::endl;
	std::cout << basic6.longestSpan() << std::endl; 
	std::cout << std::endl;
	
	//////////////////////

	std::cout << "RANDOM TEST - 10000 ELEMENTS" << std::endl;
	Span sp(10000);
	
	std::vector<int> bigVector(10000);
	std::generate(bigVector.begin(), bigVector.end(), std::rand);
	
	sp.addRange(bigVector.begin(), bigVector.end());
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << std::endl;
	//////////////////////
	
	std::cout << "RANDOM TEST - 100000 ELEMENTS" << std::endl;
	Span sp2(100000);
	
	std::vector<int> bigVector2(100000);
	std::generate(bigVector2.begin(), bigVector2.end(), std::rand);
	
	sp2.addRange(bigVector2.begin(), bigVector2.end());
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	return 0;
}

