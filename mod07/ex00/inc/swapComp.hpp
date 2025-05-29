/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapComp.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:34:31 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 17:55:56 by adebert          ###   ########.fr       */
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
	return (v1 > v2 ? v1 : v2);
}

#endif