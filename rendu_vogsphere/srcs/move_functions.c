/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:51:28 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/25 12:38:13 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		can_step(char **map, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map[map_y][map_x] == '1' || map[map_y][map_x] == '2')
		return (0);
	return (1);
}

void	move_player_side(t_param *param)
{
	t_raycast	*algo;
	t_move		*mvt;

	algo = &param->algo;
	mvt = &param->mvt;
	if (mvt->move_left)
	{
		if (can_step(param->map, (algo->player_pos.x - algo->cam_plane.x *
			mvt->move_speed), algo->player_pos.y))
			algo->player_pos.x -= algo->cam_plane.x * mvt->move_speed;
		if (can_step(param->map, algo->player_pos.x, (algo->player_pos.y -
			algo->cam_plane.y * mvt->move_speed)))
			algo->player_pos.y -= algo->cam_plane.y * mvt->move_speed;
	}
	if (mvt->move_right)
	{
		if (can_step(param->map, (algo->player_pos.x + algo->cam_plane.x *
			mvt->move_speed), algo->player_pos.y))
			algo->player_pos.x += algo->cam_plane.x * mvt->move_speed;
		if (can_step(param->map, algo->player_pos.x, (algo->player_pos.y +
			algo->cam_plane.y * mvt->move_speed)))
			algo->player_pos.y += algo->cam_plane.y * mvt->move_speed;
	}
}

void	move_player_fwd(t_param *param)
{
	t_raycast	*algo;
	t_move		*mvt;

	algo = &param->algo;
	mvt = &param->mvt;
	if (mvt->move_fwd)
	{
		if (can_step(param->map, (algo->player_pos.x + algo->player_dir.x *
			mvt->move_speed), algo->player_pos.y))
			algo->player_pos.x += algo->player_dir.x * mvt->move_speed;
		if (can_step(param->map, algo->player_pos.x, (algo->player_pos.y +
			algo->player_dir.y * mvt->move_speed)))
			algo->player_pos.y += algo->player_dir.y * mvt->move_speed;
	}
	if (mvt->move_back)
	{
		if (can_step(param->map, (algo->player_pos.x - algo->player_dir.x *
			mvt->move_speed), algo->player_pos.y))
			algo->player_pos.x -= algo->player_dir.x * mvt->move_speed;
		if (can_step(param->map, algo->player_pos.x, (algo->player_pos.y -
			algo->player_dir.y * mvt->move_speed)))
			algo->player_pos.y -= algo->player_dir.y * mvt->move_speed;
	}
}

void	move_camera(t_param *param)
{
	double old_dir_x;

	if (param->mvt.rot_left)
	{
		old_dir_x = param->algo.player_dir.x;
		param->algo.player_dir.x = param->algo.player_dir.x *
			cos(-param->mvt.cam_speed) - param->algo.player_dir.y *
			sin(-param->mvt.cam_speed);
		param->algo.player_dir.y = old_dir_x * sin(-param->mvt.cam_speed) +
			param->algo.player_dir.y * cos(-param->mvt.cam_speed);
	}
	if (param->mvt.rot_right)
	{
		old_dir_x = param->algo.player_dir.x;
		param->algo.player_dir.x = param->algo.player_dir.x *
			cos(param->mvt.cam_speed) - param->algo.player_dir.y *
			sin(param->mvt.cam_speed);
		param->algo.player_dir.y = old_dir_x * sin(param->mvt.cam_speed)
			+ param->algo.player_dir.y * cos(param->mvt.cam_speed);
	}
	param->algo.cam_plane.x = (double)(-FOV / 100.0 * param->algo.player_dir.y);
	param->algo.cam_plane.y = (double)(FOV / 100.0 * param->algo.player_dir.x);
}
