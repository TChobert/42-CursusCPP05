/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/12 14:17:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

///// CANONICAL /////

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
	//std::cout << "PresidentialPardonForm: default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	//std::cout << "PresidentialPardonForm: parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :AForm(other), _target(other._target) {
	//std::cout << "PresidentialPardonForm: copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		//std::cout << "PresidentialPardonForm: affectation operator called" << std::endl;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	//std::cout << "PresidentialPardonForm: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (getSignStatus() == false) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
