/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:18:53 by adebert           #+#    #+#             */
/*   Updated: 2025/07/01 19:55:32 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char**argv) {

	if (argc < 2) {
		std::cerr << "Error: At least one argument needed" << std::endl;
		return ERROR;
	} 
	
	PmergeMe<std::vector<int> > vec;
	PmergeMe<std::deque<int> > deq;
	if (vec.checkInputs(argc - 1, argv + 1)) {
		std::cerr << "Error Vector" << std::endl;
		return ERROR;
	}
	if (deq.checkInputs(argc - 1, argv + 1)) {
		std::cerr << "Error Deque" << std::endl;
		return ERROR;
	}
	
	std::cout << "Before: " << vec << std::endl;
	std::vector<int> vecSorted = vec.fordJohsonSort(vec.getInputs());	
	std::cout << "After: ";
	vec.printContainer(vecSorted);
	
	std::cerr << "Success" << std::endl;
	return SUCCESS;
}