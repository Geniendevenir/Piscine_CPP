/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:34:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 21:25:40 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(); 
		Dog(const Dog &src);
		~Dog();

		Dog &operator=(const Dog &rhs);
		std::string getType(void) const;
		Brain* getBrain(void) const;
		
		void makeSound(void) const;
		
	private:
		Brain* _brain;	
};

std::ostream &operator<<(std::ostream &o, const Dog &i);

#endif