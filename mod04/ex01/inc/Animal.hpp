/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:20:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 21:25:54 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
		Animal();
		Animal(const Animal &src);
		virtual ~Animal();

		Animal &operator=(const Animal &rhs);
		std::string getType(void) const;
		virtual Brain* getBrain(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream &operator<<(std::ostream &o, const Animal &i);

#endif