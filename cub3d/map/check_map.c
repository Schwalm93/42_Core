/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:12 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:51:15 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_characters(t_data *data, int *startposition, int y, int x)
{
	if (data->map_attr->map[y][x] == 78 || data->map_attr->map[y][x] == 83
		|| data->map_attr->map[y][x] == 87 || data->map_attr->map[y][x] == 69)
	{
		data->player->x = (float) x + 0.5;
		data->player->y = (float) y + 0.5;
		data->map_attr->player_dir = data->map_attr->map[y][x];
		(*startposition)++;
	}
	else if (data->map_attr->map[y][x] != 32 && data->map_attr->map[y][x] != 10
		&& data->map_attr->map[y][x] != 0 && data->map_attr->map[y][x] != 1)
		return (-1);
	return (1);
}

/*check if only allowed characters in the map			*/
/*1 --> wall, 0 --> floor, 32 --> space, 10 --> new line*/
/*78 --> north orientation, 83 --> south orientation	*/
/*87 --> west orientation, 69 --> east orientation		*/
int	check_map_characters(t_data *data)
{
	int	x;
	int	y;
	int	startposition;

	x = -1;
	y = -1;
	startposition = 0;
	while (++y < data->map_attr->map_height)
	{
		while (++x < data->map_attr->map_width)
			if (check_characters(data, &startposition, y, x) == -1)
				return (-1);
		x = -1;
	}
	if (startposition == 0)
		return (-2);
	if (startposition != 1)
		return (-1);
	return (0);
}

/*check the first and the last coloum/row there are no floor or player allowed*/
int	check_map_walls_around(t_data *data)
{
	int	iter;
	int	**map;

	iter = -1;
	map = data->map_attr->map;
	while (++iter < data->map_attr->map_width)
	{
		if (map[0][iter] != 1 && map[0][iter] != 32 && map[0][iter] != 10)
			return (-1);
		if (map[data->map_attr->map_height - 1][iter] != 1
			&& map[data->map_attr->map_height - 1][iter] != 32
			&& map[data->map_attr->map_height - 1][iter] != 10)
			return (-1);
	}
	iter = -1;
	while (++iter < data->map_attr->map_height)
	{
		if (map[iter][0] != 1 && map[iter][0] != 32 && map[iter][0] != 10)
			return (-1);
		if (map[iter][data->map_attr->map_width - 1] != 1
			&& map[iter][data->map_attr->map_width - 1] != 32
			&& map[iter][data->map_attr->map_width - 1] != 10)
			return (-1);
	}
	return (1);
}

/*check the map, the floor is not allowed to hav any contact with whitespaces*/
int	check_map_walls(t_data *data)
{
	int	x;
	int	y;
	int	**map;

	x = 0;
	y = 0;
	map = data->map_attr->map;
	while (++y < data->map_attr->map_height - 1)
	{
		while (++x < data->map_attr->map_width - 1)
		{
			if (map[y][x] == 0 && (map[y][x + 1] == 32
				|| map[y][x - 1] == 32 || map[y + 1][x] == 32
				|| map[y - 1][x] == 32 || map[y][x + 1] == 10
				|| map[y][x - 1] == 10 || map[y + 1][x] == 10
				|| map[y - 1][x] == 10))
				return (-1);
		}
		x = -1;
	}
	return (1);
}

/*check map main function. calls all check function*/
int	check_map(t_data *data)
{
	int	ret;

	ret = check_map_characters(data);
	if (ret == -2)
		ft_exit(data, 1, "Error - no player startposition");
	if (ret == -1)
		ft_exit(data, 1, "Error - not allowed characters in the map");
	if (check_map_walls_around(data) == -1)
		ft_exit(data, 1, "Error - map is not closed at the borders");
	if (check_map_walls(data) == -1)
		ft_exit(data, 1, "Error - map is not closed");
	return (1);
}
