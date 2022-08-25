/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 06:56:52 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/25 04:05:14 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    if (argc != 2)
    {
        std::cout << RED << "Error! Wrong Input! Try DEBUG, INFO, WARNING or ERROR" << RESET << std::endl;
        return (1);
    }
    harl.complain(argv[1]);
    return (0);
}
