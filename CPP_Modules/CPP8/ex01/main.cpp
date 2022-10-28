/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:42:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/26 10:55:06 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span a(3);

	a.addNumber(1);
	a.addNumber(50);
	a.addNumber(4);

	std::vector<int> vec(4);

	Span b(5);
	b.addNumber(vec.begin(), vec.end());
	std::cout << a.longestSpan() << std::endl;
	std::cout << a.shortestSpan() << std::endl;
	return(0);
}