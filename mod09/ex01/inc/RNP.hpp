/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:39:47 by allan             #+#    #+#             */
/*   Updated: 2025/06/15 20:33:28 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <string>
#include <iostream>
#include <stack>

#define SUCCESS 0
#define ERROR 1


/* Warning Edge cases: div by 0*/

class RNP {
	private:
		std::stack<int> _rnp;	
		int _stackSize;
		std::string _input;
		bool isOperator(char c) const;

	public:
		RNP();
		RNP(const std::string& str);
		RNP(const RNP &src);
		~RNP();

		bool parseInput(void);


/* 		RNP &operator=(const RNP &rhs);
		std::string getSomething(void) const;
		void setSomething(std::string new_value); */

};

std::ostream &operator<<(std::ostream &o, const RNP &i);

#endif