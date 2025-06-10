/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:50:16 by allan             #+#    #+#             */
/*   Updated: 2025/06/10 14:35:10 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

Span::Span() : _N(0) {
	return ;
}

Span::Span(unsigned int N) : _N(N) {
	return ;
}

Span::Span(const Span &src) {
	*this = src;
	return ;
}


Span::~Span() {
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

Span& Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_v = rhs._v;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Span &i) {
	for (size_t j = 0; j < i.getSize(); j++) {
		o << i.getElement(j) << std::endl;					
	}
	return o;
}


//////////////////////////////////////////////////////////
//					 GETTER/SETTER						//
//////////////////////////////////////////////////////////

size_t Span::getSize(void) const {
	return _v.size();
}

int Span::getElement(size_t index) const {
	return _v[index];
}


//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////


void Span::addNumber(int nbr) {
	if (_N <= _v.size())
		throw std::overflow_error("Array is already full");	
	_v.push_back(nbr);
}

long Span::shortestSpan() {
	if (_N == 0 || _v.size() == 0 || _v.size() == 1)
		throw std::logic_error("Shortest Span: Array is empty");
		
	std::sort(_v.begin(), _v.end());
		
	long shortest = std::numeric_limits<int>::max();
	
	for (size_t i = 1; i < _v.size(); i++) {
		long diff = static_cast<long>(_v[i]) - static_cast<long>(_v[i - 1]);						
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

long Span::longestSpan() {
	if (_N == 0 || _v.size() == 0 || _v.size() == 1)
		throw std::logic_error("Longest Span: Array is empty");
		
	std::sort(_v.begin(), _v.end());
		
	long longest = static_cast<long>(_v.back()) - static_cast<long>(_v.front());

	return longest;
}