/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:17:06 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:22:45 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(/* args */)
{
	for (size_t i = 0; i < n_ideas; i++)
	{
		this->ideas[i] = "Default Idea";
	}
	std::cout << "Brain default Constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called!" << std::endl;
}
	
Brain::Brain(Brain const &copy)
{
	for (size_t i = 0; i < n_ideas; i++)
	{
		this->ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain Copy-Constructor called!" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	for (size_t i = 0; i < n_ideas; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain Assignment-Constructor called!" << std::endl;
	return (*this);
}

std::string *Brain::getIdeas()
{
	return(this->ideas);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index <= n_ideas)
	{
		this->ideas[index] = idea;
	}
	else
		std::cout << "index is out of range!" << std::endl;
}