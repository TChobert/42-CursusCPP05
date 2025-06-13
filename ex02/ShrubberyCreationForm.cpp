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

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("target") {
	//std::cout << "ShrubberyCreationForm: default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
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

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::printAsciiTrees(const std::string& target) const {

	std::ofstream	fileStream((target + "_shrubbery").c_str());
	if (fileStream.is_open() == false) {
		throw std::runtime_error("ShrubberyCreationForm: File creation failed " + target);
	}
	for (size_t i = 0; i < 3; ++i) {
		fileStream << "       _-_" << std::endl;
	fileStream << "    /~~   ~~\\" << std::endl;
	fileStream << " /~~         ~~\\" << std::endl;
	fileStream << "{               }" << std::endl;
	fileStream << " \\  _-     -_  /" << std::endl;
	fileStream << "   ~  \\\\ //  ~" << std::endl;
	fileStream << "_- -   | | _- _" << std::endl;
	fileStream << "  _ -  | |   -_" << std::endl;
	fileStream << "      // \\\\" << std::endl;
	}
	fileStream.close();
	if (fileStream.fail()) {
		throw std::runtime_error("ShrubberyRequestForm: failed to close file properly " + target);
	}
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (getSignStatus() == false) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	printAsciiTrees(getTarget());
}
