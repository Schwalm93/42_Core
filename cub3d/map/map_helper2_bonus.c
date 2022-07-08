/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:45 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:51:51 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

/*trims away spaces in the color and texture values/paths*/
char	*color_texture_trim(char *string)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	while (string[i])
	{
		if (string[i] != ' ')
			temp[j++] = string[i++];
		else if (j > 2 && (string[0] == 'N' || string[0] == 'S'
				|| string[0] == 'W' || string[0] == 'E'))
			temp[j++] = string[i++];
		else
			i++;
	}
	temp[j] = '\0';
	return (temp);
}

/*helper function for get_color to check RGB values*/
int	get_color_helper(char *str, char c)
{
	int	i;

	i = 0;
	while (i < 3 && str[i])
	{
		if ((c == 'F' && !ft_isdigit((int)str[i])) || ft_strlen(str) > 3)
			return (0);
		if ((c == 'C' && !ft_isdigit((int)str[i])) || ft_strlen(str) > 3)
			return (0);
		i++;
	}
	return (1);
}

/*saves the RGB valus in the struct*/
void	get_color_save(t_data *data, char c, char *str, int j)
{
	if (c == 'F')
		data->map_attr->rgb_floor[j] = ft_atoi(str);
	if (c == 'C')
		data->map_attr->rgb_ceiling[j] = ft_atoi(str);
}

/*helper function to get custom ft_split below 25 lines*/
int	ft_split_helper1(const char *s, int i, char c, unsigned int *pos_1)
{
	while (s[i] == c && s[i] != '\0')
	{
		i++;
		if (s[i] == ' ')
			i = checkspace(s, i);
	}
	*pos_1 = i;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		if (s[i] == ' ')
			i = checkspace(s, i);
	}
	return (i);
}

void	end_store_map(char *map_str, char **temp, t_data *data)
{
	free(map_str);
	ft_free_arry((void *) &temp);
	ft_exit(data, 1, "Error - Map data wrong format, please try again");
}
