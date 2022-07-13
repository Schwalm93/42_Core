/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:30:59 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/09 10:33:12 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::init()
{
	this->oldest = 0;
	this->entrys = 0;
}

void	PhoneBook::add()
{
	this->member[oldest].clear_all();
	this->member[oldest].set_phonebook_entry();
	oldest++;
	if (oldest == 8)
		oldest = 0;
	if (entrys != 8)
		entrys++;
}

void	PhoneBook::search()
{
	if (this->entrys != 0)
	{
		std::string input;
		int index;
		std::cout << std::endl << MAGENTA << "Index|First Name| Last Name|  Nickname| " << std::endl;
		for (size_t i = 0; i < this->entrys; i++)
		{
			std::cout << std::setw(5) << i << "|";
			this->member[i].display();
		}
		std::cout << RESET << std::endl;
		std::cout << YELLOW << "Which member should be Displayed? - Use the Index Number" << RESET << std::endl;
		getline(std::cin, input);
		index = input[0] - 48;
		if (index < 0 || index >= this->entrys || input.length() > 1)
			std::cout << RED << "Index not found!" << std::endl;
		else
			this->member[index].details();
	}
	else
		std::cout << RED << "The Phonebook is Empty!" << std::endl << std::endl;

}

void	PhoneBook::exit()
{
	for (size_t i = 0; i < 8; i++)
	{
		this->member[i].clear_all();
	}
}