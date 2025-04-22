/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 16:48:42by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm() : _name("PresidentialPardonForm"), _target("None"), _is_signed(FALSE), _sign_grade(25), _exec_grade(5) {
	return ;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : _name("PresidentialPardonForm"), _target(target), _is_signed(FALSE), _sign_grade(25), _exec_grade(5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	AForm(src),
	_name(src.getName()),
	_target(src.getTarget()),
	_sign_grade(src.getSignGrade()),
	_exec_grade(src.getExecGrade()) {
		return ;
}


PresidentialPardonForm::~PresidentialPardonForm() {
	return ;
}

//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	_is_signed = rhs.getSignState();
	return *this;
}

AForm* PresidentialPardonForm::clone() const {
	return new PresidentialPardonForm(*this);
}

void PresidentialPardonForm::print(std::ostream& o) const {
	o << "Form Name: " << getName() << "\n"
	<< "Target: " << getTarget() << "\n"
	<< "Signed: " << getSignState() << "\n"
	<< "Grade to Sign: " << getSignGrade() << "\n"
	<< "Grade to Execute: " << getExecGrade() << std::endl;
}


//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string PresidentialPardonForm::getName(void) const {
	return _name;
}

bool PresidentialPardonForm::getSignState(void) const {
	return _is_signed;
}

int PresidentialPardonForm::getSignGrade(void) const {
	return _sign_grade;
}

int PresidentialPardonForm::getExecGrade(void) const {
	return _exec_grade;
}

std::string PresidentialPardonForm::getTarget(void) const {
	return _target;
}


//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_is_signed == TRUE) {
		std::cout << "Form: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		if (bureaucrat.getGrade() > _sign_grade)
			throw PresidentialPardonForm::GradeTooLowException("Grade is too low to sign the form");
		else {
			_is_signed = TRUE;
		}
	} catch (const std::exception &e) {
		throw;
	}
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		AForm::execute(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	} catch (const std::ios_base::failure& e) {
		std::cerr << "File operation Failed: " << e.what() << std::endl;
		throw;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		throw;
	}
}