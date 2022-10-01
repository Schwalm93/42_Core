/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:18 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:48:53 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExecute;

public:
	Form();
	Form(std::string const &name, const int gradeSign, const int gradeExecute);
	Form(const Form &rhs);
	Form& operator=(const Form &rhs);
	virtual ~Form();

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
	void beSigned(Bureaucrat const &bureaucrat);
	const std::string& getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	virtual void execute(Bureaucrat const &executor) const = 0;
	
};

std::ostream& operator<<(std::ostream &out, Form const &form);

#endif