/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:44:43 by allan             #+#    #+#             */
/*   Updated: 2025/04/21 15:36:01 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

#define FALSE 0
#define TRUE 1

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string name, const int sign_grade, const int exec_grade);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form &rhs);
		const std::string getName(void) const;
		bool getSignState(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		int check_input(int grade) const;
		void beSigned(const Bureaucrat& bureaucrat);
		
		private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
		
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(const char*m) : _msg(m) {}
				const char* what() const throw() {
					return _msg;
				}	
			private:
				const char* _msg;
		};
		
		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(const char*m) : _msg(m) {}
				const char* what() const throw() {
					return _msg;
				}	
			private:
				const char* _msg;
		};
};

std::ostream &operator<<(std::ostream &o, const Form &i);

#endif