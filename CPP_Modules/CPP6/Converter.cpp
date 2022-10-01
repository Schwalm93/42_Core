/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:59:41 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/01 05:32:04 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


Converter::Converter(/* args */)
{
	this->_char = ' ';
	this->_double = 0;
	this->_float = 0;
	this->_int = 0;
}

Converter::~Converter()
{
}

