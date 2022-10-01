/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:58:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/01 05:32:59 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CONVERTER_HPP)
#define CONVERTER_HPP

#include <iostream>

class Converter
{
private:
	char	_char;
	int		_int;
	float	_float;
	double	_double;
public:
	Converter(/* args */);
	Converter(Converter const &);
	Converter &operator=(Converter const &);
	~Converter();

	char	getChar();
	int		getInt();
	float	getFloat();
	double	getDouble();
};


#endif // CONVERTER_HPP

