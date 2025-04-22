/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:59:00 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 14:09:48 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);
		
		const std::string getName(void) const;
		int getGrade(void) const;
		
		void upGrade();
		void downGrade();
		void signForm(AForm &to_sign) const;
		void executeForm(AForm const & form) const;

	private:
		const std::string _name;
		int _grade;
		
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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i);

#endif