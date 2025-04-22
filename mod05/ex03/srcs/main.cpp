/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:46:16 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 20:39:39by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {	
	
	//Valid Forms:
	//"shrubbery request";
	//"robotomy request";
	//"pardon request";

	Intern someRandomIntern;

	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	std::cout << std::endl;

	AForm* srf;
	srf = someRandomIntern.makeForm("shrubbery request", "Mickeal");
	std::cout << *srf << std::endl;
	std::cout << std::endl;

	AForm* prf;
	prf = someRandomIntern.makeForm("pardon request", "Jackson");
	std::cout << *prf << std::endl;
	std::cout << std::endl;

	AForm* wrong;
	wrong = someRandomIntern.makeForm("no form", "Jackson");
	if (!wrong)
	{
		delete rrf;
		delete srf;
		delete prf;
		return 1;
	}
	std::cout << *wrong << std::endl;
	std::cout << std::endl;

	
	delete rrf;
	delete srf;
	delete prf;
	delete wrong;
	return (0);
}
