/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:45:25 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:45:27 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*fillstring(int fd, char *string1);
size_t	ft_strlengnl(char *str);
char	*ft_strchrgnl(char *str, int c);
char	*ft_strjoingnl(char *string1, char *string2);
char	*output(char *string1);
char	*new_string(char *string1);

#endif
