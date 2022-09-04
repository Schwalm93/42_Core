/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/01 00:28:49 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FIXED_HPP)
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int					_fixedValue;
	static const int	_fractBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(int const convert);
		Fixed(float const convert);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif


