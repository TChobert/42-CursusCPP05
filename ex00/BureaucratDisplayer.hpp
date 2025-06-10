/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayBureaucratInfo.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:50:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/10 14:50:45 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATDISPLAYER_HPP
# define BUREAUCRATDISPLAYER_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class BureaucratDisplayer {

	public:

	BureaucratDisplayer(void);
	BureaucratDisplayer(const BureaucratDisplayer& other);
	BureaucratDisplayer&	operator=(const BureaucratDisplayer& other);
	~BureaucratDisplayer(void);

	void	displayName(const Bureaucrat& bureaucrat) const;
	void	displayGrade(const Bureaucrat& bureaucrat) const;
	void	displayInfo(const Bureaucrat& bureaucrat) const;
};

#endif
