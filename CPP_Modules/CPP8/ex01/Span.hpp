/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:43:42 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/24 14:05:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	std::vector<int>	_vector;
	unsigned int 		_size;
	unsigned int		_index;
	bool				_allocation;
	Span(); //! Calling without params is not possible //
public:
	Span(unsigned int);
	Span(Span const &);
	Span &operator=(Span const &);
	~Span();
	void addNumber(int number);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};
