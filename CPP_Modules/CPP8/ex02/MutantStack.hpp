/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:57:24 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/28 02:48:06 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MUTANTSTACK_HPP)
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack() {};
	MutantStack(MutantStack const & copy) { *this = copy;};
	MutantStack & operator=(MutantStack const & copy)
	{
		std::stack<T>::operator=(copy);
		return (*this);
	}
	virtual ~MutantStack(void) {};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	iterator begin(void) { return(std::stack<T>::c.begin()); }
	iterator end(void) { return(std::stack<T>::c.end()); }
	reverse_iterator rbegin(void) { return(std::stack<T>::c.rbegin()); }
	reverse_iterator rend(void) { return(std::stack<T>::c.rend()); }
};

#endif
