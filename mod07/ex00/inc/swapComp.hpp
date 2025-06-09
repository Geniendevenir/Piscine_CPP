/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapComp.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:32:23 by allan             #+#    #+#             */
/*   Updated: 2025/06/09 13:32:35 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPCOMP_HPP
#define SWAPCOMP_HPP

#include <string>
#include <iostream>

template< typename T >
void swap(T& v1, T& v2) {
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

template< typename T >
const T& min(const T& v1, const T& v2) {
	return (v1 < v2 ? v1 : v2);
}

template< typename T >
const T& max(const T& v1, const T& v2) {
	return (v1 > v2 ? v1 : v2);Add commentMore actions
}

#endif