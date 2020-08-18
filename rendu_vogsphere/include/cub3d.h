/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:49:42 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/28 11:10:51 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>

# include "libft.h"
# include "cub3d_structures.h"
# include "cub3d_error.h"

# define FOV 66
# define RUN_SPEED 0.15
# define SPEED 0.07
# define CAM_SPEED 0.05

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SHIFT 257
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define CLOSE_BUTTON_EVENT 17

void	initialize_mlx(t_param *param);
void	initialize_window_and_textures(t_param *param);
void	initialize_vectors(t_raycast *algo, char **matrix);

int		check_extension(char *path);
void	check_arguments(int ac, char **av, t_param *param);
void	save_view_as_bmp(t_param *param);
void	read_cub_file(char *path, t_param *param);

void	clean_and_exit(t_param *param, char *msg, int clean_mlx);
void	clean_image_struct(t_image *image);

int		key_press(int key, t_param *param);
int		key_release(int key, t_param *param);
int		key_loop(t_param *param);
int		click_to_quit(t_param *param);

int		get_player_pos_x(char **map);
int		get_player_pos_y(char **map);
t_coord	get_player_direction(char **matrix);
void	move_player_side(t_param *param);
void	move_player_fwd(t_param *param);
void	move_camera(t_param *param);

void	ray_caster(t_param *param);
void	initialize_camera_ray(t_raycast *algo, int x, double screen_width);
void	find_wall(t_raycast *algo, char **matrix);
void	find_wall_orientation(t_param *param);
void	set_line_params(t_raycast *algo, t_param *param);
void	draw_view_stripe(t_raycast *algo, t_param *param, int *screen_buf);

void	sprite_caster(t_param *param, int **screen_buf);
void	set_sprites(t_sprite *sprite, t_param *param);
int		count_sprites(char **map);
void	get_sprites_pos(char **map, t_sprite *sp);
void	ft_sort_double_tab_index(double *values, int *index, int size);
void	draw_sprites(int **screen_buf, t_sprite *sp_algo, t_image *sp_tex,
		t_param *param);
void	clean_sprites_data(t_param *param, t_sprite *sprite);

void	draw_buffer(int **screen_buf, t_image *img_to_display);
void	free_buffer(int **screen_buf, int width);

int		is_player(int i);
int		search_player(char **map);
int		count_map_lines(char *path);
void	check_borders(char **map, t_param *param);

int		rgb_to_int(int r, int g, int b);
char	*get_path(t_param *param, char *line, char *indic, char id);
int		parse_color(char *line, char *indic, char id);
void	load_all_textures(t_param *param);
void	check_param_validity(char parsing[9], t_param *param);
int		check_string(char *line);

#endif
