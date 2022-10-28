/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:35:38 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/23 04:43:37 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T &con, int find)
{
	typename T::iterator it = std::find(con.begin(), con.end(), find);
	if (it == con.end())
		throw std::invalid_argument("Easyfinde: The Cotainer does not contain the searched Element!");
	else 
		std::cout << "The Element got found!" << std::endl; 
}