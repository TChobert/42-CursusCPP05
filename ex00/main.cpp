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

int	main(void) {

	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 95);
	Bureaucrat	copy;

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
	std::cout << stagiaire.getName() << ": " << stagiaire.getGrade() << std::endl;
	std::cout << middle.getName() << ": " << middle.getGrade() << std::endl;
	std::cout << copy.getName() << ": " << copy.getGrade() << std::endl;
	return (EXIT_SUCCESS);
}
