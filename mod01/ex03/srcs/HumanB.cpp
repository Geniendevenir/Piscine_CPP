/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:01:10 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 23:11:49by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name) {
	this->weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}	

void HumanB::setWeapon(Weapon &weapon_type) {
	this->weapon = &weapon_type;
}