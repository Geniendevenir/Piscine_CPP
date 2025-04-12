/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:44:51 by allan             #+#    #+#             */
/*   Updated: 2025/04/10 22:24:26 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void) {
	ClapTrap Jose("Jose");

	Jose.attack("Maurice");
	Jose.takeDamage(5);
	Jose.beRepaired(10);
	
	std::cout << std::endl;	
	Jose.takeDamage(INT_MAX);
	Jose.beRepaired(INT_MAX);

	std::cout << std::endl;	
	Jose.takeDamage(INT_MIN);
	Jose.beRepaired(INT_MIN);
	
	std::cout << std::endl;	
	Jose.takeDamage(0);
	Jose.beRepaired(0);
	Jose.beRepaired(10);
	
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	
	//Supposed to be out of Energy;
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	Jose.attack("Momo_fils_de_Maurice");
	
	return 0;
}