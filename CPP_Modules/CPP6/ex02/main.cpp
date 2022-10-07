/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:53:54 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/07 07:01:35 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Class A identified" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Class B identified" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Class C identified" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Class A identified" << std::endl;
		(void) a;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Class B identified" << std::endl;
		(void) b;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Class C identified" << std::endl;
		(void) c;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}

}


Base *generate(void)
{
	Base *base;
	int rnd = rand() % 3;

	switch (rnd)
	{
	case 0:
		base = new A;
		break;
	case 1:
		base = new B;
		break;
	default:
		base = new C;
		break;
	}
	return (base);
}

int main()
{
	Base *base;

	base = generate();
	// Base &base2  = *base;

	identify(base);
	identify(*base);
	delete base;

	return(0);
}