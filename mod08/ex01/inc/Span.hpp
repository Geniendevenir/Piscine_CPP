/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:41:54 by allan             #+#    #+#             */
/*   Updated: 2025/06/10 14:30:01 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &rhs);
		size_t getSize(void) const;
		int getElement(size_t index) const;

		void addNumber(int nbr);
		long shortestSpan();
		long longestSpan();

		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last) {
			size_t rangeSize = std::distance(first, last);
			if (_v.size() + rangeSize > _N)
				throw std::overflow_error("Adding range exceeds Span Capacity");
			_v.insert(_v.end(), first, last);
				
		}

	private:
		unsigned int _N;
		std::vector<int> _v;
};

std::ostream &operator<<(std::ostream &o, const Span &i);

#endif