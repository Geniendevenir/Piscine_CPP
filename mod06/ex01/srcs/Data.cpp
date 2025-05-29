/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:49:25 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 12:57:37 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream& operator<<(std::ostream &o, const Data& rhs){
	o << "age: " << rhs.age << std::endl
		<< "name: " << rhs.name << std::endl;	
	return o;
}