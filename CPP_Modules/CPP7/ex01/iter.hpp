/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:51:06 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/09 10:38:46 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void iter(T *array, size_t len, void (*function)(T &element))
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
}

template<typename T>
void print(T &element)
{
	std::cout << "element = " << element << std::endl;
}