/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:55 by allan             #+#    #+#             */
/*   Updated: 2025/04/22 16:48:42by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//////////////////////////////////////////////////////////
//					CONSTRUCTOR/DESTRUCTOR				//
//////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm() : _name("ShrubberyCreationForm"), _target("None"), _is_signed(FALSE), _sign_grade(145), _exec_grade(137) {
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _name("ShrubberyCreationForm"), _target(target), _is_signed(FALSE), _sign_grade(145), _exec_grade(137) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	AForm(src),
	_name(src.getName()),
	_target(src.getTarget()),
	_sign_grade(src.getSignGrade()),
	_exec_grade(src.getExecGrade()) {
	return ;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
	return ;
}

//////////////////////////////////////////////////////////
//					OVERLOADED OPERATOR					//
//////////////////////////////////////////////////////////

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	_is_signed = rhs.getSignState();
	return *this;
}

AForm* ShrubberyCreationForm::clone() const {
	return new ShrubberyCreationForm(*this);
}

void ShrubberyCreationForm::print(std::ostream& o) const {
	o << "Form Name: " << getName() << "\n"
	<< "Target: " << getTarget() << "\n"
	<< "Signed: " << getSignState() << "\n"
	<< "Grade to Sign: " << getSignGrade() << "\n"
	<< "Grade to Execute: " << getExecGrade() << std::endl;
}


//////////////////////////////////////////////////////////
//						GETTER							//
//////////////////////////////////////////////////////////

const std::string ShrubberyCreationForm::getName(void) const {
	return _name;
}

bool ShrubberyCreationForm::getSignState(void) const {
	return _is_signed;
}

int ShrubberyCreationForm::getSignGrade(void) const {
	return _sign_grade;
}

int ShrubberyCreationForm::getExecGrade(void) const {
	return _exec_grade;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return _target;
}


//////////////////////////////////////////////////////////
//						ACTION							//
//////////////////////////////////////////////////////////

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_is_signed == TRUE) {
		std::cout << "Form: " << _name << ", is already signed" << std::endl;
		return ;
	}
	try {
		if (bureaucrat.getGrade() > _sign_grade)
			throw ShrubberyCreationForm::GradeTooLowException("Grade is too low to sign the form");
		else {
			_is_signed = TRUE;
		}
	} catch (const std::exception &e) {
		throw;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		
		AForm::execute(executor);
		
		std::string file_name = getTarget() + "_shrubbery";
		std::ofstream fout;
		fout.exceptions(std::ios::failbit | std::ios::badbit);
		fout.open(file_name.c_str());

		createTrees(fout);

	} catch (const std::ios_base::failure& e) {
		std::cerr << "File operation Failed: " << e.what() << std::endl;
		throw;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		throw;
	}
}

void ShrubberyCreationForm::createTrees(std::ofstream &fout) const {
	//Get current path
	char buffer[PATH_MAX];	
	if (!getcwd(buffer, sizeof(buffer)))
		throw std::runtime_error(std::string("getcwd() failed: ") + std::strerror(errno));
	
	//Get current dir out of curr path and write it to fout
	std::string full_path(buffer);
	std::string current_dir;

	std::string::size_type lastSlash = full_path.find_last_of("/");
	if (lastSlash == std::string::npos)
		current_dir = full_path;
	else if (lastSlash == full_path.length() - 1)
		current_dir = "/";
	else
		current_dir = full_path.substr(lastSlash + 1);
	fout << current_dir << std::endl;	

	//Get the list of all files and folders of curr dir and write them to fout
	DIR* dir = opendir(".");
	if (!dir)
		throw std::runtime_error(std::string("opendir(\".\") failed: ") + std::strerror(errno));
	
	struct dirent* entry;
	while ((entry = readdir(dir)) != NULL) {
		std::string name(entry->d_name);	
		if (name != "." && name != "..")
			fout << "├── " << name << std::endl;
	}
}