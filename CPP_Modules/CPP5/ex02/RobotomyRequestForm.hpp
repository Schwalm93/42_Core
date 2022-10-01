/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:43:20 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:43:22 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	std::string const _target;

public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &cpy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &cpy);

	const std::string getTarget(void) const;
	void execute(Bureaucrat const &executor) const;
};

#endif