/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:34:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:13:24 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat(); 
		Cat(const Cat &src);
		~Cat();

		Cat &operator=(const Cat &rhs);
		std::string getType(void) const;
		
		void makeSound(void) const;
};

std::ostream &operator<<(std::ostream &o, const Cat &i);

#endif