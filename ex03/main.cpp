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

#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

int	main(void) {

	srand(time(NULL));
	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 25);
	Bureaucrat	superior("Superior", 1);

	// VALID FORM EXECUTIONS

	std::cout << GREEN << "======> VALID FORM CREATIONS & EXECUTIONS <======" << std::endl;

	Intern	intern;

	try {
		AForm	*robotomy = intern.makeForm("robotomy request", "Bender");
		middle.signForm(*robotomy);
		middle.executeForm(*robotomy);
		delete robotomy;
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		AForm	*pardon = intern.makeForm("presidential pardon", "Joe");
		superior.signForm(*pardon);
		superior.executeForm(*pardon);
		delete pardon;
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		AForm	*shrubbery = intern.makeForm("shrubbery creation", "test");
		superior.signForm(*shrubbery);
		superior.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;

	// INVALID FORM EXECUTIONS

	std::cout << RED << "======> INVALID FORM CREATIONS <======" << std::endl;

	try {
		AForm	*robotomy2 = intern.makeForm("bobotomy", "Aie");
		std::cout << "Unexpected success: " << robotomy2 << std::endl;
		delete robotomy2;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		AForm	*shrubbery2 = intern.makeForm("shrubberie", "non");
		std::cout << "Unexpected success: " << shrubbery2 << std::endl;
		delete shrubbery2;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		AForm	*pardon2 = intern.makeForm("parrdon", "");
		std::cout << "Unexpected success: " << pardon2 << std::endl;
		delete pardon2;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;

	return (EXIT_SUCCESS);
}
