/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:54 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:05:46 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&src);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap&rhs);
		std::string getName(void) const;
		void beRepaired(unsigned int amount);
		
		void attack(const std::string& target);
		void guardGate();

};

std::ostream &operator<<(std::ostream &o, const ScavTrap &i);

#endif