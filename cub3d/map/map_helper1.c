/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:32 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:51:37 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*checks if the color range is within the RGB range*/
void	check_color_range(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->map_attr->rgb_ceiling[i] > 255
			|| data->map_attr->rgb_ceiling[i] < 0)
			ft_exit(data, 1, "Error - RGB colors have wrong format");
		if (data->map_attr->rgb_floor[i] > 255
			|| data->map_attr->rgb_floor[i] < 0)
			ft_exit(data, 1, "Error - RGB colors have wrong format");
		i++;
	}
}

/*helper function to get below 25 lines while converting char to int array*/
static void	char_to_int_helper(t_data *data, int j, int i)
{
	if (data->map_attr->map_char[j][i] == ' ')
		data->map_attr->map[j][i] = 32;
	else if (data->map_attr->map_char[j][i] >= 48
		&& data->map_attr->map_char[j][i] <= 57)
		data->map_attr->map[j][i] = data->map_attr->map_char[j][i] - 48;
	else
		data->map_attr->map[j][i] = data->map_attr->map_char[j][i];
}

/*converting char to int array*/
void	char_to_int(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	data->map_attr->map
		= ft_calloc(data->map_attr->map_height + 1, sizeof(int *));
	if (!data->map_attr->map)
		ft_exit(data, 1, "Error - can not allocate for 2D map!");
	while (data->map_attr->map_char[++j])
	{
		i = -1;
		data->map_attr->map[j]
			= ft_calloc(data->map_attr->map_width + 1, sizeof(int));
		if (!data->map_attr->map[j])
			ft_exit(data, 1, "Error - can not allocate for 2D map!");
		while (data->map_attr->map_char[j][++i])
			char_to_int_helper(data, j, i);
	}
}

/*checking if there is a line with only spaces among the
first six lines in the map file*/
int	checkspace(const char *str, int i)
{
	int	j;

	j = i;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (i);
	return (j);
}

/*checking if the RGB colors have the right format (lenght and 2 ',')*/
int	check_color(char *string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	if (i < 6)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (0);
	return (1);
}
