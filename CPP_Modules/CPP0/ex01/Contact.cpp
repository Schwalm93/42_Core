/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 05:01:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/09 10:27:35 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_var(std::string *var, std::string prompt)
{
	while (*var == "")
	{
		std::cout << prompt << ": ";
		getline(std::cin, *var);
		if (*var == "")
			std::cout << RED << "Empty Input!" << RESET << std::endl << std::endl;
	}	
}

void	Contact::set_phonebook_entry()
{
	set_var(&name, "First Name");
	set_var(&last_name, "Last Name");
	set_var(&nickname, "Nickname");
	set_var(&phone_number, "Phone");
	set_var(&darkes_secret, "Darkest Secret");
}

void	Contact::format_display(std::string var)
{
	if (var.length() > 10)
	{
		std::cout << var.substr(0, 9) << "." << "|";
	}
	else
		std::cout << std::setw(10) << var << "|";
}

void	Contact::display()
{
	format_display(name);
	format_display(last_name);
	format_display(nickname);
	std::cout << std::endl;
}

void	Contact::details()
{
	std::cout << MAGENTA;
	std::cout << "First Name:	" << name << std::endl;
	std::cout << "Last Name:	" << last_name << std::endl;
	std::cout << "Nickname:	" << nickname << std::endl; 
	std::cout << "Phonenumber:	" << phone_number << std::endl; 
	std::cout << "Darkessecret:	" << darkes_secret << std::endl << std::endl;  
	std::cout << RESET;
}

void	Contact::clear_all()
{
	name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkes_secret = "";
}
