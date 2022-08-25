/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 06:57:21 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/08 06:57:40 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    HARL_HPP
#define    HARL_HPP

#include <iostream>
#include <string>

# define RED        "\x1b[31m"
# define GREEN        "\x1b[32m"
# define YELLOW        "\x1b[33m"
# define BLUE        "\x1b[34m"
# define MAGENTA    "\x1b[35m"
# define CYAN        "\x1b[36m"
# define RESET        "\x1b[0m"

class Harl
{
	private:

		void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);

	public:
		void    complain(std::string level);
};

#endif