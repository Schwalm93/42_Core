/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/28 06:24:36 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FIXED_HPP)
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int					_fixedValue;
	static const int	_fractBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};


#endif


