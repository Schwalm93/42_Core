/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:50 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:42:40 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CAT_HPP)
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(Cat const &copy);
	Cat const &operator=(Cat const &rhs);
	~Cat();
	void makeSound() const;
	std::string *getIdeas();
	void setIdea(int, std::string);
};

#endif // MACRO



