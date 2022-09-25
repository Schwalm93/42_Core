/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:10:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:31:21 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *animals[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Cat();
		}
		else
			animals[i] = new Dog();
	}

	for (size_t i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	Cat cat1;

	std::string *ideas;
	
	ideas = cat1.getIdeas();

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << ideas[i] << std::endl;
	}
	Cat cat2 = cat1;

	cat2.setIdea(0, "Test");

	ideas = cat1.getIdeas();

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << ideas[i] << std::endl;
	}

	ideas = cat2.getIdeas();

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << ideas[i] << std::endl;
	}

	return 0;
}