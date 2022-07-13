/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:33:44 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/09 10:48:39 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define MAGENTA "\x1b[35m"
#define RESET	"\x1b[0m"

class PhoneBook
{
private:
	Contact member[8];
	int		oldest;
	int		entrys;

public:

	void	init();
	void	add();
	void	search();
	void	exit();
};

#endif