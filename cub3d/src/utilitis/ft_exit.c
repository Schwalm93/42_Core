/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:56:23 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:56:25 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* Prints Error_String in red with a newline + exit(1) */
void	printe(char *error_str)
{
	printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, error_str);
}

/*free all memory in the structs*/
void	free_structs(t_data *data)
{
	if (data->map_attr->map_char)
		ft_free_arry((void *) &data->map_attr->map_char);
	if (data->map_attr->map)
		ft_free_arry((void *) &data->map_attr->map);
	if (data->map_attr->n_texture)
		ft_free_str((void *) &data->map_attr->n_texture);
	if (data->map_attr->s_texture)
		ft_free_str((void *) &data->map_attr->s_texture);
	if (data->map_attr->w_texture)
		ft_free_str((void *) &data->map_attr->w_texture);
	if (data->map_attr->e_texture)
		ft_free_str((void *) &data->map_attr->e_texture);
}

/*destroy all open pictures and/or windows*/
void	destroy_all(t_data *data)
{
	ft_desetroy_north_south(data);
	ft_desetroy_west_east(data);
	if (data->mlx_attr->mlx_win != NULL)
	{
		mlx_destroy_window(data->mlx_attr->mlx, data->mlx_attr->mlx_win);
		data->mlx_attr->mlx_win = NULL;
	}
}

static char	*ft_strjoin_exit(char *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = ft_calloc ((len_1 + len_2 + 1), sizeof(char));
	if (s3 == 0)
		return (0);
	ft_strlcat(s3, s1, len_1 + 1);
	ft_strlcat(s3, s2, len_1 + len_2 + 1);
	return (s3);
}

/*exiting the game but before clean memory and/or display error_msg*/
void	ft_exit(t_data *data, int error, char *error_msg)
{
	char	*err_str;
	char	*temp;

	if (errno != 0)
		err_str = strerror(errno);
	err_str = NULL;
	destroy_all(data);
	free_structs(data);
	if (error == 1)
	{
		if (err_str != NULL)
		{
			temp = ft_strjoin_exit(error_msg, err_str);
			printe(temp);
			free(temp);
		}
		else
			printe(error_msg);
		exit(-1);
	}
	exit(0);
}
