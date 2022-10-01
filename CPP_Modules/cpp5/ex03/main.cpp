/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:48:04 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:50:46 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;
	Form *forms[4];
	forms[0] = intern.makeForm("ShrubberyCreation", "Home");
	forms[1] = intern.makeForm("RobotomyRequest", "Dog");
	forms[2] = intern.makeForm("PresidentialPardon", "Chris");
	forms[3] = intern.makeForm("bla", "bla");

	for (int i = 0; i < 4; i++)
	{
		delete forms[i];
	}
	return (0);
}