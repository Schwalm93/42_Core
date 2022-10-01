/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:25:30 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 03:13:59 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradetosign(75), _gradetoexec(75)
{
	this->_issigned = false;
}

Form::Form(std::string const &name, int gradetosign, int gradetoexec) : _name(name), _gradetosign(gradetosign), _gradetoexec(gradetoexec)
{
	try
	{
		if (_gradetosign > 150 || _gradetoexec > 150)
			throw Form::GradeTooLowException();
		else if (_gradetosign < 1 || _gradetoexec < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	this->_issigned = false;
}

Form::~Form()
{
}

int Form::getGradetoSign() const
{
	return(this->_gradetosign);
}

int Form::getGradetoExec() const
{
	return(this->_gradetoexec);
}
bool Form::getIsSigned() const
{
	return(this->_issigned);
}

std::string Form::getName() const
{
	return(this->_name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception Grade to High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception Grade to Low");
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getGradetoSign())
			throw Form::GradeTooLowException();
		else if (bureaucrat.getGrade() < this->getGradetoSign())
			this->_issigned = true;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Form const &value)
{
	std::string formsigned = "False";

	if (value.getIsSigned())
	{
		formsigned = "True";
	}
	return (out << "Form " << value.getName() << ", grade to sign " << value.getGradetoSign() << 
	", grade to exec " << value.getGradetoExec() << " Signed: " << formsigned << std::endl);
}