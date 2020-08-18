/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:33:33 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/28 15:24:01 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

# include "linked_list.h"

typedef struct	s_coord
{
	double x;
	double y;
}				t_coord;

typedef struct	s_image
{
	char	*path;
	void	*img_ptr;
	int		*img_addr;
	int		height;
	int		width;
	int		size_line;
	int		b_p_p;
	int		endian;
}				t_image;

typedef struct	s_bmp
{
	char			*img_ptr;
	unsigned char	header[14];
	unsigned char	pad[3];
	unsigned char	info[40];
	int				size;
	int				fd;
	int				color;
}				t_bmp;

typedef struct	s_palette
{
	t_image north;
	t_image south;
	t_image west;
	t_image east;
	t_image sprite;
}				t_palette;

typedef struct	s_sprite
{
	double	*sp_max_dist;
	int		sp_count;
	int		*sp_order;
	t_coord	*sprite_pos;
	double	*sp_dist;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	tsf_x;
	double	tsf_y;
	int		sp_screen_x;
	int		sp_h;
	int		sp_w;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		tex_x;
	int		tex_y;
	int		d;
	int		color;
}				t_sprite;

typedef struct	s_move
{
	int		move_fwd;
	int		move_back;
	int		move_left;
	int		move_right;
	int		rot_left;
	int		rot_right;
	double	move_speed;
	double	cam_speed;
}				t_move;

typedef struct	s_raycast
{
	t_coord	player_dir;
	t_coord	player_pos;
	t_coord	cam_plane;
	t_coord	ray_dir;
	t_coord	delta_dist;
	t_coord	side_dist;
	t_coord	step;
	double	camera_x;
	double	p_wall_dist;
	int		wall_dir;
	int		start;
	int		end;
	int		map_x;
	int		map_y;
	int		color;
	int		line_height;
	int		hit;
	int		side;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	scale;
	double	tex_pos;
}				t_raycast;

typedef struct	s_window
{
	void	*win_ptr;
	int		screen_height;
	int		screen_width;
}				t_window;

typedef struct	s_param
{
	void		*mlx_ptr;
	t_window	win;
	t_image		img_to_display;
	t_palette	text;
	t_raycast	algo;
	t_move		mvt;
	t_sprite	sprite;
	t_list		*malloc_list;
	int			**screen_buf;
	char		**map;
	char		check[9];
	int			fd;
	int			map_height;
	int			floor;
	int			ceiling;
	int			create_bmp;
}				t_param;

#endif
