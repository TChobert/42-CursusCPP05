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
# include "AForm.hpp"

class Intern {

	public:

	Intern(void);
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern(void);
	AForm	*makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif
