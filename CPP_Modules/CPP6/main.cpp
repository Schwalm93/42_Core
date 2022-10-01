/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:53:54 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/01 05:33:38 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of parameters!" << std::endl;
		return(0);
	}

	Converter converter;
	
	std::cout << "char: " << converter.getChar() << std::endl;
	std::cout << "int: " << converter.getInt() << std::endl;
	std::cout << "float: " << converter.getFloat() << std::endl;
	std::cout << "double: " << converter.getDouble() << std::endl;

	(void)argv;
}