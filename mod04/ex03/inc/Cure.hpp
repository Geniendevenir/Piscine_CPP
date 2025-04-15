/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:03:18 by allan             #+#    #+#             */
/*   Updated: 2025/04/14 01:05:57 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria{
	protected:
		std::string _type;

	public:
		Cure();
		Cure(std::string const & type);
		Cure(const Cure &src);
		~Cure();

		std::string const & getType() const;
		
		AMateria* clone() const;	
		void use(ICharacter& target);
		
		Cure &operator=(const Cure &rhs);
};

std::ostream &operator<<(std::ostream &o, const Cure &i);

#endif