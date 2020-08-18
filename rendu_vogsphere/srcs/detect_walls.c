/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:59:47 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 16:39:03 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_side_dist(double ray_dir, double pos, double delta_dist,
	int map)
{
	double side_dist;

	side_dist = (double)((map + 1.0 - pos) * delta_dist);
	if (ray_dir < 0)
		side_dist = (double)((pos - map) * delta_dist);
	return (side_dist);
}

void	initialize_camera_ray(t_raycast *algo, int x, double screen_width)
{
	algo->map_x = (int)(algo->player_pos.x);
	algo->map_y = (int)(algo->player_pos.y);
	algo->hit = 0;
	algo->side = 0;
	algo->camera_x = 2 * x / screen_width - 1.0;
	algo->ray_dir.x = algo->player_dir.x + algo->cam_plane.x *
		algo->camera_x;
	algo->ray_dir.y = algo->player_dir.y + algo->cam_plane.y *
		algo->camera_x;
	algo->delta_dist.x = fabs(1 / algo->ray_dir.x);
	algo->delta_dist.y = fabs(1 / algo->ray_dir.y);
	algo->step.x = 1;
	algo->step.y = 1;
	if (algo->ray_dir.x < 0)
		algo->step.x = -1;
	if (algo->ray_dir.y < 0)
		algo->step.y = -1;
}

void	find_wall(t_raycast *algo, char **matrix)
{
	while (algo->hit == 0)
	{
		algo->side_dist.x = get_side_dist(algo->ray_dir.x, algo->player_pos.x,
			algo->delta_dist.x, algo->map_x);
		algo->side_dist.y = get_side_dist(algo->ray_dir.y, algo->player_pos.y,
			algo->delta_dist.y, algo->map_y);
		if (algo->side_dist.x < algo->side_dist.y)
		{
			algo->side_dist.x += algo->delta_dist.x;
			algo->map_x += algo->step.x;
			algo->side = 1;
		}
		else
		{
			algo->side_dist.y += algo->delta_dist.y;
			algo->map_y += algo->step.y;
			algo->side = 0;
		}
		if (matrix[algo->map_y][algo->map_x] == '1')
			algo->hit = 1;
	}
}

void	find_wall_orientation(t_param *param)
{
	if (param->algo.side == 0)
	{
		param->algo.wall_dir = SOUTH;
		if (param->algo.ray_dir.y < 0)
			param->algo.wall_dir = NORTH;
	}
	else
	{
		param->algo.wall_dir = EAST;
		if (param->algo.ray_dir.x < 0)
			param->algo.wall_dir = WEST;
	}
}

void	set_line_params(t_raycast *algo, t_param *param)
{
	if (algo->side == 1)
		algo->p_wall_dist = (algo->map_x - algo->player_pos.x +
			(1.0 - algo->step.x) / 2) / algo->ray_dir.x;
	else
		algo->p_wall_dist = (algo->map_y - algo->player_pos.y +
			(1.0 - algo->step.y) / 2) / algo->ray_dir.y;
	algo->line_height = (int)(param->win.screen_height / algo->p_wall_dist);
	algo->start = (int)(param->win.screen_height / 2 - algo->line_height / 2);
	if (algo->start < 0)
		algo->start = 0;
	algo->end = (int)(param->win.screen_height / 2 + algo->line_height / 2);
	if (algo->end >= param->win.screen_height)
		algo->end = param->win.screen_height - 1;
}
