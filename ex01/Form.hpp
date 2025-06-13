/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:03:50 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/10 16:04:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class	Bureaucrat;

class Form {

	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradetoSign;
	const int			_gradetoExecute;

	public:

	Form(void);
	Form(const std::string& name, bool isSigned, const int gradeToSign,
			const int gradeToExecute);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form(void);

	std::string		getName(void) const;
	bool			getSignStatus(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExecute(void) const;
	void			beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException: public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
