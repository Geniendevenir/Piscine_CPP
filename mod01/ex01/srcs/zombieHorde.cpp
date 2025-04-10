/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:01:10 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 22:02:21 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		//std::cout << &horde[i] << std::endl;
		horde[i].annonce();
	}
		
	return horde;
}