/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:13:13 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/10 16:13:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

///// CANONICAL /////

Form::Form(void) : _name("Default"), _isSigned(false), _gradeRequieredtoSign(150),
	_gradeRequieredtoExecute(150) {
	//std::cout << "Form: default constructor called" << std::endl;
	if (_gradeRequieredtoSign > 150 ||  _gradeRequieredtoExecute > 150) {
		throw (GradeTooLowException());
	}
	if (_gradeRequieredtoSign < 1 || _gradeRequieredtoExecute < 1) {
		throw (GradeTooHighException());
	}
}

Form::Form(const std::string& name, bool isSigned, const unsigned int gradeRequieredToSign,
	const unsigned int gradeRequieredToExecute) :_name(name), _isSigned(isSigned),
	_gradeRequieredtoSign(gradeRequieredToSign), _gradeRequieredtoExecute(gradeRequieredToExecute) {
	//std::cout << "Form: parametrized constructor called" << std::endl;
	if (_gradeRequieredtoSign > 150 ||  _gradeRequieredtoExecute > 150) {
		throw (GradeTooLowException());
		}
	if (_gradeRequieredtoSign < 1 || _gradeRequieredtoExecute < 1) {
		throw (GradeTooHighException());
	}
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
	_gradeRequieredtoSign(other._gradeRequieredtoSign), _gradeRequieredtoExecute(other._gradeRequieredtoExecute) {
	//std::cout << "Form: copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
		//std::cout << "Form: assignment operator called" << std::endl;
	}
	return (*this);
}

Form::~Form(void) {
	//std::cout << "Form: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////



///// EXCEPTIONS /////

const char 	*Form::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Form: grade is too low!");
}
