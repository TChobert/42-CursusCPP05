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
	//std::cout << "Bureaucrat: parametrized constructor called" << std::endl;
	if (grade > 150) {
		throw GradeTooLowException();
	}
	if (grade < 1) {
		throw GradeTooHighException();
	}
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

void	Bureaucrat::incrementGrade(int value) {
	if ((_grade - value) < 1) {
		throw GradeTooHighException();
	}
	_grade -= value;
	std::cout << _name << ": is now at grade: " << _grade << std::endl;
}

void	Bureaucrat::decrementGrade(int value) {
	if ((_grade + value) > 150) {
		throw GradeTooLowException();
	}
	_grade += value;
	std::cout << _name << ": is now at grade: " << _grade << std::endl;
}

void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << getName() << "couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

///// EXCEPTIONS /////

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade is too low!");
};

///// OPERATOR << /////

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
