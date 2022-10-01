/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:43:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:43:28 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("ShrubberyCreation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : Form(cpy), _target(cpy.getTarget() + "_cpy")
{
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	(void)cpy;
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream file;
	int i = 0;

	try
	{
		if (executor.getGrade() > getExecuteGrade())
			throw Form::GradeTooLowException();
		if (!isSigned())
			throw Form::FormNotSignedException();
		else
		{
			file.open((this->getTarget() + "_shrubbery").c_str(), std::fstream::out);
			if (!file.is_open())
			{
				std::cout << "Could not open file" << std::endl;
				file.close();
				return;
			}
			while (i < 2)
			{
				file << "             * *" << std::endl;
				file << "          *    *  *" << std::endl;
				file << "      *  *    *     *  *" << std::endl;
				file << "     *     *    *  *    *" << std::endl;
				file << " * *   *    *    *    *   *" << std::endl;
				file << " *     *  *    * * .#  *   *" << std::endl;
				file << " *   *     * #.  .# *   *" << std::endl;
				file << "  *      #.  #: #  * *    *" << std::endl;
				file << " *   * *  #. ##        *" << std::endl;
				file << "   *        ###" << std::endl;
				file << "             ###" << std::endl;
				file << "              ##." << std::endl;
				file << "              .##:" << std::endl;
				file << "              :###" << std::endl;
				file << "              ;###" << std::endl;
				file << "            ,####." << std::endl;
				file << "           .######." << std::endl;
				file << std::endl
					 << std::endl;
				i++;
			}
			file.close();
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}