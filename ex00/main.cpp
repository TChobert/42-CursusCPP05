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

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

int	main(void) {

	// VALID BUREAUCRATS //

	std::cout << GREEN << "======> VALID BUREAUCRATS INSTANCIATIONS <======" << std::endl;
	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 95);
	Bureaucrat	copy;

	std::cout << stagiaire << std::endl;
	std::cout << middle << std::endl;
	std::cout << copy << std::endl;

	std::cout << RESET << std::endl;

	std::cout << GREEN << "======> VALID GRADES INCREMENT AND DECREMENT <======" << std::endl;

	try {
		middle.incrementGrade(50);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		middle.decrementGrade(59);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;

	std::cout << RED << "======> INVALID GRADES INCREMENT AND DECREMENT <======" << std::endl;

	try {
		middle.incrementGrade(500);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		middle.decrementGrade(200);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RESET << std::endl;


	// INVALID BUREAUCRATS

	std::cout << RED << "======> INVALID BUREAUCRATS INSTANCIATIONS <=====" << std::endl;

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

	std::cout << RESET << std::endl;

	return (EXIT_SUCCESS);
}
