/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:18:53 by adebert           #+#    #+#             */
/*   Updated: 2025/07/02 12:34:04 by adebert          ###   ########.fr       */
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
	
	//BEFORE SORTING
	std::cout << "Before:\t";
	printContainer(vec.getInputs());
	
	//TEST WITH STD::VECTOR()
	std::clock_t vecStart = std::clock();	
	std::vector<int> vecSorted = vec.fordJohsonSort(vec.getInputs());	
	std::clock_t vecEnd = std::clock();
	double vecDuration = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC;

	//AFTER SORTING
	std::cout << "After:\t";
	printContainer(vecSorted);

	//TEST WITH STD::DEQUE
	std::clock_t deqStart = std::clock();	
	std::deque<int> deqSorted = deq.fordJohsonSort(deq.getInputs());	
	std::clock_t deqEnd = std::clock();
	double deqDuration = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC;
	
	//TIME	
	std::cout << "Time to process a range of " << argc - 1 << " with std::vector : " << std::fixed << vecDuration << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " with std::deque: " << std::fixed << deqDuration << " us" << std::endl;

	
	return SUCCESS;
}