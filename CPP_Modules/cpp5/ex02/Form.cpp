/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:42:28 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"), _signed(false), _gradeSign(75), _gradeExecute(75)
{
}

Form::Form(std::string const &name, const int gradeSign, const int gradeExecute) :_name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExecute > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(const Form &rhs) : _name(rhs._name), _gradeSign(rhs._gradeSign), _gradeExecute(rhs._gradeExecute)
{
	*this = rhs;
}

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return ("FormException: Form already signed");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("FormException: Form needs to be signed first");
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		_signed = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " succesfully signed the " << getName() << " Form." << std::endl;
	}
}

 const std::string& Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_gradeSign);
}

int Form::getExecuteGrade() const
{
	return (_gradeExecute);
}

std::ostream& operator<<(std::ostream& out, Form const &form)
{
	out << "Form Name -> " << form.getName() << std::endl << "Status Signature --> " << form.isSigned() << std::endl << "Grade for signing --> " << form.getSignGrade() << std::endl << "Grade for Exceuting --> " << form.getExecuteGrade() << std::endl;

	return (out);
}