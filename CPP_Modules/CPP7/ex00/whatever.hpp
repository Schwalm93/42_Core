/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:38:55 by cschwalm          #+#    #+#             */
/*   Updated: 2022/10/09 06:14:05 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void swap(T &x, T &y)
{
	T tmp = x;

	x = y;
	y = tmp;
}

template<typename T>
T const &min(T const &x, T const &y)
{
	if (x < y)
		return(x);
	else
		return(y);
}

template<typename T>
T const &max(T const &x, T const &y)
{
	if (x > y)
		return(x);
	else
		return(y);
}