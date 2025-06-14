/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:10:02 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/13 17:10:29 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORMS_NB 3

typedef enum formTypes {
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL,
	UNKNOWN
};

class Intern {

	public:

	Intern(void);
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern(void);
	AForm	*makeForm(const std::string& formName, const std::string& formTarget) const;

	class InvalidForm: public std::exception {
		virtual const char *what() const throw();
	};
};

#endif
