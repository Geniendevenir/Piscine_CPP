/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:43:34 by adebert           #+#    #+#             */
/*   Updated: 2025/05/29 12:53:43 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
	std::string name;
	int age;
};
std::ostream& operator<<(std::ostream &o, const Data& rhs);

#endif