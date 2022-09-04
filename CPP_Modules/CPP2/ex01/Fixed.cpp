/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/01 02:55:53 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_fixedValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &firstclass )
{
	std::cout << "Copy constructor called\n";
	this->_fixedValue = firstclass._fixedValue;
}

Fixed::Fixed(int const convert)
{
	std::cout << "Int constructor called\n";
	this->_fixedValue = convert << this->_fractBits;
}

Fixed::Fixed(float const convert)
{
	std::cout << "float constructor called\n";
	this->_fixedValue = roundf(convert * (1 << this->_fractBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedValue >> this->_fractBits);
}

float Fixed::toFloat(void) const
{
	return ((float) this->_fixedValue / (1 << this->_fractBits));
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

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	return (out << value.toFloat());
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}
