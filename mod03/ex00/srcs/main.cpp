/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:51 by allan             #+#    #+#             */
/*   Updated: 2025/04/18 18:28:04 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Jose("Jose");

	Jose.attack("Maurice"); 					//9
	Jose.takeDamage(5);
	Jose.beRepaired(10);						//8
	
	std::cout << std::endl;	
	Jose.takeDamage(INT_MAX);
	Jose.beRepaired(INT_MAX);					//7

	std::cout << std::endl;	
	Jose.takeDamage(INT_MIN);
	Jose.beRepaired(INT_MIN);					//6
	
	std::cout << std::endl;	
	Jose.takeDamage(0);
	Jose.beRepaired(0);							//5
	Jose.beRepaired(10);						//4
	
	Jose.attack("Momo_fils_de_Maurice");		//3
	Jose.attack("Momo_fils_de_Maurice");		//2
	Jose.attack("Momo_fils_de_Maurice");		//1
	Jose.attack("Momo_fils_de_Maurice");		//0
	
	std::cout << std::endl;	
	
	//Supposed to be out of Energy;
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	
	return 0;
}