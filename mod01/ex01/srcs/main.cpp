/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:51:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/16 14:58:33 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	Zombie *horde = zombieHorde(10, "Henry");

	for (int i = 0; i < 10; i++) {
		horde[i].annonce();
	}
	
	delete [] horde;
	
	return 0;
}
