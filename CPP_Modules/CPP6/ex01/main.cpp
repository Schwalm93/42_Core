/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:53:54 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/07 01:36:45 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main()
{
	Data *data = new Data;
	uintptr_t conv;

	data->i = 1;
	data->c = 'c';
	data->s = "String";

	std::cout << "i = " << data->i << std::endl;
	std::cout << "c = " << data->c << std::endl;
	std::cout << "s = " << data->s << std::endl;

	conv = serialize(data);
	data = deserialize(conv);

	std::cout << "i = " << data->i << std::endl;
	std::cout << "c = " << data->c << std::endl;
	std::cout << "s = " << data->s << std::endl;

	delete data;
	return(0);
}