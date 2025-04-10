/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:59 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 23:50:58 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	public:
		Weapon();
		Weapon(std::string weapon_type);
		~Weapon();
		std::string const &getType();
		void setType(std::string type_info);
	
	private:
		std::string type;	
};

#endif