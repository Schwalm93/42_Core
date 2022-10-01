/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:43:09 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:43:12 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(), _target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequest", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : Form(cpy), _target(cpy.getTarget() + "_cpy")
{
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	(void)cpy;
	return (*this);
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getExecuteGrade())
			throw Form::GradeTooLowException();
		if (!isSigned())
			throw Form::FormNotSignedException();
		else
		{
			std::cout << "******************************************" << std::endl;
			std::cout << "BzzzZzzzZZZzzzZ BrrRRRRrrrRRRrrrr BzzzzZzz" << std::endl;
			std::cout << "******************************************" << std::endl;
			if ((rand() % 2))
			{
				std::cout << this->getTarget() << " was successfully";
				std::cout << " robotomized !" << std::endl << std::endl;
			}
			else
			{
				std::cout << this->getTarget() << " FAILED to be";
				std::cout << " robotomized !" << std::endl << std::endl;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
