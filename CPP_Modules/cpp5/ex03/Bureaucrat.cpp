/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:37 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:47:48 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :_name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		this->_grade = 75;
		std::cout << "Grade out of range. Set to default 75." << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): _name(rhs._name)
{
	*this = rhs;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

std::string const &Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << getName() << " could not sign " << form.getName() << " because of: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << getName() << " successfully executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << getName() << " could not execute " << form.getName() << " because of: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ")";
	return (out);
}
