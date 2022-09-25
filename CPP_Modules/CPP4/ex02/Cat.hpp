/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:50 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:48:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CAT_HPP)
#define CAT_HPP

#include "AAnimal.hpp"
#include <iostream>

class Cat : public AAnimal
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



