/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:13:44 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/26 03:44:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>


int	main(int argc, char **argv)
{
	if (argc > 1)
	{	
		for (int x = 1; x < argc; x++)
		{
			for (size_t i = 0; i < strlen(argv[x]); i++)
			{
				std::cout << (char) toupper(argv[x][i]);
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;
	}
	return (0);
}