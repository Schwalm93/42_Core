/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:57:01 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:27:51 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include "./mlx_linux/mlx.h"
# include "./library/Libft/libft.h"
# include "./library/gnl/get_next_line.h"
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# ifndef PI
#  define PI 3.14159265359
# endif
# ifndef SCREENWIDTH
#  define SCREENWIDTH 768
# endif
# ifndef STEP_SIZE
#  define STEP_SIZE 0.05
# endif
# ifndef HITBOX_SIDE
#  define HITBOX_SIDE 0.1
# endif
# ifdef __linux__
#  define W_KEY 119
#  define S_KEY 115
#  define A_KEY 97
#  define D_KEY 100
#  define ARROW_L_KEY 65363
#  define ARROW_R_KEY 65361
#  define ESC_KEY 65307
# else
#  define W_KEY 13
#  define S_KEY 1
#  define A_KEY 0
#  define D_KEY 2
#  define ARROW_L_KEY 124
#  define ARROW_R_KEY 123
#  define ESC_KEY 53
# endif

typedef struct s_data
{
	struct s_player	*player;
	struct s_map	*map_attr;
	struct s_mlx	*mlx_attr;
}	t_data;

typedef struct s_map
{
	char	**map_char;
	int		**map;
	char	*n_texture;
	int		n_ok;
	char	*s_texture;
	int		s_ok;
	char	*w_texture;
	int		w_ok;
	char	*e_texture;
	int		e_ok;
	int		rgb_floor[3];
	int		rgb_ceiling[3];
	int		map_width;
	int		map_height;
	int		player_dir;
	int		counter;
	int		count_j;
	int		count_str;
}	t_map;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	struct s_img	*img_n;
	struct s_img	*img_s;
	struct s_img	*img_w;
	struct s_img	*img_e;
}	t_mlx;

typedef struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	float	look_right;
	float	look_left;
}	t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	float	perp_dis;
}	t_img;

typedef struct s_ray
{
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			camera_x;
	float			raydir_x;
	float			raydir_y;
	float			end_x;
	float			end_y;
	float			side_dis_x;
	float			side_dis_y;
	float			step_len_x;
	float			step_len_y;
	float			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				draw_start;
	int				draw_end;
	struct s_dda	*dda;
}	t_ray;

typedef struct s_dda
{
	float	x;
	int		count;
	int		hit;
	int		side;
}	t_dda;

typedef struct s_draw
{
	double	delta_x;
	double	delta_y;
	double	pixel_y;
	double	pixel_x;
	int		delta_y_i;
	int		pixels;
	int		count;
	int		diff;
	int		dda_count;
}	t_draw;

/*----------------check_input--------------------*/

void	check_input_argv(int argc, char **argv);

/*----------------init_struct---------------------*/

void	init_struct(t_data *data, t_map *map, t_mlx *mlx, t_player *player);
void	check_pictures(t_data *data);
void	init_pictures_n_s(t_data *data);
void	init_pictures_w_e(t_data *data);
void	init_player_view(t_data *data);

/*----------------check_map-----------------------*/

void	get_map(t_data *data, char *filepath);
int		read_map_file(t_data *data, char *filepath);
int		check_map(t_data *data);
int		check_map_characters(t_data *data);
int		check_map_walls_around(t_data *data);
int		check_map_walls(t_data *data);
void	get_map_dimensions(t_data *data, char **map_file);
void	store_map(t_data *data, char *map_str, int i, int j);
char	**ft_split_map(t_data *data, const char *s, char c, int i);
int		ft_split_helper1(const char *s, int i, char c, unsigned int *pos_1);
void	get_map_dimensions(t_data *data, char **map_file);
void	store_map_array(t_data *data, char **map_file, int j, int z);
int		get_color_texture(t_data *data, char **map_file);
int		get_color_texture_helper(t_data *data, char *temp);
void	end_store_map(char *map_str, char **temp, t_data *data);
char	*color_texture_trim(char *string);
int		get_texture(t_data *data, char *string, char c);
int		get_color(t_data *data, char *string, char c);
int		get_color_helper(char *str, char c);
void	get_color_save(t_data *data, char c, char *str, int j);
int		check_color(char *string);
void	check_color_range(t_data *data);
void	char_to_int(t_data *data);
int		get_first_c(char *s);
int		is_white_space(char c);
int		get_next_c(char *s, int index);
int		checkspace(const char *str, int i);

/*----------------Keybinding-----------------------*/

void	keyhooks(t_data *data);
int		pressbutton_n(int keycode, t_data *data);
int		releasebutton_n(int keycode, t_data *data);
int		pressbutton_e(int keycode, t_data *data);
int		releasebutton_e(int keycode, t_data *data);
int		pressbutton_w(int keycode, t_data *data);
int		releasebutton_w(int keycode, t_data *data);
int		ft_close(t_data *data);

/*----------------Movement-----------------------*/

void	look_right_left(t_data *data, int left);
void	left_vision(t_data *data);
void	right_vision(t_data *data);
void	wall_collision(t_data *data, int directing);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/*--------------------Raycasting-------------------*/

void	ray_cast(t_data *data);
void	calc_draw_points(t_ray *ray);
int		calc_tex_diff(t_data *data, t_ray *ray, int side);
void	calc_perdis(t_ray *ray, int side);
void	calc_step_init_dist(t_ray *ray);

/*-------------------Free--------------------------*/

void	ft_free_str(void **pntr);
void	ft_free_arry(void ***pntr);

/*-------------------Drawing-----------------------*/

void	img_pix_put(t_img *img, int x, int y, int color);
void	img_pix_put_t(t_img *img, t_data *data, t_draw *draw, int side);
void	img_pix_put_tt(t_img *img, t_data *data, t_draw *draw, int side);
void	draw_floor_ceiling(t_img *img, int x, t_data *data);
void	draw_hline_tex(t_img *img, t_ray *ray, t_data *data, int diff);
char	*get_pixel_tex(t_data *data, t_draw *draw, int diff_y, int side);
int		rgb_to_i(t_data *data, int floor);

/*-------------------Minimap-----------------------*/

void	draw_minimap(t_data *data, t_img *img);

/*----------------Error_handling-------------------*/

void	ft_exit(t_data *data, int error, char *error_msg);
void	destroy_all(t_data *data);
void	ft_desetroy_north_south(t_data *data);
void	ft_desetroy_west_east(t_data *data);
void	free_structs(t_data *data);
void	printe(char *error_str);

#endif
