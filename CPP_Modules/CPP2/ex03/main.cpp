/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:25 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/04 05:00:42 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point corner_a(3, 6);
	Point corner_b(6, 3);
	Point corner_c(9, 6);
	Point point (6, 3);

	if (bsp(corner_a, corner_b, corner_c, point))
		std::cout << "Point is inside!" << std::endl;
	else
		std::cout << "Point is outside!" << std::endl;
	return 0;
}
