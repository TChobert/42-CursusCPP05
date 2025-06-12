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

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", false, 25, 5), _target("Default") {
	//std::cout << "PresidentialPardonForm: default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
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

