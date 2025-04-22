/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 16:48:42by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm() : _name("RobotomyRequestForm"), _target("None"), _is_signed(FALSE), _sign_grade(72), _exec_grade(45) {
	return ;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : _name("RobotomyRequestForm"), _target(target), _is_signed(FALSE), _sign_grade(72), _exec_grade(45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm(src),
	_name(src.getName()),
	_target(src.getTarget()),
	_sign_grade(src.getSignGrade()),
	_exec_grade(src.getExecGrade()) {
		return ;
}


RobotomyRequestForm::~RobotomyRequestForm() {
	return ;
}

//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	_is_signed = rhs.getSignState();
	return *this;
}

AForm* RobotomyRequestForm::clone() const {
	return new RobotomyRequestForm(*this);
}

void RobotomyRequestForm::print(std::ostream& o) const {
	o << "Form Name: " << getName() << "\n"
	<< "Target: " << getTarget() << "\n"
	<< "Signed: " << getSignState() << "\n"
	<< "Grade to Sign: " << getSignGrade() << "\n"
	<< "Grade to Execute: " << getExecGrade() << std::endl;
}


//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string RobotomyRequestForm::getName(void) const {
	return _name;
}

bool RobotomyRequestForm::getSignState(void) const {
	return _is_signed;
}

int RobotomyRequestForm::getSignGrade(void) const {
	return _sign_grade;
}

int RobotomyRequestForm::getExecGrade(void) const {
	return _exec_grade;
}

std::string RobotomyRequestForm::getTarget(void) const {
	return _target;
}


//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_is_signed == TRUE) {
		std::cout << "Form: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		if (bureaucrat.getGrade() > _sign_grade)
			throw RobotomyRequestForm::GradeTooLowException("Grade is too low to sign the form");
		else {
			_is_signed = TRUE;
		}
	} catch (const std::exception &e) {
		throw;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		AForm::execute(executor);
		robotomize();
	} catch (const std::ios_base::failure& e) {
		std::cerr << "File operation Failed: " << e.what() << std::endl;
		throw;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		throw;
	}
}

void RobotomyRequestForm::robotomize() const {
	std::cout << "Drriiiiiiiiiillll" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));

	if (std::rand() % 2 == 0)
		std::cout << _target << " has been Robotomized" << std::endl;
	else
		std::cout << _target << " Robotomy has Failed" << std::endl;
}