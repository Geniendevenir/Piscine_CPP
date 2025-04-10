/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:53:06 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 23:51:03 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string weapon_type) : type(weapon_type) {
}

Weapon::~Weapon() {
}

std::string const &Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type_info) {
	this->type = type_info;	
}