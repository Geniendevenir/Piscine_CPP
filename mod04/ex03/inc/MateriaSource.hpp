/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:44:05 by allan             #+#    #+#             */
/*   Updated: 2025/04/15 20:18:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_inventory[4];
		void _empty_inventory();
		void _clone_inventory(const MateriaSource &rhs);
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &rhs);
		~MateriaSource();
		
		MateriaSource& operator=(const MateriaSource &rhs);
		
		void learnMateria(AMateria* to_learn);
		AMateria* createMateria(std::string const & type);
};

#endif