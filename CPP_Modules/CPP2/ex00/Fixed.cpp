/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/28 06:17:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}

Fixed::Fixed()
{
	std::cout << "**Default constructor called\n";
	this->_fixedValue = 0;
}
Fixed::Fixed( Fixed const &firstclass )
{
	std::cout << "***Copy constructor called\n";
	*this = firstclass;
}

Fixed& Fixed::operator=( Fixed const &fixed )
{
	std::cout << "****Copy assignment operator called\n";
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "*Destructor called" << std::endl;
}