/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratDisplayer.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:57:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/10 14:57:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucratDisplayer.hpp"

///// CANONICAL /////

BureaucratDisplayer::BureaucratDisplayer(void) {
	//std::cout << "BureaucratDisplayer: default constructor called" << std::endl;
}

BureaucratDisplayer::BureaucratDisplayer(const BureaucratDisplayer& other) {
	(void)other;
	//std::cout << "BureaucratDisplayer: copyconstructor called" << std::endl;
}

BureaucratDisplayer&	BureaucratDisplayer::operator=(const BureaucratDisplayer& other) {
	if (this != &other) {
		//std::cout << "BureaucratDisplayer: assignment operator called" << std::endl;
	}
	return (*this);
}

BureaucratDisplayer::~BureaucratDisplayer(void) {
	//std::cout << "BureaucratDisplayer: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	BureaucratDisplayer::displayName(const Bureaucrat& bureaucrat) const {
	std::cout << bureaucrat.getName() << std::endl;
}

void	BureaucratDisplayer::displayGrade(const Bureaucrat& bureaucrat) const {
	std::cout << bureaucrat.getGrade() << std::endl;
}

void	BureaucratDisplayer::displayInfo(const Bureaucrat& bureaucrat) const {
	std::cout << "Name: " << bureaucrat.getName() << " - Grade: " << bureaucrat.getGrade() << std::endl;
}