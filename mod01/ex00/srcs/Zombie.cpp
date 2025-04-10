/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:53:06 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 21:23:31 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string z_name) : name(z_name) {
}

Zombie::~Zombie() {
	std::cout << "Destructor: " << this->name << std::endl;
}

void Zombie::annonce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}