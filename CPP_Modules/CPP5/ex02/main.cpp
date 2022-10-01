/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:42:10 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:42:13 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat bur1("Bur 1", 1);
	Bureaucrat bur2("Bur 2", 150);

	ShrubberyCreationForm shrubby("Bathroom");
	RobotomyRequestForm robot("Tree");
	PresidentialPardonForm presi("Tom");

	std::cout << "Test 1: Execute a not signed form" << std::endl;
	std::cout << shrubby;
	bur1.executeForm(shrubby);

	std::cout << "\nTest 2: Execute with a too low grade" << std::endl;
	std::cout << bur2 << "Grade needed to execute: 145" << std::endl;
	bur2.executeForm(shrubby);

	std::cout << "\nTest 3: Sign form and execute" << std::endl;
	std::cout << shrubby;
	std::cout << bur1;
	bur1.signForm(shrubby);
	bur1.executeForm(shrubby);

	std::cout << "\nTest 4: Sign Robo form and execute" << std::endl;
	bur1.signForm(robot);
	bur1.executeForm(robot);

	std::cout << "\nTest 4: Sign Presidential form and execute" << std::endl;
	bur1.signForm(presi);
	bur1.executeForm(presi);
	return (0);
}