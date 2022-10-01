/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:25:15 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:19:08 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FORM_HPP)
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	int const _gradetosign;
	int const _gradetoexec;
	bool _issigned;
	
public:
	Form(void);
	Form(std::string const &, int, int);
	Form(Form const &);
	Form &operator=(Form const &);
	~Form();

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	int getGradetoSign() const;
	int getGradetoExec() const;
	bool getIsSigned() const;
	std::string getName() const;
	void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif


