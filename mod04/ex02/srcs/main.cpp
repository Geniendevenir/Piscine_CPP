/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:29:50 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 11:37:29 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Test Animal is instantiable	
	//Animal* test = new Animal();
	//Animal test;
	Animal *zoo[10]; 
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();	
	}

	std::cout << std::endl;


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i != j) {
				if (zoo[i] == zoo[j])
					std::cout << "Error: Animals number " << i << " and " << j << " are pointing to the same Instance address" << std::endl;
				if (zoo[i]->getBrain() && zoo[j]->getBrain() && zoo[i]->getBrain() == zoo[j]->getBrain())
					std::cout << "Error: Animals number " << i << " and " << j << " are sharing the same Brain" << std::endl;
			}
		}
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		delete zoo[i];
	}
	return 0;
}
