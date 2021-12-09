/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:16:09 by keshav            #+#    #+#             */
/*   Updated: 2021/12/05 22:16:16 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdbool.h>
# include <limits.h>

# define OPEN_MAX_F 6000

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
bool	checklinebreak(char const *buffer);
size_t	ft_strlen(const char *c);
void	concatenate(char **remainder, char *buffer);
void	read_and_concatenate(int *bytes, int fd, char **remainder);
char	*ft_strdup(const char *c);
void	*ft_memset(void *s, int c, size_t n);

#endif