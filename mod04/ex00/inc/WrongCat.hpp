/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:34:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:45:13 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat(); 
		WrongCat(const WrongCat &src);
		 ~WrongCat();

		WrongCat &operator=(const WrongCat &rhs);
		std::string getType(void) const;
		
		void makeSound(void) const;
};

std::ostream &operator<<(std::ostream &o, const WrongCat &i);

#endif