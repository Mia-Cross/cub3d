/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:42:20 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 16:39:03 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int key, t_param *param)
{
	if (key == KEY_A)
		param->mvt.move_left = 1;
	if (key == KEY_S)
		param->mvt.move_back = 1;
	if (key == KEY_D)
		param->mvt.move_right = 1;
	if (key == KEY_W)
		param->mvt.move_fwd = 1;
	if (key == KEY_RIGHT || key == KEY_E)
		param->mvt.rot_right = 1;
	if (key == KEY_LEFT || key == KEY_Q)
		param->mvt.rot_left = 1;
	if (key == KEY_SHIFT)
		param->mvt.move_speed = RUN_SPEED;
	if (key == 53)
		clean_and_exit(param, EXIT_MSG, 1);
	return (0);
}

int	key_release(int key, t_param *param)
{
	if (key == KEY_A)
		param->mvt.move_left = 0;
	if (key == KEY_S)
		param->mvt.move_back = 0;
	if (key == KEY_D)
		param->mvt.move_right = 0;
	if (key == KEY_W)
		param->mvt.move_fwd = 0;
	if (key == KEY_RIGHT || key == KEY_E)
		param->mvt.rot_right = 0;
	if (key == KEY_LEFT || key == KEY_Q)
		param->mvt.rot_left = 0;
	if (key == KEY_SHIFT)
		param->mvt.move_speed = SPEED;
	return (0);
}

int	click_to_quit(t_param *param)
{
	clean_and_exit(param, EXIT_MSG, 1);
	return (0);
}

int	key_loop(t_param *param)
{
	double	old_sum;
	double	new_sum;

	old_sum = param->algo.player_dir.x + param->algo.cam_plane.x +
		param->algo.player_pos.x + param->algo.player_dir.y +
		param->algo.cam_plane.y + param->algo.player_pos.y;
	if (param->mvt.move_left || param->mvt.move_right)
		move_player_side(param);
	if (param->mvt.move_fwd || param->mvt.move_back)
		move_player_fwd(param);
	if (param->mvt.rot_right || param->mvt.rot_left)
		move_camera(param);
	new_sum = param->algo.player_dir.x + param->algo.cam_plane.x +
		param->algo.player_pos.x + param->algo.player_dir.y +
		param->algo.cam_plane.y + param->algo.player_pos.y;
	if (old_sum != new_sum)
	{
		mlx_clear_window(param->mlx_ptr, param->win.win_ptr);
		ray_caster(param);
		mlx_put_image_to_window(param->mlx_ptr, param->win.win_ptr,
		param->img_to_display.img_ptr, 0, 0);
		mlx_destroy_image(param->mlx_ptr, param->img_to_display.img_ptr);
	}
	return (0);
}
