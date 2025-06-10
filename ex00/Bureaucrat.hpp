/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:51:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/06 16:51:46 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <cstdlib>
# include <iostream>

class Bureaucrat {

	private:

	const std::string	_name;
	int					_grade;

	public:

	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat(void);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(unsigned int value);
	void		decrementGrade(unsigned int value);

	class GradeToHighException: public std::exception {
		virtual const char *what() const throw();
	};
	class GradeToLowException: public std::exception {
		virtual const char *what() const throw();
	};
};

#endif
