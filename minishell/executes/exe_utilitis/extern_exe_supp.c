/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_exe_supp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:24:14 by tguth             #+#    #+#             */
/*   Updated: 2022/05/26 13:06:49 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*extern_exe_support(int *start, char *str, char *func)
{
	char	*tmp;
	char	*exe_path;

	tmp = NULL;
	*start = 1;
	if (func[0] != '/')
	{
		tmp = ft_strjoin(str, "/");
		exe_path = ft_strjoin(tmp, func);
		ft_free((void *) &tmp, NULL, NULL);
	}
	else
		exe_path = ft_strdup(func);
	return (exe_path);
}
