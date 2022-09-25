/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:17:10 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:26:41 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define n_ideas 100

class Brain
{
private:
	std::string ideas[n_ideas];
public:
	Brain();
	Brain(Brain const &copy);
	Brain &operator=(Brain const &rhs);
	~Brain();
	std::string *getIdeas();
	void setIdea(int, std::string);
};

