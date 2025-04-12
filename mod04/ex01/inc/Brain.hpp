/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:20:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/11 16:50:25 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain &operator=(const Brain &rhs);
		std::string getIdea(int i) const;

	private:
		std::string *ideas;
};

std::ostream &operator<<(std::ostream &o, const Brain &i);

#endif