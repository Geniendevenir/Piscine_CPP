/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm {
	public:
		AForm();
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);
		virtual void print(std::ostream& out) const;
		virtual int check_input(int grade) const;
		virtual AForm* clone() const = 0;

		virtual const std::string getName(void) const;
		virtual bool getSignState(void) const;
		virtual int getSignGrade(void) const;
		virtual int getExecGrade(void) const;

		virtual void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const;
		
		private:
			const std::string _name;
			bool _is_signed;
			const int _sign_grade;
			const int _exec_grade;

		protected:	
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

			class FormNotSigned: public std::exception {
				public:
					FormNotSigned(const char*m) : _msg(m) {}
					const char* what() const throw() {
						return _msg;
					}	
				private:
					const char* _msg;
			};
};

std::ostream &operator<<(std::ostream &o, const AForm &i);

#endif