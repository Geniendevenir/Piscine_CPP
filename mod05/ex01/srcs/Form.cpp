/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:55:04 by allan             #+#    #+#             */
/*   Updated: 2025/04/21 15:56:25 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

Form::Form() : _name("None"), _is_signed(FALSE), _sign_grade(150), _exec_grade(150) {
	return ;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
	try :	_name(name),
			_is_signed(FALSE),
			_sign_grade(check_input(sign_grade)),
			_exec_grade(check_input(exec_grade)) {}
	catch (const std::exception& e) {
		std::cerr << "Caught Grade Exception: " << e.what() << std::endl;
		throw;
	} 

Form::Form(const Form &src)
	try :	_name(src._name),
			_is_signed(src._is_signed),
			_sign_grade(check_input(src._sign_grade)),
			_exec_grade(check_input(src._exec_grade)) {}
	catch (const std::exception& e) {
		std::cerr << "Caught Grade Exception: " << e.what() << std::endl;
		throw;
	} 


Form::~Form() {
	std::cout << _name << " Destructor Called" << std::endl;
	return ;
}

int Form::check_input(int grade) const {
	if (grade <= 0)
		throw Form::GradeTooHighException("Error: Constructor: Parameter sign/exec grade is too High");
	else if (grade > 150)
		throw Form::GradeTooLowException("Error: Constructor: Parameter sign/exec grade is too Low");
	return grade;
}


//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

//Can't copy const name, _sign_grade/_exec_grade
Form& Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		_is_signed = rhs._is_signed;
	}
	return *this;
}


std::ostream &operator<<(std::ostream &o, const Form &i) {
	o << "Form: " << i.getName() << "\n"
	<< "Signed: " << i.getSignState() << "\n"
	<< "Grade to Sign: " << i.getSignGrade() << "\n"
	<< "Grade to Execute: " << i.getExecGrade() << std::endl;
	return o;
}

//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string Form::getName(void) const {
	return _name;
}

bool Form::getSignState(void) const {
	return _is_signed;
}

int Form::getSignGrade(void) const {
	return _sign_grade;
}

int Form::getExecGrade(void) const {
	return _exec_grade;
}


//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_is_signed == TRUE) {
		std::cout << "Form: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		if (bureaucrat.getGrade() > _sign_grade)
			throw Form::GradeTooLowException("Grade is too low to sign the form");
		else
			_is_signed = TRUE;	
	} catch (const std::exception &e) {
		throw;
	}
}
