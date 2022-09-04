/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:24:05 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/04 05:02:41 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float sign(Point point, Point corner1, Point corner2)
{
	float test;
	test = (point.get_x() - corner2.get_x()) * (corner1.get_y() - corner2.get_y()) \
	- (corner1.get_x() - corner2.get_x()) * (point.get_y() - corner2.get_y());
	std::cout << (point.get_x() - corner2.get_x()) << "  *  " << (corner1.get_y() - corner2.get_y()) \
	<< "  -  " << (corner1.get_x() - corner2.get_x()) << "  *  " << (point.get_y() - corner2.get_y()) << "  =  " << test << std::endl;
	return((point.get_x() - corner2.get_x()) * (corner1.get_y() - corner2.get_y()) \
	- (corner1.get_x() - corner2.get_x()) * (point.get_y() - corner2.get_y()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

	return !(has_neg && has_pos);
}