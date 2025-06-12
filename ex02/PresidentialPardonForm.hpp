/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:13:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/12 14:14:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:

	std::string	_target;

	public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	void	execute(const Bureaucrat& executor);
};

#endif
