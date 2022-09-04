/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:25:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/04 04:45:13 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructor 
Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y)
{
}

Point &Point::operator=(Point const &assignment)
{
	(void) assignment;
	return (*this);
}

Point::~Point(void)
{
}

// functions

float Point::get_x(void) const
{
	return (this->_x.toFloat());
}

float Point::get_y(void) const
{
	return (this->_y.toFloat());
}