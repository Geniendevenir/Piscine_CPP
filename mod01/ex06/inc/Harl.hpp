/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:59:23 by allan             #+#    #+#             */
/*   Updated: 2025/04/03 14:06:31 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
		void complain(std::string level);
		
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*mfp_level[4])();
		std::string options[4];
};

#endif