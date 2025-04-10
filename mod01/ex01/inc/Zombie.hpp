/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:59 by allan             #+#    #+#             */
/*   Updated: 2025/04/01 21:56:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	
	public:
		Zombie();
		~Zombie();
		void annonce(void);
		void setName(std::string);

	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif