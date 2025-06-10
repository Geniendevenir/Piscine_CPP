/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:32:36 by allan             #+#    #+#             */
/*   Updated: 2025/06/10 19:13:08 by allan            ###   ########.fr       */
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


//begin, end, ++, --, *


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

/* First Try
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack &src) : _data(src._data) {}
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &rhs) {
			if (this != &rhs) {
				_data = rhs._data
			}
			return *this;
		}

		void push(const T& value) {
			_data.push_back(value);
		}
		
		void pop() {
			if (_data.empty())
				throw std::underflow_error("Stack is empty");
			_data.pop_back();	
		}
		
		T& top() {
			if (_data.empty())
				throw std::underflow_error("Stack is empty");
			return _data.back();
		}
		
		const T& top() const {
			if (_data.empty())
				throw std::underflow_error("Stack is empty");
			return _data.back();	
		}
		
		void empty() const {
			return _data.empty();
		}
		
		std::size_t size() const {
			return _data.size();
		}
		
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		
		iterator begin() {
			return _data.begin();
		}
		
		const_iterator begin() const {
			return _data.begin();
		}
		
		iterator end() {
			return _data.end();
		}
		
		const_iterator end() const {
			return _data.end();
		}

	private:
		std::deque<T> _data;
		
}; */

//std::ostream &operator<<(std::ostream &o, const MutantStack &i);

#endif