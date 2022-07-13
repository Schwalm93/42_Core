/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:47:49 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/09 10:35:24 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	std::string command;
	PhoneBook book;

	book.init();
	while (1)
	{
		std::cout << YELLOW << "ADD | SEARCH | EXIT - Choose one of the Keywords" << RESET << std::endl;
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			book.add();
			std::cout << GREEN << "New Entry Completed!" << RESET << std::endl << std::endl;
		}
		else if (command.compare("SEARCH") == 0)
			book.search();
		else if (command.compare("EXIT") == 0)
		{
			book.exit();
			std::cout << GREEN << "All Contacts Destroyed - Phonebook Closed" << RESET << std::endl << std::endl;
			return(0);
		}
		else
			std::cout << RED << "Keyword does not exist" << RESET << std::endl << std::endl;
	}
	return (0);
}
