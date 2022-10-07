/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:59:20 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/07 04:25:14 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(BASE_HPP)
#define BASE_HPP

class Base
{

public:
	virtual ~Base(void) {}
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};


#endif // BASE_HPP
