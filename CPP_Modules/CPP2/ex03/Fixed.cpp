/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/01 12:40:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************Constructor****************/
Fixed::Fixed()
{
	//std::cout << "Default constructor called\n";
	this->_fixedValue = 0;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &firstclass )
{
	//std::cout << "Copy constructor called\n";
	this->_fixedValue = firstclass._fixedValue;
}

Fixed::Fixed(int const convert)
{
	//std::cout << "Int constructor called\n";
	this->_fixedValue = convert << this->_fractBits;
}

Fixed::Fixed(float const convert)
{
	//std::cout << "float constructor called\n";
	this->_fixedValue = roundf(convert * (1 << this->_fractBits));
}




/*************Operator Overloads**********/

Fixed	&Fixed::operator=( Fixed const &fixed )
{
	std::cout << "****Copy assignment operator called\n";
	if (this != &fixed)
	{
		this->_fixedValue = fixed.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(Fixed const &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(Fixed const &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	Fixed::operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	Fixed::operator--();
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	return (out << value.toFloat());
}



/*************Member Functions************/

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed  const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed  const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}

int Fixed::toInt(void) const
{
	return (this->_fixedValue >> this->_fractBits);
}

float Fixed::toFloat(void) const
{
	return ((float) this->_fixedValue / (1 << this->_fractBits));
}
