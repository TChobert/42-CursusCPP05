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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class	Bureaucrat;

class AForm {

	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradetoSign;
	const int			_gradetoExecute;

	public:

	AForm(void);
	AForm(const std::string& name, bool isSigned, const unsigned int gradeToSign,
			const unsigned int gradeToExecute);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm(void);

	std::string		getName(void) const;
	bool			getSignStatus(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExecute(void) const;
	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException: public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw();
	};
	class FormNotSignedException: public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
