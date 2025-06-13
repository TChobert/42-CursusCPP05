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

	std::cout << GREEN << "======> VALID FORM EXECUTIONS <======" << std::endl;

	AForm	*robotomy = new RobotomyRequestForm("Bender");
	AForm	*pardon = new PresidentialPardonForm("Joe");
	AForm	*shrubbery = new ShrubberyCreationForm("shrub");

	RobotomyRequestForm original("original");
	RobotomyRequestForm copy;
	copy = original;

	middle.signForm(*robotomy);
	middle.executeForm(*robotomy);
	std::cout << std::endl;

	superior.signForm(*pardon);
	superior.executeForm(*pardon);
	std::cout << std::endl;

	superior.signForm(*shrubbery);
	superior.executeForm(*shrubbery);

	superior.signForm(copy);
	superior.executeForm(copy);

	std::cout << RESET << std::endl;

	// INVALID FORM EXECUTIONS

	std::cout << RED << "======> INVALID FORM EXECUTIONS <======" << std::endl;

	AForm	*robotomy2 = new RobotomyRequestForm("Lala");
	AForm	*shrubbery2 = new ShrubberyCreationForm("shrub2");
	AForm	*pardon2 = new PresidentialPardonForm("pardon2");

	stagiaire.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);
	superior.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);
	std::cout << std::endl;

	stagiaire.signForm(*shrubbery2);
	stagiaire.executeForm(*shrubbery2);
	superior.signForm(*shrubbery2);
	stagiaire.executeForm(*shrubbery2);
	std::cout << std::endl;

	stagiaire.signForm(*pardon2);
	stagiaire.executeForm(*pardon2);
	superior.signForm(*pardon2);
	stagiaire.executeForm(*pardon2);

	std::cout << RESET << std::endl;

	// CLEANUP

	delete robotomy;
	delete pardon;
	delete shrubbery;
	delete robotomy2;
	delete pardon2;
	delete shrubbery2;

	return (EXIT_SUCCESS);
}
