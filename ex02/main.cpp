/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:32:20 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/06 17:37:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {

	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 95);
	Bureaucrat	superior("Superior", 1);
	Bureaucrat	copy;

	// INVALID BUREAUCRATS //

	try {
		Bureaucrat	invalidToLow("Aouch", 175);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	High("Aie", 0);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	copy = stagiaire;

	try {
		stagiaire.decrementGrade(22);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		middle.incrementGrade(50);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// VALID FORM EXECUTIONS

	AForm	*robotomy = new RobotomyRequestForm("Bender");
	AForm	*pardon = new PresidentialPardonForm("Joe");
	middle.signForm(*robotomy);
	middle.executeForm(*robotomy);
	superior.signForm(*pardon);
	superior.executeForm(*pardon);

	// INVALID FORM EXECUTIONS

	RobotomyRequestForm	*robotomy2 = new RobotomyRequestForm("Lala");

	stagiaire.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);
	superior.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);

	std::cout << stagiaire << std::endl;
	std::cout << middle << std::endl;
	std::cout << copy << std::endl;

	delete robotomy;
	delete pardon;
	delete robotomy2;

	return (EXIT_SUCCESS);
}
