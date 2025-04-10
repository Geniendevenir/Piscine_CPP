/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:51:37 by allan             #+#    #+#             */
/*   Updated: 2025/03/31 19:33:04 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	//heap zombies
	Zombie* Didier;	
	Didier = newZombie("Didier");
	Didier->annonce();
	std::cout << std::endl;

	Zombie* Bruno;	
	Bruno = newZombie("Bruno");
	Bruno->annonce();
	std::cout << std::endl;
	
	Zombie* Sandrine;	
	Sandrine = newZombie("Sandrine");
	Sandrine->annonce();
	std::cout << std::endl;
	
	//stack zombies
	randomChump("Corinne");
	std::cout << std::endl;
	
	randomChump("Vincent");
	std::cout << std::endl;
	
	randomChump("Vivianne");
	std::cout << std::endl;

	delete Didier;
	std::cout << std::endl;

	delete Bruno;
	std::cout << std::endl;
	
	delete Sandrine;
	
	return 0;
}
