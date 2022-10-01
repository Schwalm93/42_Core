/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:09:35 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:26:51 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//*Constructor*//

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
}

//*Methods*//

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade > 1)
		{
			this->_grade--;
		}
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade < 150)
		{
			this->_grade++;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because grade to low" << std::endl;
}

//*Execptions*//

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Exception Grade to High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Exception Grade to Low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
	return (out << value.getName() << ", " << "bureaucrat grade " << value.getGrade());
}