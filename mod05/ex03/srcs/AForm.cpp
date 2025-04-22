/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:55:04 by allan             #+#    #+#             */
/*   Updated: 2025/04/21 15:56:25 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

AForm::AForm() : _name("None"), _is_signed(FALSE), _sign_grade(150), _exec_grade(150) {
	return ;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
	try :	_name(name),
			_is_signed(FALSE),
			_sign_grade(check_input(sign_grade)),
			_exec_grade(check_input(exec_grade)) {}
	catch (const std::exception& e) {
		std::cerr << "Caught Grade Exception: " << e.what() << std::endl;
		throw;
	} 

AForm::AForm(const AForm &src)
	try :	_name(src._name),
			_is_signed(src._is_signed),
			_sign_grade(check_input(src._sign_grade)),
			_exec_grade(check_input(src._exec_grade)) {}
	catch (const std::exception& e) {
		std::cerr << "Caught Grade Exception: " << e.what() << std::endl;
		throw;
	} 


AForm::~AForm() {
	//std::cout << _name << " Destructor Called" << std::endl;
	return ;
}

int AForm::check_input(int grade) const {
	if (grade <= 0)
		throw AForm::GradeTooHighException("Error: Constructor: Parameter sign/exec grade is too High");
	else if (grade > 150)
		throw AForm::GradeTooLowException("Error: Constructor: Parameter sign/exec grade is too Low");
	return grade;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

//Can't copy const name, _sign_grade/_exec_grade
AForm& AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		_is_signed = rhs._is_signed;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const AForm &i) {
	i.print(o);
	return o;
}

void AForm::print(std::ostream& o) const {
	o << "Form Name: " << getName() << "\n"
	<< "Signed: " << getSignState() << "\n"
	<< "Grade to Sign: " << getSignGrade() << "\n"
	<< "Grade to Execute: " << getExecGrade() << std::endl;
}

//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string AForm::getName(void) const {
	return _name;
}

bool AForm::getSignState(void) const {
	return _is_signed;
}

int AForm::getSignGrade(void) const {
	return _sign_grade;
}

int AForm::getExecGrade(void) const {
	return _exec_grade;
}


//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_is_signed == TRUE) {
		std::cout << "AForm: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		if (bureaucrat.getGrade() > _sign_grade)
			throw AForm::GradeTooLowException("Grade is too low to sign the form");
		else
			_is_signed = TRUE;	
	} catch (const std::exception &e) {
		throw;
	}
}

void AForm::execute(Bureaucrat const & executor) const {
	if (getSignState() == FALSE)
		throw AForm::FormNotSigned("The Form is not signed");
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException("Grade is too low to execute the form");
}

