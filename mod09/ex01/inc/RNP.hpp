/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:39:47 by allan             #+#    #+#             */
/*   Updated: 2025/06/22 17:44:09 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <string>
#include <iostream>
#include <stack>
#include <limits>
#include <iomanip>

#define SUCCESS 0
#define ERROR 1

class RNP {
	private:
		std::stack<double> _rnp;	
		int _stackSize;
		std::string _input;
		
		bool isOperator(char c) const;
		bool doOperation(char sign);
		bool doSubstraction();
		bool doMultiplication();
		bool doAddition();
		bool doDivision();
		bool checkIntOverflow() const;

	public:
		RNP();
		RNP(const std::string& str);
		RNP(const RNP &src);
		~RNP();

		bool parseInput(void);
		bool createStack(void);
		double getResult(void) const;

 		RNP &operator=(const RNP &rhs);
};

#endif