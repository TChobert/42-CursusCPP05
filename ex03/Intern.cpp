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
	//std::cout << "Intern: copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	//std::cout << "Intern: assignement operator called" << std::endl;
	if (this != &other) {
	}
	return (*this);
}

Intern::~Intern(void) {
	//std::cout << "Intern: destructor called" << std::endl;
}

AForm	*Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
}
