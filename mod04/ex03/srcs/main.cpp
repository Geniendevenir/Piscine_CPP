/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:51:48 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 15:13:46y adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	//Test Creating Abstract Class / Interface: Should'nt be possible
	//AMateria a();	
	//ICharacter b();
	//IMateriaSource c();
	
	//Test simple materia and character
	std::cout << "THE ADVENTURES OF JOSE" << std::endl;
	AMateria* icetea = new Ice();
	ICharacter* Jose = new Character("Jose");
	std::cout << "Jose faces a monster of type: " << *icetea << std::endl;
	icetea->use(*Jose);
	std::cout << "Jose has died on the battlefield" << std::endl;
	delete Jose;
	delete icetea;
	std::cout << std::endl;
	

	//Test cloning a materia, type and deep copy
	std::cout << "THE WORKSHOP OF THE WiZARD" << std::endl;
	AMateria* ancient_cure = new Cure();
	AMateria* new_cure = ancient_cure->clone(); 
	std::cout << "Ancient cure is of type: " << *ancient_cure << std::endl;
	std::cout << "New cure is of type: " << *new_cure << std::endl;
	std::cout << "Acient cure address: " << ancient_cure << std::endl;
	std::cout << "New cure address: " << new_cure << std::endl;
	std::cout << "You've learned the power of infite youth" << std::endl;
	delete ancient_cure;
	delete new_cure;
	std::cout << std::endl;

	//Test Character inventory, empty at construction, then full then unequip without deleting
	std::cout << "THE QUEST OF JOHN" << std::endl;
	ICharacter* John = new Character("John");
	static_cast<Character*>(John)->showItems();
	IMateriaSource*shop = new MateriaSource();
	shop->learnMateria(new Ice());
	shop->learnMateria(new Cure());
	AMateria*temp;
	std::cout << "John finds a galery shop" << std::endl;
	for (int i = 0; i < 5; i++) {
		temp = shop->createMateria("ice");
		John->equip(temp);
	}
	std::cout << "John is feeling too heavy now" << std::endl;
	for (int i = 0; i < 5; i++) {
		John->unequip(i);
	}
	std::cout << "Aaaah much better" << std::endl;
	std::cout << "Here is what John left behind" << std::endl;
	static_cast<Character*>(John)->showFloor();
	delete shop;
	delete John;

	std::cout << std::endl;

	//Main Test
	std::cout << "THE 42 MAIN TALE" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}