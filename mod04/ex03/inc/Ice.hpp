/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:03:18 by allan             #+#    #+#             */
/*   Updated: 2025/04/14 01:40:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria{
	protected:
		std::string _type;

	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice &src);
		~Ice();

		std::string const & getType() const;
		
		AMateria* clone() const;	
		void use(ICharacter& target);
		
		Ice &operator=(const Ice &rhs);
};

std::ostream &operator<<(std::ostream &o, const Ice &i);

#endif