/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:46:16 by allan             #+#    #+#             */
/*   Updated: 2025/04/21 16:05:51 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {	
	
	//try {
		//TESTS 1: Form Grade Limits -> Object is not constructed
		std::cout << "TEST 1" << std::endl;
	/* 	Form Buyout("Buyout", 151, 50);
		std::cout << Buyout << std::endl; */
		
	/* 	Form Buyout("Buyout", 0, 50);
		std::cout << Buyout << std::endl; */

	/* 	Form Buyout("Buyout", 50, INT_MAX);
		std::cout << Buyout << std::endl; */
		
	/* 	Form Buyout("Buyout", 50, INT_MIN);
		std::cout << Buyout << std::endl; */
		
/* 	} catch (std::exception &e) {
		std::cerr << "Error went back up to main" << std::endl;
	} */
	

	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;
	
	//TEST 2: Failling singing a form
	std::cout << "TEST 2" << std::endl;
	Bureaucrat Jose("Jose", 150);
	std::cout << Jose << std::endl;
	
	std::cout << "\nForm Before attempting to sign:" << std::endl;
	Form Sellstuff("Sellstuff", 1, 50);
	std::cout << Sellstuff << std::endl;

	//Sellstuff.beSigned(Jose); //no message cause supposed to be used with Bureaucrat::signForm();
	
	Jose.signForm(Sellstuff);	
	std::cout << "\nForm After failling to sign:" << std::endl;
	std::cout << Sellstuff << std::endl; //Form has not been signed;


	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;
	
	//TEST 3: Successfully signing a form
	std::cout << "TEST 3" << std::endl;
	Bureaucrat Estelle("Estelle", 1);
	std::cout << Estelle << std::endl;
	
	std::cout << "\nForm Before attempting to sign:" << std::endl;
	std::cout << Sellstuff << std::endl;

	Estelle.signForm(Sellstuff);	
	std::cout << "\nForm After successful signing:" << std::endl;
	std::cout << Sellstuff << std::endl; //Form has been signed;
	
	
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;

	//TEST 4: Trying to Sign a form already Signed
	Estelle.signForm(Sellstuff);	

	return (0);
}
