/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm copy.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:30:28 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 16:54:57 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		AForm* clone() const;
		void print(std::ostream& o) const;
		
		const std::string getName(void) const;
		bool getSignState(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		std::string getTarget(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
		
	private:
		const std::string _name;
		const std::string _target;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
};

#endif