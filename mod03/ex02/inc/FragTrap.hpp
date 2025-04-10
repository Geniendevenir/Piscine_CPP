/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:54 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:31:39 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap&src);
		~FragTrap();

		FragTrap &operator=(const FragTrap&rhs);
		std::string getName(void) const;
		void beRepaired(unsigned int amount);
		
		void attack(const std::string& target);
		void highFivesGuys();

};

std::ostream &operator<<(std::ostream &o, const FragTrap &i);

#endif