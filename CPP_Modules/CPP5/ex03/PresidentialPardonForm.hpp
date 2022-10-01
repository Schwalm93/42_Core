/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:43:02 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:43:03 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
#define PRESIDENTIALPARDON_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
private:
	std::string const _target;

public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &cpy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &cpy);

	const std::string getTarget(void) const;
	void execute(Bureaucrat const &executor) const;
};

#endif