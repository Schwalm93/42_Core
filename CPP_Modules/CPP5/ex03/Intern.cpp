/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:47:53 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:47:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;
}

Intern& Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
}

Form* Intern::makeForm(std::string const name, std::string const target)
{
	std::string form[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	int caseNumb = -1;
	Form *tmp = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form[i] == name)
		{
			caseNumb = i;
			break ;
		}
	}
	switch (caseNumb)
	{
		case 0:
			tmp = new ShrubberyCreationForm(target);
			std::cout << "Intern creates form " << name << std::endl;
			break;
		case 1:
			tmp = new RobotomyRequestForm(target);
			std::cout << "Intern creates form " << name << std::endl;
			break;
		case 2:
			tmp = new PresidentialPardonForm(target);
			std::cout << "Intern creates form " << name << std::endl;
			break;
		default:
			std::cout << "Intern can not create form " << name << " as it does not exist." << std::endl;
			break;
	}
	return (tmp);
}