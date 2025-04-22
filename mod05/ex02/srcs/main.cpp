/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:46:16 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 18:07:10 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {	
	
/* 	std::cout << "TEST 0" << std::endl;
	//Check that AForm is an Bastract Form & test cloning a Form
	// AForm sell("sell", 100, 100);
	
	AForm *one = new ShrubberyCreationForm("Billy");
	std::cout << *one << std::endl;
	
	AForm *two = one->clone();
	std::cout << *two << std::endl; 
	
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;	*/

		
		
		
	Bureaucrat John("John", 150);	
	Bureaucrat Titi("Titi", 1);	
	ShrubberyCreationForm shrub("home");

	
	//Try to execute a Form that is not sign (with/without rights)
 	std::cout << "TEST 1" << std::endl;
	try {
		shrub.execute(John); //Shouldn't work
	} catch (const std::exception &e) {
	}
	try {
		shrub.execute(Titi); //Shouldn't work
	} catch (const std::exception &e) {
	}
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;	
	

	
	//Try to sign a Form (with/without rights)
 	std::cout << "TEST 2" << std::endl;
	John.signForm(shrub); //Shouldn't work
	Titi.signForm(shrub); //Should work
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;	

	

	
	//Try to sign a Form that's already signed (with/wihtout rights)
	John.signForm(shrub); //Shouldn't work
	Titi.signForm(shrub); //Shouldn't work
 	std::cout << "TEST 3" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;	
	

	
	//Trying to execute a Form: By calling ShrubberyCreationform::execute() without calling Bureaucrat::exec() 
 	std::cout << "TEST 4" << std::endl;
	try {
		shrub.execute(John); //Shouldn't work
	} catch (const std::exception &e) {}
	try {
		shrub.execute(Titi); //Should work 
		std::cout << "Success" << std::endl;
	} catch (const std::exception &e) {}
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;	


	
	
 	std::cout << "TEST 5" << std::endl;
	//Trying to execute a Form: By calling Bureaucrat::exec();
	John.executeForm(shrub); //shoudlnt work
	std::cout << std::endl;
	Titi.executeForm(shrub); //should work
	
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;


	
 	std::cout << "TEST 6" << std::endl;
	//Test Robotomy
	Bureaucrat Marie("Marie", 73);	
	Bureaucrat Justine("Justine", 45);	
	RobotomyRequestForm robot("Awen");
	
	Marie.signForm(robot); //Shouldnt Work
	std::cout << std::endl;
	Justine.signForm(robot); //Should Work
	std::cout << std::endl;
	Justine.executeForm(robot); //Should Work
	

	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;


 	std::cout << "TEST 7" << std::endl;
	//Test Presidential 
	Bureaucrat Suzie("Suzie", 6);	
	Bureaucrat Mathieu("Mathieu", 5);	
	PresidentialPardonForm Ronald("Ronald");
	
	Suzie.signForm(Ronald); //Should Work
	std::cout << std::endl;
	Suzie.executeForm(Ronald); //Shouldnt Work
	std::cout << std::endl;
	Mathieu.executeForm(Ronald); //Should Work
	return (0);
}
