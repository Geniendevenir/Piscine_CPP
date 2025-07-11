/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:32:36 by allan             #+#    #+#             */
/*   Updated: 2025/06/11 15:05:27 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <list>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {
	public:	
		//Constructor - Destructor - Operator
		MutantStack() {}
		MutantStack(const MutantStack &src) : std::stack<T>(src) {} //Use std::stack copy constructor
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs); //Use std::stack operator=
			return *this;
		}

		
		//Iterator Implementation	
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
    	iterator end()   { return this->c.end(); }

    	const_iterator begin() const { return this->c.begin(); }
    	const_iterator end()   const { return this->c.end(); }

    	reverse_iterator rbegin() { return this->c.rbegin(); }
    	reverse_iterator rend()   { return this->c.rend(); }

    	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    	const_reverse_iterator rend()   const { return this->c.rend(); }
		
};

#endif