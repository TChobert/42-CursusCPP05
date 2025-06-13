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
#include "Form.hpp"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

int	main(void) {

	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 95);
	Bureaucrat	copy;
	Form		formA;

	//std::cout << formA << std::endl;

	// INVALID FORMS //

	std::cout << RED << "======> INVALID FORM INSTANCIATIONS <======" << std::endl;

	try {
		Form	invalidFormLow("Invalid", false, 156, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormHigh("Invalid", false, 0, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormLow("Invalid", false, 22, 185);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormHigh("Invalid", false, 22, -12);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;

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

	// INVALID FORM SIGN ATTEMPT

	Form	formToSignInvalid("ToSignInvalid", false, 20, 50);
	Bureaucrat	signer("Random", 25);

	signer.signForm(formToSignInvalid);

	// VALID FORM SIGN ATTEMPT

	Form	formToSignValid("ToSignInvalid", false, 20, 50);
	Bureaucrat	signer2("Random2", 15);

	signer2.signForm(formToSignValid);

	std::cout << stagiaire << std::endl;
	std::cout << middle << std::endl;
	std::cout << copy << std::endl;
	return (EXIT_SUCCESS);
}
