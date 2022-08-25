/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 01:00:02 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/25 04:16:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ Debug ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << "[ Info ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[ Warning ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ Error ]\nThis is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string a[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int n;

	n = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (level.compare(a[i]) == 0)
		{
			n = i;
			break;
		}
	}
	switch (n)
	{
		case 0:
		{
			debug();
			std::cout << std::endl;
			info();
			std::cout << std::endl;
			warning();
			std::cout << std::endl;
			error();
			std::cout << std::endl;
			break;
		}
		case 1:
		{
			info();
			std::cout << std::endl;
			warning();
			std::cout << std::endl;
			error();
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			warning();
			std::cout << std::endl;
			error();
			std::cout << std::endl;
			break;
		}
		case 3:
		{
			error();
			std::cout << std::endl;
			break;
		}
		default:
		{
			std::cout << RED << "[ Unknown Level ]\nWhat the hell is this?!" << std::endl;
			break;
		}
	}
}