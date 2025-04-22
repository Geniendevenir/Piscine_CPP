/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:51:06 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 20:41:19 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//////////////////////////////////////////////////////////
//				 CONSTRUCTOR/DESTRUCTOR					//
//////////////////////////////////////////////////////////

Intern::Intern() {
	_forms_names[0] = "shrubbery request";
	_forms_names[1] = "robotomy request";
	_forms_names[2] = "pardon request";
	
	return ;
}


Intern::Intern(const Intern &src) {
	*this = src;
	return ;
}


Intern::~Intern() {
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

Intern& Intern::operator=(const Intern &rhs) {
	if (this != &rhs) {
		_forms_names[0] = rhs._forms_names[0];
		_forms_names[1] = rhs._forms_names[1];
		_forms_names[2] = rhs._forms_names[2];
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Intern &i) {
	o << "Forms[0] = " << i.getFormName(0) << "\n"
	 << "Forms[1] = " << i.getFormName(1) << "\n"
	 << "Forms[2] = " << i.getFormName(2) << "\n"
	 << std::endl;
	return o;
}


//////////////////////////////////////////////////////////
//					 GETTER/SETTER						//
//////////////////////////////////////////////////////////

std::string Intern::getFormName(int index) const {
	if (index < 0 || index > 2)
		return NULL;
	return _forms_names[index];
}

//////////////////////////////////////////////////////////
//						 ACTION							//
//////////////////////////////////////////////////////////


AForm* Intern::makeForm(std::string name, std::string target) {
	int i = -1;
	for (int j = 0; j < 3; j++) {
		if (_forms_names[j] == name) {
			i = j;	
			break ;
		}
	}
	
	switch (i) {
		case 0:
			std::cout << "Inten creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Inten creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Inten creates " << name << std::endl;
			return new PresidentialPardonForm(target);	
	}
	std::cerr << "Error: Intern couldn't create the form: " << name << ". No Form of that name" << std::endl;	
	return NULL;
}
