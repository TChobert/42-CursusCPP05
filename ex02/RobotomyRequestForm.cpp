/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:45:30 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/12 13:45:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

///// CANONICAL /////

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false, 72, 45), _target("Default") {
	//std::cout << "RobotomyRequestForm: default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {
	//std::cout << "RobotomyRequestForm: parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	//std::cout << "RobotomyRequestForm: copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		//std::cout << "RobotomyRequestForm: affectation operator called" << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	//std::cout << "RobotomyRequestForm: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {

	if (getSignStatus() == false) {
			throw FormNotSignedException();
		}
		if (executor.getGrade() > getGradeToExecute()) {
			throw GradeTooLowException();
		}
		std::cout << "Makes some drilling noises..." << std::endl;
		if (rand() % 2 == 0) {
			std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
		}
		else {
			std::cout << getTarget() << ": robotomy failed!" << std::endl;
		}
}
