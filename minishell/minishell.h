/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:57:00 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:48:00 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./Libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include "./gnl/get_next_line_bonus.h"
# include <sys/wait.h>

# ifdef __linux__
#  include <linux/limits.h>
# else
#  include <sys/syslimits.h>
# endif

typedef struct s_command
{
	char		*command;
	int			input_fd;
	int			output_fd;
	int			id;
}	t_command;

typedef struct s_data
{
	int				count_pipe;
	int				env_len;
	int				stdout_cpy;
	int				stdin_cpy;
	int				**pipes_fd;
	int				redirect_stat[2];
	int				status_code;
	int				status_len;
	char			path[PATH_MAX];
	char			*line;
	char			**env_strings;
	int				cmd_numb;
	int				index;
	t_command		**t_commands;
}	t_data;

/*
global
*/
extern int	g_pid;

/*
manatory minishell
*/
void	read_input(t_data *data);
void	parse_input(t_data *data);
void	ft_pwd(t_data *data);
void	ft_free(void **single_pntr, void ***arr_pntr, void ***single_arrpntr);
void	err_handler(t_data *data, int fatal_err, void *mem, char *err_str);
void	signal_check(t_data *data);
void	ft_exit(t_data *data);
void	re_init(t_data *data);
void	run(t_data *data);

/*
utilitis
*/
int		trim_strlen(char *s);
int		get_last_c(char *s);
int		get_first_c(char *s);
int		is_white_space(char c);
int		get_next_space(char *s, int start_index);
void	command_trim(t_data *data, int cmd_numb);
char	*ft_substr_pntr(t_data *data, char *big, char *small);
char	*ft_trim(char *cmd, int *set_flag);
char	*ft_strtrim_mini(char *s1, char const *set);
char	*create_substr_before(t_data *data, char *str, char *dol);
char	*create_substr_after(char *dol, int index);
void	create_string(char **str, char *before, char *after, char *var);
int		get_next_c(char *s, int index);
char	*valided_variable(t_data *data, char *dol, int *index);
int		ft_input_strncmp(const char *s1, const char *s2, size_t len);
char	*get_func(t_data *data, int cmd_numb);
char	**get_path(t_data *data);
void	check_all_paths(t_data *data);
int		is_all_white_space(char *str);
char	*find_path(char **old_path);
void	num_pipes(t_data *data);
char	**ft_init_cmd(t_data *data, char *str, int *j);
char	**init_cmd(char *str, t_data *data);
void	ft_helper(t_data *data, char *str, int j, char ***cmd);
char	*ft_strtrim_quotes(char *s1);
void	check_i_zero(char line_char, char *c, int *count, int *quotes);
void	check_i_not_zero(char *line_char, char *c, int *count, int *quotes);
void	check_i_z(char line_char, char *c, int *quotes);
void	check_i_nz(char *line_char, char *c, int *quotes);
void	ft_putstr_fd_c(char *s, int fd);

/*
redirect
*/
void	redirect(t_data *data, int cmd_numb);
void	ft_open(t_data *data, int option, char *path);
void	ft_heredoc(t_data *data, char *in_arrow);
int		check_option_re(int option, char **arrow, char directing);
int		re_check_quotes(char *begin, char *arrow, int echo);
char	*ft_redirect_helper(char *before, char *after, char *cmd);

/*
echo
*/
void	ft_echo(t_data *data, int cmd_numb);
void	create_string_support(char **str, char *sol, char *before);
void	ft_trim_helper(char **temp, int first, int *i, int *set_flag);
void	create_string_1_h(char *before, char *after, char *var, char **sol);
void	create_string_2_h(char *before, char *var, char **sol);
char	*create_string_3_h(char *after, char *var, char *before, int i);

/*
cd
*/
void	ft_cd(t_data *data, int cmd_numb);
char	*ft_check_master(t_data *data, char *str, int *status);
char	*ft_cd_back(t_data *data, char **temp, int turn, char **cmd);
char	*check_cd_name(t_data *data, char ***temp);
void	ft_set_cd(t_data *data, char *path, char **cmd, char **tmp);
void	ft_create_cd(t_data *data, char *str, char **cmd);
char	*get_sec_last_str(char **str);
int		ft_check_cd_1_helper(char **sol, char *tmp);
void	cd_supp_1_helper(t_data *data, int turn, char **str);
int		ft_check_cd_helper(char **sol, char **temp, int i, int index);

/*
execute
*/
void	before_exe_re(t_data *data, int cmd_numb);
void	before_exe_pipe(t_data *data, int cmd_numb);
void	after_exe(t_data *data);
void	select_exe(t_data *data, int cmd_numb);
void	extern_execute(t_data *data, int cmd_numb, int start);
char	**get_path(t_data *data);
char	*extern_exe_support(int *start, char *str, char *func);
char	*copy_and_cut_str(t_data *data, char *func);
int		check_path(t_data *data, char *path, char *func, int exce_file);

/*
env
*/
char	**init_env(char **environ, t_data *data);
void	set_env(t_data *data, char *var_value);
void	ft_unset(t_data *data, int cmd_numb);
void	print_env(t_data *data);
void	set_env_var(t_data *data, char *var, char *name);
int		find_var_index(t_data *data, char *var);
void	get_env_len(t_data *data, char **environ);
char	*get_var(t_data *data, char *var);

/*
export
*/
void	ft_export(t_data *data, int cmd_numb);
int		check_for_variables(char *cmd);
void	sort_exp_strings(t_data *data);

/*
pipe
*/

void	ft_pipe(t_data *data);

/*
status
*/

int		count_status(t_data *data, char *str);

#endif
