/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:59:41 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/03 03:48:19 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


Converter::Converter()
{
	this->_char = ' ';
	this->_double = 0;
	this->_float = 0;
	this->_int = 0;
	this->_type = -1;
	this->_isPrintable = true;
	this->_isSpecial = false;
}

Converter::Converter(Converter const &copy)
{
	*this = copy;
}

Converter &Converter::operator=(Converter const &copy)
{
	this->_char			= copy._char;
	this->_int			= copy._int;
	this->_float		= copy._float;
	this->_double		= copy._double;
	this->_type			= copy._type;
	this->_isPrintable	= copy._isPrintable;
	this->_isSpecial	= copy._isSpecial;
	return(*this);
}

Converter::~Converter()
{
}

bool	Converter::getIsPrintble() const
{
	return(this->_isPrintable);
}

bool	Converter::getIsSpecial() const
{
	return(this->_isSpecial);
}

char	Converter::getChar() const
{
	return(this->_char);
}
int		Converter::getInt() const
{
	return(this->_int);
}
float	Converter::getFloat() const
{
	return(this->_float);
}
double	Converter::getDouble() const
{
	return(this->_double);
}

void	Converter::convert(std::string const &input)
{
	this->_type = getType(input);

	this->input = input;
	if (_type != -1)
	{
		this->_float	= atof(input.c_str());
		this->_int		= atoi(input.c_str());
		this->_double 	= atof(input.c_str());
	}
	switch (this->_type)
	{
	case TYPE_CHAR:
		std::cout << "Type is Char" << std::endl;
		this->_char		= input[0];
		this->_int		= static_cast<int>(input[0]);
		this->_float	= static_cast<float>(input[0]);
		this->_double	= static_cast<double>(input[0]);
		break;
	case TYPE_INT:
		std::cout << "Type is Int" << std::endl;
		this->_char		= static_cast<char>(_int);
		this->_float	= static_cast<float>(_int);
		this->_double	= static_cast<double>(_int);
		break;
	case TYPE_FLOAT:
		std::cout << "Type is Float" << std::endl;
		this->_char		= static_cast<char>(_float);
		this->_int		= static_cast<int>(_float);
		this->_double	= static_cast<double>(_float);
		break;
	case TYPE_DOUBLE:
		std::cout << "Type is Double" << std::endl;
		this->_char		= static_cast<char>(_double);
		this->_int		= static_cast<int>(_double);
		this->_float	= static_cast<float>(_double);
		break;
	case TYPE_SPECIAL:
		std::cout << "Type is Special" << std::endl;
		this->_isSpecial = true;
		break;
	default:
		std::cout << "Wrong Type" << std::endl;
		this->_isPrintable = false;
		break;
	}
}

int	Converter::getType(std::string const &input)
{
	if (isprint(input[0]) && !isdigit(input[0]) && input.length() == 1)
		return(TYPE_CHAR);
	else if (this->isInt(input))
		return(TYPE_INT);
	else if (this->isFloat(input))
		return(TYPE_FLOAT);
	else if (this->isDouble(input))
		return(TYPE_DOUBLE);
	else if (this->isSpecial(input))
		return(TYPE_SPECIAL);
	return(-1);
}

bool	Converter::isInt(std::string const &input)
{
	std::stringstream ss;
	double d;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && !(input[i] == '-' && i == 0))
			return(false);
	}
	ss << input;
	ss >> d;
	if (d > 2147483647 || d < -2147483648)
		return(false);
	return(true);
}

bool	Converter::isFloat(std::string const &input)
{
	int j = 0;
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] != '.' && !(input[i] == 'f' && i == (input.length() -1)))
			{
				return(false);
			}
			else if (input[i] == '.')
				j++;
		}
		if (j > 1)
			return(false);
	}
	if (input[input.length() - 1] == 'f')
		return(true);
	else
		return(false);
}

bool	Converter::isDouble(std::string const &input)
{
	int j = 0;
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] != '.')
			{
				return(false);
			}
			else if (input[i] == '.')
				j++;
		}
		if (j > 1)
			return(false);
	}
	return(true);
}

bool	Converter::isSpecial(std::string const &input)
{
	std::string comp[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};
	for (size_t i = 0; i < 6; i++)
	{
		if (!input.compare(comp[i]))
			return(true);
	}
	return(false);
}

std::ostream &operator<<(std::ostream &out, Converter const &value)
{
	if (value.getIsPrintble())
	{
		if (value.getIsSpecial())
			out << "Char:	Impossible"	<< std::endl;
		else if (isprint(value.getChar()))
			out << "Char:	'"	<< value.getChar()		<< "'" << std::endl;
		else
			out << "Char:	Non displayable" << std::endl;
		if (value.getIsSpecial())
			out << "Int:	Impossible"	<< std::endl;
		else
			out << "Int:	"	<< value.getInt()		<< std::endl;
		out << "Float:	"	<< value.getFloat()		<< "f" << std::endl;
		out << "Double:	"	<< value.getDouble()	<< std::endl;
	}
	else
		out << "Worng input Type!" << std::endl;

	return (out);
}