/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:02:21 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*before_re(t_data *data, char *cmd, char *arrow)
{
	while (1)
	{
		if (is_white_space(*(arrow - 1)) == 1)
			arrow--;
		else
			break ;
	}
	return (ft_substr_pntr(data, arrow, cmd));
}

static	int	check_preoption_re(char directing, char **err_msg)
{
	int	option;

	option = 0;
	if (directing == '>')
		option = 1;
	else
		option = 3;
	if (directing == '>')
		*err_msg = "syntax error near unexpected token '>'";
	else
		*err_msg = "syntax error near unexpected token '<'";
	return (option);
}

static char	*create_after_re(char *arrow, char *before, char **name)
{
	int		temp;
	int		index;
	int		temp_2;
	char	*str;
	int		index_2;

	index = get_first_c(arrow);
	index_2 = get_next_space(arrow, index) - 1;
	str = ft_substr(arrow, index, index_2 + 1);
	*name = ft_strtrim_quotes(str);
	ft_free((void *) &str, NULL, NULL);
	temp = ft_strlen(arrow);
	temp_2 = get_next_c(arrow, index_2 + 1);
	if ((temp - index_2 - 1) > 0)
	{
		if (before[ft_strlen(before) - 1] != ' '
			&& before[ft_strlen(before) - 1] != '\t')
			return (ft_substr(arrow, temp_2 - 1, (temp - index_2 - 1)));
		else
			return (ft_substr(arrow, temp_2, (temp - index_2 - 1)));
	}
	else
		return (NULL);
}

char	*operate_re(t_data *data, char *cmd, char *arrow, char directing)
{
	char	*before;
	char	*after;
	char	*err_msg;
	char	*name;
	int		option;

	option = check_preoption_re(directing, &err_msg);
	before = before_re(data, cmd, arrow);
	option = check_option_re(option, &arrow, directing);
	name = NULL;
	if (option == -1)
		err_handler(data, 1, before, err_msg);
	if (option == 4)
	{
		ft_heredoc(data, arrow);
		ft_free((void *) &cmd, NULL, NULL);
		return (before);
	}
	after = create_after_re(arrow, before, &name);
	ft_open(data, option, name);
	ft_free((void *) &name, NULL, NULL);
	return (ft_redirect_helper(before, after, cmd));
}

void	redirect(t_data *data, int cmd_numb)
{
	char	**cmd;
	char	*out_arrow;
	char	*in_arrow;

	cmd = &data->t_commands[cmd_numb]->command;
	out_arrow = ft_strchr(*cmd, '>');
	if (out_arrow != NULL && re_check_quotes(*cmd, out_arrow, 0) == 0)
		*cmd = operate_re(data, *cmd, out_arrow, '>');
	in_arrow = ft_strchr(*cmd, '<');
	if (in_arrow != NULL && re_check_quotes(*cmd, in_arrow, 0) == 0)
		*cmd = operate_re(data, *cmd, in_arrow, '<');
}
