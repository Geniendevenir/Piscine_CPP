/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:01:10 by allan             #+#    #+#             */
/*   Updated: 2025/04/16 14:58:40 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
		
	return horde;
}