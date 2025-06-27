/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:55:22 by adebert           #+#    #+#             */
/*   Updated: 2025/06/04 16:24:32 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void printContainer(const T& t) {
	typename T::const_iterator it;
	for (it = t.begin(); it != t.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;	
	return ;
}

template <typename T>
int easyfind(const T& t1, const int &t2) {
	typename T::const_iterator it = std::find(t1.begin(), t1.end(), t2);		
	if (it == t1.end())
		throw std::runtime_error("Value not found in the container");
	return std::distance(t1.begin(), it);	
}

#endif