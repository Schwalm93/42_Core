/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:19 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:51:22 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

/*the function that calls all functions neccessary to read the map*/
void	get_map(t_data *data, char *filepath)
{
	read_map_file(data, filepath);
	check_color_range(data);
	char_to_int(data);
	check_map(data);
	ft_free_arry((void *) &data->map_attr->map_char);
}

/* reads the map file and stores it in a string */
int	read_map_file(t_data *data, char *filepath)
{
	char	*map_str;
	char	*temp;
	int		i;
	int		fd;

	map_str = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_exit(data, 1, "Error - Failed to read map");
	i = 1;
	while (i != 0)
	{
		temp = get_next_line(fd);
		if (temp)
			map_str = ft_strjoin(map_str, temp);
		else
			i--;
		ft_free_str((void *) &temp);
	}
	store_map(data, map_str, 6, 0);
	ft_free_str((void *) &map_str);
	return (1);
}

/* reads the map string and stores the data in the data struct */
void	store_map(t_data *data, char *map_str, int i, int j)
{
	char	**temp;
	int		z;

	if (!map_str)
		return ;
	temp = ft_split_map(data, map_str, '\n', 0);
	if (get_color_texture(data, temp) == -1)
		end_store_map(map_str, temp, data);
	while (temp[i])
	{
		z = 1;
		j = ft_strlen(temp[i]);
		while (z <= j)
		{
			if (temp[i][j - z] == ' ')
				temp[i][j - z] = '\0';
			else
				break ;
			z++;
		}
		i++;
	}
	get_map_dimensions(data, temp);
	store_map_array(data, temp, 5, -1);
	ft_free_arry((void *) &temp);
}

/* stores the map in the structs **map array */
void	store_map_array(t_data *data, char **map_file, int j, int z)
{
	int	i;

	data->map_attr->map_char
		= ft_calloc(data->map_attr->map_height + 1, sizeof(char *));
	if (!data->map_attr->map_char)
	{
		ft_free_arry((void *) &map_file);
		ft_exit(data, 1, "Error - Map allocation failed!");
	}
	while (map_file[++j] && j < data->map_attr->map_height + 6)
	{
		data->map_attr->map_char[++z]
			= ft_calloc(data->map_attr->map_width + 1, sizeof(char));
		i = -1;
		while (map_file[j][++i])
			data->map_attr->map_char[z][i] = map_file[j][i];
		if ((map_file[j][i]) == '\0' && i < data->map_attr->map_width)
		{
			while (i < data->map_attr->map_width)
				data->map_attr->map_char[z][i++] = ' ';
		}
	}
}

/* gets the height and width of the map and stores it in the struct */
void	get_map_dimensions(t_data *data, char **map_file)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 6;
	while (map_file[z])
	{
		while (map_file[z][i])
		{
			i++;
			if (i > j)
				j = i;
		}
		i = 0;
		z++;
	}
	data->map_attr->map_width = j;
	while (map_file[z] == NULL)
		z--;
	data->map_attr->map_height = (z - 5);
}
