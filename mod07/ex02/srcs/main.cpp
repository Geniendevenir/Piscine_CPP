/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:55:45 by adebert           #+#    #+#             */
/*   Updated: 2025/06/03 15:21:06 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
	//Int Array
	//Empty
	try {
		Array <int> arr_i;
		std::cout << "arr_i Array Address = " << arr_i.getArrAddress() << std::endl;
		std::cout << "arr_i size = " << arr_i.size() << std::endl;

		if (arr_i[0])
			std::cout << "Error: arr_i is not Empty";
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Success: arr_i[0] is Empty" << std::endl;
	}

	std::cout << std::endl;

	//Not Empty
	try {
		Array <int> arr2_i(5); //Initalized by Default to 0
		std::cout << "arr2_i size = " << arr2_i.size() << std::endl;
		std::cout << "arr2_i Content =\n" << arr2_i << std::endl;
		std::cout << std::endl;

		//Copy Constructor
		Array <int> arr3_i(arr2_i); //Initalized by Default to 0
		std::cout << "arr3_i size = " << arr3_i.size() << std::endl;
		std::cout << "arr3_i Content =\n" << arr3_i << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}	
	
	std::cout << std::endl;
	
	//Float Array - Test Copy Constructor and Assigning Operator
	try {
		Array <float> arr_f(3); //Initalized by Default to 0
		arr_f.setArr(0, 0.0);
		arr_f.setArr(1, 1.0);
		arr_f.setArr(2, 2.0);
		std::cout << "arr_f size = " << arr_f.size() << std::endl;
		std::cout << "arr_f Content =\n" << arr_f << std::endl;
		
		Array <float> arr2_f(5); //Initalized by Default to 0
		arr2_f.setArr(0, 40.0);
		arr2_f.setArr(1, 50.0);
		arr2_f.setArr(2, 60.0);
		arr2_f.setArr(3, 70.0);
		arr2_f.setArr(4, 80.0);
		std::cout << "Before Copy Operator" << std::endl;
		std::cout << "arr_f Array Address = " << arr_f.getArrAddress() << std::endl; //Never supposed to change
		std::cout << "arr2_f Array Address = " << arr2_f.getArrAddress() << std::endl; //Can change
		std::cout << "arr2_f size = " << arr2_f.size() << std::endl;
		std::cout << "arr2_f Content =\n" << arr2_f << std::endl;
		
		arr2_f = arr_f;
		
		std::cout << "After Copy Operator" << std::endl;
		std::cout << "arr_f Array Address = " << arr_f.getArrAddress() << std::endl; //Never supposed to have changed
		std::cout << "arr2_f Array Address = " << arr2_f.getArrAddress() << std::endl; //Possibly changed
		std::cout << "arr2_f size = " << arr2_f.size() << std::endl;
		std::cout << "arr2_f Content =\n" << arr2_f << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}	
	
	return 0;
}