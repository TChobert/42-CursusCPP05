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

	std::cout << GREEN << "======> VALID FORM INSTANCIATIONS <======" << std::endl;
	
	Form	formA;
	std::cout << formA << std::endl;

	Form	formB("SuspectForm", 50, 50);
	std::cout << formB << std::endl;

	Form	formC(formB);
	std::cout << formC << std::endl;

	std::cout << RESET << std::endl;

	// INVALID FORMS //

	std::cout << RED << "======> INVALID FORM INSTANCIATIONS <======" << std::endl;

	try {
		Form	invalidFormLow("Invalid", 156, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormHigh("Invalid", 0, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormTooHigh("Invalid", -52, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormLow("Invalid", 22, 185);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	invalidFormHigh("Invalid", 22, -12);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;

	// INVALID FORM SIGN ATTEMPT

	std::cout << RED << "======> INVALID FORM SIGN ATTEMPTS <======" << std::endl;

	Form	formToSignInvalid("ToSignInvalid", 20, 50);
	Bureaucrat	signer("Random", 25);

	signer.signForm(formToSignInvalid);

	std::cout << RESET << std::endl;

	std::cout << GREEN << "======> VALID FORM SIGN ATTEMPTS <======" << std::endl;

	// VALID FORM SIGN ATTEMPT

	Form	formToSignValid("ToSignValid", 20, 50);
	Bureaucrat	signer2("Random2", 15);

	signer2.signForm(formToSignValid);
	signer2.signForm(formToSignValid);

	std::cout << RESET << std::endl;

	return (EXIT_SUCCESS);
}
