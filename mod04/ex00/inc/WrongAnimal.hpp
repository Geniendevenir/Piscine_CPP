/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:20:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:45:18 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &rhs);
		std::string getType(void) const;

		void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream &operator<<(std::ostream &o, const WrongAnimal &i);

#endif