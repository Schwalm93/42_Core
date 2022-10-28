/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:34:49 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/23 04:43:48 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	std::list<int> list;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	try
	{
		easyfind(vec, 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	list.push_back(10);
	list.push_back(20);
	try
	{
		easyfind(list, 22);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return(0);
}