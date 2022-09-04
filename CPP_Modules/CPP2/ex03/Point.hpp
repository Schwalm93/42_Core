/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:25:14 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/04 04:44:28 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(POINT_HPP)
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &copy);
	~Point(void);
	Point& operator=(Point const &assignment);

	float get_x(void) const;
	float get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif 
