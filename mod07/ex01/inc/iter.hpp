/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:41:06 by allan             #+#    #+#             */
/*   Updated: 2025/06/09 14:54:31 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void iter(T* arr, size_t length, void (*func)(T&)) {
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < length; i++) {
		if (arr[i])
			func(arr[i]);	
	}
}

template <typename T>
void iter(const T* arr, size_t length, void (*func)(const T&)) {
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < length; i++) {
		if (arr[i])
			func(arr[i]);	
	}
}

//Instantiated function template to Test
template <typename T>
void addOne(T& nbr) {
	nbr++;
}

template <typename T>
void display(const T& i) {
	std::cout << i << std::endl;	
}

#endif