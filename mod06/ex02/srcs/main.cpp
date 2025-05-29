/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:53:46 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 14:22:07 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"


int main(void) {
	//TEST 1: Try Generating Random Derived Class
	try {
		for (int i = 0; i < 10; i++) {
			Base *test = generate();
			delete test;	
			usleep(500000); //Wait as srand seed is based on time
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl; 
	}

	//TEST 2: Identify the Original (Derived) Type of a Base Class
	/*Base *ptr = generate();
	Base& ref = *ptr;
	
	identify(ptr);
	identify(ref);
	
	delete ptr;	 */
	return (0);
}
