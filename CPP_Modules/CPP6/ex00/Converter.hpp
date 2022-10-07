/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:58:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/07 07:04:27 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CONVERTER_HPP)
#define CONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>

#define TYPE_UNDEF		-1
#define TYPE_CHAR		0
#define TYPE_INT		1
#define TYPE_FLOAT		2
#define TYPE_DOUBLE		3
#define TYPE_SPECIAL	4

class Converter
{
private:
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	bool		_isPrintable;
	bool		_isSpecial;
	int			_type;

public:
	Converter();
	Converter(Converter const &);
	Converter &operator=(Converter const &);
	~Converter();

	void	convert(std::string const &);
	bool	isInt(std::string const &);
	bool	isFloat(std::string const &);
	bool	isDouble(std::string const &);
	bool	isSpecial(std::string const &);
	int		getType(std::string const &);
	bool	getIsPrintble() const;
	bool	getIsSpecial() const;
	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;
	std::string input;
};

std::ostream &operator<<(std::ostream &out, Converter const &value);
#endif 

