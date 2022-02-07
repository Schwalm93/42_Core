/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 05:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/07 07:29:40 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./source/get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

typedef struct s_xy
{
	int			list_y;
	int			list_x;
	struct s_xy	*list_next;
}					t_xy;

typedef struct s_map
{
	t_xy			*head_coin;
	t_xy			*head_wall;
	t_xy			*head_empty;
	int				map_x;
	int				map_y;
	int				numb_coin;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				finish;
}					t_world;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*wall;
	int		wall_width;
	int		wall_height;
	void	*player;
	int		player_width;
	int		player_height;
	void	*exit;
	int		exit_width;
	int		exit_height;
	void	*coin;
	int		coin_width;
	int		coin_height;
	void	*empty;
	int		empty_width;
	int		empty_height;
	void	*exit_closed;
	int		exit_closed_width;
	int		exit_closed_height;
	int		count_steps;
}			t_mlx;

typedef struct s_pntr
{
	t_world	*t_map_p;
	t_mlx	*t_win_p;
}					t_pointer;

t_xy	*ft_lstnew_xy(int row, int coloum);
void	ft_map_init(t_pointer *t_pntr);
void	ft_lstadd_back_xy(t_xy **lst, t_xy *new);
void	ft_playermove(t_pointer *t_pntr);
int		ft_close_all(t_pointer *t_pntr);
void	ft_clear_lists(t_pointer *t_pnter);
void	ft_init_win(t_pointer *t_pntr);
void	ft_init(t_pointer *t_pntr);
void	ft_free(void *string);
void	ft_check_wall(char *line, int i, char **overflow);
int		ft_set_walls(char *line, int i, t_pointer *t_pntr, int *walls);
int		ft_set_player_coin(char *line, int i, t_pointer *t_pntr,
			char **overflow);
int		ft_set_exit(char *line, int i, t_pointer *t_pntr, char **overflow);
void	ft_check_line(char **line, t_pointer *t_pntr, char **overflow, int fp);
void	ft_check_wall_2(int *i, t_pointer *t_pntr, int *last_line, int walls);
void	ft_check_wall_3(int last_line, char **overflow, char *line,
			t_pointer *t_pntr);
void	ft_init_read_map(int *last_line, int *i, int *walls);
void	ft_error_input(int error, char **overflow, char *line);
void	ft_free_lists(t_pointer *t_pntr);
int		ft_check_y(int y, int *new_x, int *new_y, t_pointer *t_pntr);
int		ft_check_x(int x, int *new_x, int *new_y, t_pointer *t_pntr);
void	ft_change_image_1(t_pointer *t_pntr, int new_x, int new_y);
void	ft_change_image_2(t_pointer *t_pntr, int new_x, int new_y);
void	ft_change_image_3(t_pointer *t_pntr, int new_x, int new_y);
int		ft_init_image_1(t_pointer *t_pntr, int x_in, int y_in);
int		ft_init_image_2(t_pointer *t_pntr, int x_in, int y_in);
int		ft_init_image_3(t_pointer *t_pntr, int x_in, int y_in);
int		ft_init_image_4(t_pointer *t_pntr, int x_in, int y_in);
int		ft_init_image_5(t_pointer *t_pntr, int x_in, int y_in);
void	ft_file_to_pntr_1(t_pointer *t_pntr);
void	ft_file_to_pntr_2(t_pointer *t_pntr);
int		ft_check(int x, int y, t_pointer *t_pntr);
#endif