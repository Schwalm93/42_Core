/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:08:06 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/12 02:38:31 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_isdigit(int c);
int		ft_putnbr(int n);
int		ft_uputnbr(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(const char *str);
int		ft_print_percent(int *i);
int		ft_print_pointer(unsigned long n);
int		ft_print_pointer_l(unsigned int n);
int		ft_print_pointer_u(unsigned int n);

#endif
