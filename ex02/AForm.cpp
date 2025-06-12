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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

///// CANONICAL /////

AForm::AForm(void) : _name("Default"), _isSigned(false), _gradetoSign(150),
	_gradetoExecute(150) {
	//std::cout << "Form: default constructor called" << std::endl;
	if (_gradetoSign > 150 ||  _gradetoExecute > 150) {
		throw (GradeTooLowException());
	}
	if (_gradetoSign < 1 || _gradetoExecute < 1) {
		throw (GradeTooHighException());
	}
}

AForm::AForm(const std::string& name, bool isSigned, const unsigned int gradeToSign,
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

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned),
	_gradetoSign(other._gradetoSign), _gradetoExecute(other._gradetoExecute) {
	//std::cout << "Form: copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
		//std::cout << "Form: assignment operator called" << std::endl;
	}
	return (*this);
}

AForm::~AForm(void) {
	//std::cout << "Form: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getSignStatus(void) const {
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const {
	return (_gradetoSign);
}

int	AForm::getGradeToExecute(void) const {
	return (_gradetoExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradetoSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

///// EXCEPTIONS /////

const char 	*AForm::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("Form: grade is too low!");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("Form: form is not signed!");
}

///// OPERATOR << /////

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << "Form name: " << form.getName() << ", signed: " << form.getSignStatus() << ", requiered grade to sign: " << form.getGradeToSign() << ", requiered grade to execute: " << form.getGradeToExecute() << ".";
	return (os);
}
