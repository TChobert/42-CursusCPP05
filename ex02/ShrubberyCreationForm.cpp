/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:21:33 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/12 12:21:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

///// CANONICAL /////

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", false, 145, 137), _target("target") {
	//std::cout << "ShrubberyCreationForm: default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	//std::cout << "ShrubberyCreationForm: parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	//std::cout << "ShrubberyCreationForm: copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm&  other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		//std::cout << "ShrubberyCreationForm: affectation operator called" << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	//std::cout << "ShrubberyCreationForm: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (getSignStatus() == false) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
}
