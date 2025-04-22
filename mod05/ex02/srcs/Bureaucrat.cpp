/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:04:51 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 16:11:09 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat() : _name("None"), _grade(0) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {	
	try {
		if (grade <= 0)
			throw Bureaucrat::GradeTooHighException("Error: Grade is too High\n");
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException("Error: Grade is too Low\n");
		else
			_grade = grade;	
	}
	catch (std::exception &e) {
		std::cerr << "Caught Grade Execption: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()) {
	*this = src;
	return ;
}


Bureaucrat::~Bureaucrat() {
	return ;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}



//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void Bureaucrat::upGrade() {
	try {
		if ((_grade - 1) <= 0)
			throw Bureaucrat::GradeTooHighException("Error: UpGrade results in a Grade too High");
		else
			_grade--;
	}
	catch (std::exception &e) {
		std::cerr << "Caught UpGrade Execption: " << e.what() << std::endl;
	}
}

void Bureaucrat::downGrade() {
	try {
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException("Error: DownGrade results in a Grade too Low");
		else
			_grade++;
	}
	catch (std::exception &e) {
		std::cerr << "Caught DownGrade Execption: " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &to_sign) const {
	if (to_sign.getSignState() == TRUE) {
		std::cout << "Form: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		to_sign.beSigned(*this);
		std::cout << _name << " signed " << to_sign.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << _name << " couldn't sign " << to_sign.getName() << " because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << getName() << " couldn't execute " << form.getName() << std::endl;
	}
}