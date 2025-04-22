/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:46:16 by allan             #+#    #+#             */
/*   Updated: 2025/04/21 12:59:45 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {	
	
	//1 is the HIGHEST grade && 150 is the LOWEST	
	//Test grade initialization limits
	Bureaucrat Jose("Jose", INT_MAX);
	Bureaucrat Fabrice("Fabrice", 151);
	Bureaucrat Estelle("Estelle", 0);
	Bureaucrat Raph("Raph", INT_MIN);
	
	
	//Test DownGrade Limit
	Bureaucrat Marie("Marie", 150);
	std::cout << Marie << std::endl;
	Marie.downGrade();
	std::cout << Marie << std::endl;
	
	std::cout << std::endl;	

	//Test UpGrade Limit
	Bureaucrat Suzie("Suzie", 1);
	std::cout << Suzie << std::endl;
	Suzie.upGrade();
	std::cout << Suzie << std::endl;

	std::cout << std::endl;	
	
	//Test Normal Setup
	Bureaucrat Daniel("Daniel", 5);
	std::cout << Daniel << std::endl;
	Daniel.downGrade();
	std::cout << Daniel << std::endl;
	Daniel.upGrade();
	std::cout << Daniel << std::endl;
	
	return (0);
}
