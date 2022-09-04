/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/01 12:38:45 by cschwalm         ###   ########.fr       */
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


		bool operator>( Fixed const &other) const;
		bool operator<( Fixed const &other) const;
		bool operator>=( Fixed const &other) const;
		bool operator<=( Fixed const &other) const;
		bool operator==( Fixed const &other) const;
		bool operator!=( Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		~Fixed();
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const &min(Fixed const &a, Fixed  const &b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const &max(Fixed const &a, Fixed  const &b);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif


