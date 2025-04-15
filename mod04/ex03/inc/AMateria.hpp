/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:57:16 by allan             #+#    #+#             */
/*   Updated: 2025/04/15 20:34:37 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &src);
		virtual ~AMateria();

		virtual std::string const & getType() const;

		virtual AMateria* clone() const = 0;	
		virtual void use(ICharacter& target);
		
		AMateria &operator=(const AMateria &rhs);
};

std::ostream &operator<<(std::ostream &o, const AMateria &i);

#endif