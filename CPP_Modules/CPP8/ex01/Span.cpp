/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:01:22 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/26 10:54:45 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N) : _size(N)
{
	_index = 0;
}
Span::Span(Span const &copy) : _size(0)
{
	*this = copy;
}

Span &Span::operator=(Span const &copy)
{
	this->_size = copy._size;
	this->_vector.clear();
	this->_vector = copy._vector;
	return(*this);
}
Span::~Span()
{
	this->_vector.clear();
}

void	Span::addNumber(int number)
{
	try
	{
		if (_index < _size)
		{
			_vector.push_back(number);
			_index++;
		}
		else
			throw std::out_of_range("Span: Maximum size reached!");
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator position = _vector.end();
	try
	{
		if (_vector.size() + std::distance(begin, end) > _size)
			throw std::out_of_range("Span: Maximum size reached!");
		else
			this->_vector.insert(position, begin, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

unsigned int Span::longestSpan()
{
	try
	{
		if (_vector.size() < 2)
			throw std::length_error("Span: Container has to less Elements");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	int max = *std::max_element(_vector.begin(), _vector.end());
	int min = *std::min_element(_vector.begin(), _vector.end());

	return (static_cast<unsigned int>(max - min));
}

unsigned int Span::shortestSpan()
{
	try
	{
		if (_vector.size() < 2)
			throw std::length_error("Span: Container has to less Elements");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::vector<int> vector_tmp = _vector;
	std::sort(vector_tmp.begin(), vector_tmp.end());

	int diff;
	if (_vector.size() > 1)
	{
		diff = (vector_tmp.at(1) - vector_tmp.at(0));
		for (size_t i = 1; i < _vector.size(); i++)
		{
			if ((vector_tmp.at(i) - vector_tmp.at(i - 1)) < diff)
				diff = vector_tmp.at(i) - vector_tmp.at(i - 1);
		}
	}
	else
		diff = 0;
	return (static_cast<unsigned int>(diff));
}