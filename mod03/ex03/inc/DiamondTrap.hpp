/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:54 by allan             #+#    #+#             */
/*   Updated: 2025/04/09 19:07:36 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include <climits>

class DiamondTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;

	protected:
	std::string _name;
	int _hit_points;
	int _energy_point;
	int _attack_damage;
};

std::ostream &operator<<(std::ostream &o, const DiamondTrap &i);

#endif