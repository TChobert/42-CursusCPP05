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
#include "Bureaucrat.hpp"

///// CANONICAL /////

Form::Form(void) : _name("Default"), _isSigned(false), _gradetoSign(150),
	_gradetoExecute(150) {
	//std::cout << "Form: default constructor called" << std::endl;
	if (_gradetoSign > 150 ||  _gradetoExecute > 150) {
		throw (GradeTooLowException());
	}
	if (_gradetoSign < 1 || _gradetoExecute < 1) {
		throw (GradeTooHighException());
	}
}

Form::Form(const std::string& name, bool isSigned, const unsigned int gradeToSign,
	const unsigned int gradeToExecute) :_name(name), _isSigned(isSigned),
	_gradetoSign(gradeToSign), _gradetoExecute(gradeToExecute) {
	//std::cout << "Form: parametrized constructor called" << std::endl;
	if (gradeToSign > 150 ||  gradeToExecute > 150) {
		throw (GradeTooLowException());
		}
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw (GradeTooHighException());
	}
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
	_gradetoSign(other._gradetoSign), _gradetoExecute(other._gradetoExecute) {
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

std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getSignStatus(void) const {
	return (_isSigned);
}

unsigned int	Form::getGradeToSign(void) const {
	return (_gradetoSign);
}

unsigned int	Form::getGradeToExecute(void) const {
	return (_gradetoExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > _gradetoSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

///// EXCEPTIONS /////

const char 	*Form::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Form: grade is too low!");
}

///// OPERATOR << /////

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	os << "Form name: " << form.getName() << ", signed: " << form.getSignStatus() << ", requiered grade to sign: " << form.getGradeToSign() << ", requiered grade to execute: " << form.getGradeToExecute() << ".";
	return (os);
}
