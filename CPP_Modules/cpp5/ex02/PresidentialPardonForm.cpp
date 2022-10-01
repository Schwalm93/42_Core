/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:55 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:42:57 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(), _target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : Form(cpy), _target(cpy.getTarget() + "_cpy")
{
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	(void)cpy;
	return (*this);
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getExecuteGrade())
			throw Form::GradeTooLowException();
		if (!isSigned())
			throw Form::FormNotSignedException();
		else
			std::cout << this->getTarget() << " has been pardoned by God" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
