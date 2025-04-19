/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:08:44 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 15:51:13 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[4];	
		void _empty_inventory();
		void _clone_inventory(const Character &rhs); 
		
		struct Floor {
			AMateria* _old_materia;
			Floor* _next;
			Floor(AMateria* old) : _old_materia(old), _next(NULL) {};
		};
		
		Floor* _floor;	
		void _add_to_floor(AMateria *materia);
		void _delete_floor();
		
	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character(); 
		
		Character& operator=(const Character &rhs);
		std::string const & getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void showItems() const;
		void showFloor() const;
};


#endif