/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:51:11 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:56:24 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image_to_display(t_param *param)
{
	t_image *image;

	image = &param->img_to_display;
	if (!(image->img_ptr = mlx_new_image(param->mlx_ptr,
	param->win.screen_width, param->win.screen_height)))
		clean_and_exit(param, NEW_IMG_ERR, 1);
	image->height = param->win.screen_height;
	image->width = param->win.screen_width;
	image->img_addr = (int *)mlx_get_data_addr(image->img_ptr, &image->b_p_p,
		&image->size_line, &image->endian);
}

void	perform_algo(t_param *param, int x)
{
	initialize_camera_ray(&param->algo, x, (double)param->win.screen_width);
	find_wall(&param->algo, param->map);
	find_wall_orientation(param);
	set_line_params(&param->algo, param);
	param->sprite.sp_max_dist[x] = param->algo.p_wall_dist;
}

void	ray_caster(t_param *param)
{
	int	x;

	create_image_to_display(param);
	x = -1;
	while (++x < param->win.screen_width)
	{
		perform_algo(param, x);
		draw_view_stripe(&param->algo, param, param->screen_buf[x]);
	}
	sprite_caster(param, param->screen_buf);
	draw_buffer(param->screen_buf, &param->img_to_display);
}
