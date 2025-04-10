/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:59 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 23:57:36 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <Weapon.hpp>

class HumanA {
		
	public:
		HumanA(std::string h_name, Weapon &weapon_type);
		~HumanA();
		void attack();	
		
	private:
		Weapon &weapon;
		std::string name;
};

#endif