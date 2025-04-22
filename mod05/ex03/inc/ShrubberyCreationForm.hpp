/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:30:28 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 17:05:15 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <cstring>
#include <cerrno>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		AForm* clone() const;
		void print(std::ostream& o) const;
		
		const std::string getName(void) const;
		bool getSignState(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		std::string getTarget(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
		void createTrees(std::ofstream & fout) const;
		
	private:
		const std::string _name;
		const std::string _target;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
};

#endif