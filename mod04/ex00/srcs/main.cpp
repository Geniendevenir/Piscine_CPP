/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:29:50 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:47:52 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n";
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! (Miaaaew)
	j->makeSound(); //will output the dog sound! (Baaark)
	meta->makeSound(); //will output animal sound! (*animals don't make sound) 

	std::cout << "\n";
	
	const WrongAnimal*wrongmeta = new WrongAnimal();
	const WrongAnimal*wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will output wronganimal sound (*wrong animal don't make sound)
	wrongmeta->makeSound(); //will also output wronganimal sound

	std::cout << "\n";
	delete meta;
	delete j;
	delete i;
	delete wrongmeta;
	delete wi;

	return 0;
}
