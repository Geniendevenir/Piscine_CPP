/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:58:17 by adebert           #+#    #+#             */
/*   Updated: 2025/05/28 16:29:06 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

Serializer::Serializer() {
	return ;
}


Serializer::Serializer(const Serializer &src) {
	*this = src;
	return ;
}


Serializer::~Serializer() {
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

Serializer& Serializer::operator=(const Serializer &rhs) {
	if (this != &rhs)
		return *this;
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Serializer &i) {
	o << &i << std::endl;
	return o;
}


//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////


uintptr_t Serializer::serialize(Data* ptr) {
	if (!ptr)
		throw std::runtime_error("Data* ptr is empty");
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	if (!raw)
		throw std::runtime_error("uintptr_t* raw is empty");
	return reinterpret_cast<Data*>(raw);
}
