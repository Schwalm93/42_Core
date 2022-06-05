/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utilitis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:06:09 by tguth             #+#    #+#             */
/*   Updated: 2022/05/26 16:48:23 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	open_utilis(t_data *data, char *new_path, int option, char *temp);

void	ft_open(t_data *data, int option, char *path)
{
	int		index;
	char	*new_path;

	index = get_next_space(path, 0);
	new_path = ft_substr(path, 0, index);
	open_utilis(data, new_path, option, path);
}

static void	open_utilis(t_data *data, char *new_path, int option, char *temp)
{
	int		file_des;
	int		cmd_numb;

	file_des = -1;
	cmd_numb = data->cmd_numb;
	if (option == 1)
		file_des = open(new_path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (option == 2)
		file_des = open(new_path, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (option == 3)
		file_des = open (new_path, O_RDONLY);
	ft_free((void *) &new_path, NULL, NULL);
	if (file_des < 0)
		err_handler(data, 1, NULL, "Error bad file descripter");
	data->t_commands[cmd_numb]->command = temp;
	if (option < 3)
		data->t_commands[cmd_numb]->output_fd = file_des;
	else
		data->t_commands[cmd_numb]->input_fd = file_des;
}

void	ft_heredoc(t_data *data, char *in_arrow)
{
	int		fd;
	char	*line;
	char	*delim;
	int		start;

	start = 1;
	delim = ft_strdup(in_arrow + get_first_c(in_arrow));
	fd = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 644);
	if (fd <= 2)
		err_handler(data, 1, NULL, "Error open/create file for redirecting");
	line = NULL;
	while (start == 1)
	{
		line = readline("> ");
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			start = 0;
		ft_free((void *) &line, NULL, NULL);
	}
	close(fd);
	ft_free((void *) &delim, NULL, NULL);
}

int	check_option_re(int option, char **arrow, char directing)
{
	char	*temp;

	temp = *arrow;
	if (*(temp + 1) == ' ' && *(temp + 2) == directing)
		return (-1);
	else if (*(temp + 1) == directing)
	{
		temp++;
		option++;
	}
	temp++;
	*arrow = temp;
	return (option);
}
