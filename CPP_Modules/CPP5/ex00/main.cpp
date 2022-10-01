/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:08:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/29 07:18:45 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::string a = "test";
	Bureaucrat jon("jon", 1);

	jon.getName();
	jon.getGrade();
	jon.incrementGrade();
	jon.getGrade();
	jon.decrementGrade();
	jon.getGrade();

	std::cout << jon << std::endl;

	return (0);
}