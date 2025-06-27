/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:06:49 by adebert           #+#    #+#             */
/*   Updated: 2025/06/11 16:15:02 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TEST MAIN CPP08 - EX02

/* int main()
{
	std::cout << "TEST USING MUTANTSTACK" << std::endl;
	MutantStack<float> mstack;
	mstack.push(42.1f);
	mstack.push(100000.02f);
	mstack.push(750.3f);
	mstack.push(63.4f);
	mstack.push(0.001f);

	mstack.pop();
	mstack.pop();
	
	mstack.push(3.36f);
	mstack.push(1.2f);
	
	MutantStack<float>::iterator it = mstack.begin();
	MutantStack<float>::iterator ite = mstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "SAME TEST USING LIST" << std::endl;
	std::list<float> l_stack;
	l_stack.push_back(42.1f);
	l_stack.push_back(100000.02f);
	l_stack.push_back(750.3f);
	l_stack.push_back(63.4f);
	l_stack.push_back(0.001f);

	l_stack.pop_back();
	l_stack.pop_back();
	
	l_stack.push_back(3.36f);
	l_stack.push_back(1.2f);
	
	std::list<float>::iterator l_it = l_stack.begin();
	std::list<float>::iterator l_ite = l_stack.end();

	while (l_it != l_ite) {
		std::cout << *l_it << std::endl;
		++l_it;
	}
	return 0;
} */