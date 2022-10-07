/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:53:54 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/03 03:42:54 by cschwalm         ###   ########.fr       */
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
	converter.convert(argv[1]);
	std::cout << converter << std::endl;

	Converter converter2;

	converter2 = converter;

	std::cout << converter2 << std::endl;
	return(0);
}