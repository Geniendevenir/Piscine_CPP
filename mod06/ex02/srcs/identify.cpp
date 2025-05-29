/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:18:14 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 14:20:54 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base *generate(void) {
	std::srand(std::time(0));

	int random = std::rand() % 3;
	Base *base;
	if (random == 0) {
		std::cout << "A Class Constructed" << std::endl;
		base = dynamic_cast<Base*>(new A());
	} else if (random == 1) {
		std::cout << "B Class Constructed" << std::endl;
		base = dynamic_cast<Base*>(new B());
	} else if (random == 2) {
		std::cout << "C Class Constructed" << std::endl;
		base = dynamic_cast<Base*>(new C());
	} else
		throw std::invalid_argument("Error: srand result < 1 or > 3");
	return base;	
}

void identify(Base* p) {
	std::cout << "Identify using Pointer" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "It's an A Child" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's a B Child" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's a C Child" << std::endl;
	else
		std::cout << "Base pointer is either NULL or does not fit any derived class" << std::endl;
}

void identify(Base& p) {
	std::cout << "Identify using Reference" << std::endl;
	try {
		dynamic_cast<A&>(p);
		std::cout << "It's an A Child" << std::endl;
		return;
	} catch (const std::exception& e) {
	}
	
	try {
		dynamic_cast<B&>(p);
		std::cout << "It's a B Child" << std::endl;
		return;
	} catch (const std::exception& e) {
	}
	
	try {
		dynamic_cast<C&>(p);
		std::cout << "It's a C Child" << std::endl;
		return;
	} catch (const std::exception& e) {
	}

	std::cout << "Error: Base can't be cast into any of its derived class";
}
