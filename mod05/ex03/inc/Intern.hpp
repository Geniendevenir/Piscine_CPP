/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:46:01 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 20:40:15 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &rhs);
		std::string getFormName(int index) const;
		AForm *makeForm(std::string name, std::string target);		
	
	private:
		std::string _forms_names[3];
};

std::ostream &operator<<(std::ostream &o, const Intern &i);

#endif