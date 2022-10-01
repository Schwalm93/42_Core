/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:42:34 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat& operator=(const Bureaucrat &rhs);
		~Bureaucrat();
		
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

		std::string const &getName(void) const;
		int getGrade(void) const;
		void setGrade(int grade);
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);
		void executeForm(Form const &form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif