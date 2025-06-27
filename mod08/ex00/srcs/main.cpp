/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:55:30 by adebert           #+#    #+#             */
/*   Updated: 2025/06/04 16:26:40 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	int result = 0;
	//List
	std::list<int> l;
	l.push_back(-50);
	l.push_back(42);
	l.push_back(12);
	l.push_back(-1);
	l.push_back(0);
	
	std::cout << "TEST WITH LIST" << std::endl;

	std::cout << "LIST CONTENT" << std::endl;
	printContainer(l);
	
	std::cout << "TEST 1 (0)" << std::endl;
	try {
		result = easyfind(l, 0); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 2 (-1000)" << std::endl;
	try {
		result = easyfind(l, -1000); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 3 (42)" << std::endl;
	try {
		result = easyfind(l, 42); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//Vector
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);
	
	std::cout << "TEST WITH VECTOR" << std::endl;

	std::cout << "VECTOR CONTENT" << std::endl;
	printContainer(v);

	std::cout << "TEST 4 (0)" << std::endl;
	try {
		result = easyfind(v, 0); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 5 (3)" << std::endl;
	try {
		result = easyfind(v, 3); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 6 (-2)" << std::endl;
	try {
		result = easyfind(v, -2); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	//Deque
	std::deque<int> d;
	d.push_back(30);
	d.push_front(20);
	d.push_front(10);
	d.push_back(40);
	d.push_back(50);
	
	std::cout << "TEST WITH DEQUE" << std::endl;

	std::cout << "DEQUE CONTENT" << std::endl;
	printContainer(d);

	std::cout << "TEST 7 (10)" << std::endl;
	try {
		result = easyfind(d, 10); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 8 (30)" << std::endl;
	try {
		result = easyfind(d, 30); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "TEST 9 (50)" << std::endl;
	try {
		result = easyfind(d, 50); 
		std::cout << "FOUND AT INDEX: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
}