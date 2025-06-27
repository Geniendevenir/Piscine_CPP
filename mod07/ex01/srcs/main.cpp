/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:49:28 by allan             #+#    #+#             */
/*   Updated: 2025/06/11 10:41:55 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
	//Test const array
	std::cout << "TEST CONST ARRAY" << std::endl;
	const float arr_f[] = {1.1f, 2.2f, 3.3};
	iter(arr_f, 3, display<const float>);	//Does not modify arr value: Valid
	//iter(arr_f, 3, addOne); //Tries to modify a const value: compilation error
	std::cout << std::endl;
	
	std::cout << "TEST NON-CONST ARRAY" << std::endl;
	//Test non-const Array
	int arr[] = {1, 2, 3};
	std::cout << "Before addOne" << std::endl;
	iter(arr, 3, display<int>);
	
	iter(arr, 3, addOne<int>);
	std::cout << "After addOne" << std::endl;
	iter(arr, 3, display<int>);
	return 0;
}