/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:37:31 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/09 10:08:26 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>

#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define MAGENTA "\x1b[35m"
#define RESET	"\x1b[0m"

class Contact
{
private:
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkes_secret;
public:
	void	set_phonebook_entry();
	void	clear_all();
	void	display();
	void	details();
private:
	void	format_display(std::string var);
	void	set_var(std::string *var, std::string prompt);
};

#endif