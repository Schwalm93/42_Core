/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:08:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/30 04:26:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::string a = "test";
	Bureaucrat jon("jon", 5);

	std::cout << jon << std::endl;

	Form form("Contract", 1, 10);

	jon.signForm(form);
	std::cout << form;
	return (0);
}