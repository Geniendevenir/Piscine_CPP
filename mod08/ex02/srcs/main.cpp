/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:05:42 by allan             #+#    #+#             */
/*   Updated: 2025/06/10 19:26:58 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "TEST USING MUTANTSTACK" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack); //Used to show that Mutant Stack inherit from std::stack<T>

	
	std::cout << "SAME TEST USING STD::LIST" << std::endl;
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	
	std::list<int>::iterator l_it = lstack.begin();
	std::list<int>::iterator l_ite = lstack.end();
	++l_it;
	--l_it;
	while (l_it != l_ite) {
		std::cout << *l_it << std::endl;
		++l_it;
	}
	return 0;
}