/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:49:54 by allan             #+#    #+#             */
/*   Updated: 2025/04/03 21:20:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <string>
#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator=(const Fixed &rhs);

	private:
		int _fpn;	
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif