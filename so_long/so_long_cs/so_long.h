/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:34:29 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/09 11:44:00 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx_linux/mlx.h"
# include "./gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 

typedef struct s_program
{
	void	*mlx;
	void	*win;
	char	*gnl;
	int		check;
	int		pl;
	int		count_coin;
	int		finish;
	int		steps;
	int		check_step;
	int		move;
	int		map_h;
	int		map_w;
	int		print_x;
	int		print_y;
	void	*player;
	int		player_pos_x;
	int		player_pos_y;
	void	*empty;
	int		empty_pos_x;
	int		empty_pos_y;
	void	*exit;
	void	*coin;
	void	*wall;
}				t_program;

typedef struct s_map
{
	int		wall_l;
	int		wall_h;
	int		player_l;
	int		player_h;
	int		empty_l;
	int		empty_h;
	int		coin_l;
	int		coin_h;
	int		enemy_l;
	int		enemy_h;
	int		exit_l;
	int		exit_h;
}				t_map;

void	check_map(t_program *program, char *map);
void	check_map_wall(t_program *pro, char *map);
void	check_map_rect2(t_program *pro, char *map);
void	img_init(t_program *program, t_map *map);
void	printmap(t_program *program, char type);
int		ft_close(t_program *program);
int		ft_pressbutton(int keycode, t_program *program);
void	read_map(t_program *program, char *argv);
char	*ft_strjoin(char *s1, char *s2);
void	map_init(t_program *program);
void	player_startlocation(t_program *program);
void	move(t_program *program, int keycode);
void	ft_exit(t_program *pro);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_error_image(t_program *pro);
void	ft_error_map(t_program *pro);
void	check_map_rect_error(t_program *pro);
void	check_map_forbidden_chars(t_program *pro, char *map);

#endif