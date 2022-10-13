/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:42:25 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/13 05:06:41 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
class Array
{
private:
	
	unsigned int 	_size;
	T 				*_array;
public:
	Array(void);
	Array(unsigned int elements);
	Array(Array const &copy);
	Array &operator=(Array const &copy);
	T &operator[](unsigned int);
	~Array(void);
	unsigned int size();

	class IndexOutOfBound : public std::exception
	{
		virtual const char* what() const throw();
	};

};

template<typename T>
Array<T>::Array()
{
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int elements)
{
	_array = new T[elements];
	_size = elements;
	for (size_t i = 0; i < elements; i++)
		_array[i] = 0;
}

template<typename T>
Array<T>::Array(Array const &copy)
{
	this->_size = 0;
	*this = copy;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &copy)
{
	if (this == &copy)
		return(*this);
	if (this->_size > 0)
		delete [] this->_array;
	this->_size = copy._size;
	this->_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBound();
	return(this->_array[index]);
}

template<typename T>
Array<T>::~Array()
{
	if (this->_size > 0)
		delete [] this->_array;
}

template<typename T>
unsigned int Array<T>::size()
{
	return(this->_size);
}

template<typename T>
const char* Array<T>::IndexOutOfBound::what() const throw()
{
	return ("Index out of Bound!");
}