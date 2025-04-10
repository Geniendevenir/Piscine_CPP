/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:59 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 23:58:21 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP 
# define HUMANB_HPP

#include <Weapon.hpp>

class HumanB {
	
	public:
		HumanB(std::string h_name);
		~HumanB();
		void attack();	
		void setWeapon(Weapon &weapon_type);
		
	private:
		std::string name;
		Weapon *weapon;
};
#endif