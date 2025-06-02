/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:01:57 by adebert           #+#    #+#             */
/*   Updated: 2025/06/02 19:58:25 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template < typename T >
class Array {
	public:
		Array() : _arr(new T[0]), _size(0) { }// Creates an Empty Array
		Array(unsigned int n) : _arr(new T[n]), _size(n) { } // Creates an Array of N elements 
		Array(const Array &src) : _arr(new T[src.size]), _size(src.size()) {
			for (std::size_t i = 0; i < _size; i++) {
				_arr[i] = src._arr[i];
			}
		};
		~Array() { delete[] _arr; }
		
		std::size_t size() const {
			return _size;
		};
		
		Array &operator=(const Array &rhs) { 
			if (this != &rhs) {
				delete[] _arr;
				_arr = new T[rhs.size()];
				_size = rhs.size();
				for (std::size_t i = 0; i < _size; i++) {
					_arr[i] = rhs._arr[i];
				}
			}
		}

		const T& operator[](std::size_t index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _arr[index];
		}	

	private:
		T* _arr;
		std::size_t _size;
};

template < typename T >
std::ostream &operator<<(std::ostream &o, const Array< T > &i);

#endif