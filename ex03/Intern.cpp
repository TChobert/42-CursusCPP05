/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:39 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/13 17:36:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

///// CANONICAL /////

Intern::Intern(void) {
	//std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	//std::cout << "Intern: copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	//std::cout << "Intern: assignement operator called" << std::endl;
	if (this != &other) {}
	return (*this);
}

Intern::~Intern(void) {
	//std::cout << "Intern: destructor called" << std::endl;
}

///// EXCEPTION /////

const char	*Intern::InvalidForm::what() const throw() {
	return ("Intern: Invalid form type");
}

///// MEMBER FUNCTION /////

AForm	*Intern::makeForm(const std::string& formName, const std::string& formTarget) const {

	static const std::string	formNames[FORMS_NB] = {"shrubbery", "robotomy", "presidential"};
	formTypes	type = UNKNOWN;

	for (size_t i = 0; i < FORMS_NB; ++i) {
		if (formName.find(formNames[i]) != std::string::npos) {
			type = formTypes(i);
			break ;
		}
	}
	switch (type) {
		case SHRUBBERY:
		 	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case ROBOTOMY:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case PRESIDENTIAL:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
		case UNKNOWN:
			throw InvalidForm();
	}
	return (NULL);
}
