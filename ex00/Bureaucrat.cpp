/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:56:29 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/06 16:56:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

///// CANONICAL /////

Bureaucrat::Bureaucrat(void) : _name("Stagiaire"), _grade(150) {
	//std::cout << "Bureaucrat: default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	//std::cout << "Bureaucrat: parametrized constructor called" :: std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	//std::cout << "Bureaucrat: copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	//std::cout << "Bureaucrat: assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	//std::cout << "Bureaucrat: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}
