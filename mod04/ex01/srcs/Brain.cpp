/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:26:23 by allan             #+#    #+#             */
/*   Updated: 2025/04/19 11:24:58 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain() {
	std::cout << "Brain Default Constructor called" << std::endl;
	ideas = new std::string[100];
	return ;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++) {
		ideas[i] = src.ideas[i];	
	}
	return ;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
	delete[] ideas;
	return ;
}

Brain& Brain::operator=(const Brain &rhs) {
	//Check for self-assignment same = same
	if (this == &rhs)
		return *this;
	
	std::string *new_ideas = new std::string[100];
	for (int i = 0; i < 100; i++) {
		new_ideas[i] = rhs.ideas[i];	
	}
	
	delete[] ideas;
	ideas = new_ideas;
	
	return *this;
}

std::string Brain::getIdea(int i) const {
	return this->ideas[i];
}

void Brain::setIdea(int i, std::string new_idea) {
	if (ideas[i].empty())
		ideas[i] = new_idea;	
}

std::ostream &operator<<(std::ostream &o, const Brain &i) {
	for (int j = 0; j < 100; j++) {
		if (!i.getIdea(j).empty()) 
			o << i.getIdea(j) << std::endl;
	}
	return o;
}
