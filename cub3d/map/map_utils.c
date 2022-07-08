/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:52:08 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:52:10 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* counts how many elements will be created by ft_split_map */
static	int	ft_counter(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter + 1);
}

/* a customized version of ft_split, deletes emty lines before the
map and leaves them in the map part */
char	**ft_split_map(t_data *data, const char *s, char c, int i)
{
	char			**str;
	unsigned int	pos_1;

	pos_1 = 0;
	str = ft_calloc(sizeof(char *), ft_counter(s, c));
	while (s[i] != '\0')
	{
		if (data->map_attr->count_j < 7)
		{
			i = ft_split_helper1(s, i, c, &pos_1);
			if (s[i - 1] != c)
				str[data->map_attr->count_str] = ft_substr(s, pos_1, i - pos_1);
			if (s[i - 1] != c)
				data->map_attr->count_j++;
		}
		else
		{
			pos_1 = ++i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[data->map_attr->count_str] = ft_substr(s, pos_1, i - pos_1);
		}
		data->map_attr->count_str++;
	}
	return (str);
}

/* preselection of the functions to store color and textures of the map */
int	get_color_texture(t_data *data, char **map_file)
{
	char	*temp;
	int		stat;

	data->map_attr->counter = -1;
	while (++data->map_attr->counter < 6)
	{
		temp = color_texture_trim(map_file[data->map_attr->counter]);
		stat = get_color_texture_helper(data, temp);
		if (stat == -1)
		{
			free(temp);
			return (-1);
		}
		free(temp);
	}
	return (1);
}

/* gets the path to the wall textures of the map and stores it in the struct */
int	get_texture(t_data *data, char *string, char c)
{
	if (c == 'N')
		data->map_attr->n_texture = ft_substr(string, 2, ft_strlen(string) - 2);
	if (c == 'S')
		data->map_attr->s_texture = ft_substr(string, 2, ft_strlen(string) - 2);
	if (c == 'W')
		data->map_attr->w_texture = ft_substr(string, 2, ft_strlen(string) - 2);
	if (c == 'E')
		data->map_attr->e_texture = ft_substr(string, 2, ft_strlen(string) - 2);
	return (1);
}

/* gets the colors of the ceiling and the floor of
the map and stores it in the struct */
int	get_color(t_data *data, char *string, char c)
{
	char	*temp1;
	char	**temp2;
	int		j;
	int		end;

	j = -1;
	end = 1;
	if (!check_color(string))
		return (-1);
	temp1 = ft_substr(string, 1, ft_strlen(string) - 1);
	temp2 = ft_split(temp1, ',');
	while (temp2[++j] && j < 3)
	{
		if (!get_color_helper(temp2[j], c))
		{
			end = 0;
			break ;
		}
		get_color_save(data, c, temp2[j], j);
	}
	ft_free_str((void *) &temp1);
	ft_free_arry((void *) &temp2);
	if (j < 3 || end == 0)
		return (-1);
	return (1);
}
