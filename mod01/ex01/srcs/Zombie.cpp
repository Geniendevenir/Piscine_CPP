/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:53:06 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 21:57:21 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Default Constructor called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Destructor: " << this->name << std::endl;
}

void Zombie::annonce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string z_name) {
	this->name = z_name;
}