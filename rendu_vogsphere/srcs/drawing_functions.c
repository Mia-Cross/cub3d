/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:10:21 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:58:03 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	define_texture_variables(t_raycast *algo, t_param *param,
	t_image *texture)
{
	if (algo->side == 1)
		algo->wall_x = algo->player_pos.y + algo->p_wall_dist * algo->ray_dir.y;
	else
		algo->wall_x = algo->player_pos.x + algo->p_wall_dist * algo->ray_dir.x;
	algo->wall_x -= floor(algo->wall_x);
	algo->tex_x = (int)(algo->wall_x * (double)(texture->width));
	if (algo->side == 1 && algo->ray_dir.x > 0)
		algo->tex_x = (int)(texture->width - algo->tex_x - 1);
	else if (algo->side == 0 && algo->ray_dir.y < 0)
		algo->tex_x = (int)(texture->width - algo->tex_x - 1);
	algo->scale = (double)(1.0 * texture->height / algo->line_height);
	algo->tex_pos = (double)((algo->start - param->win.screen_height / 2 +
		algo->line_height / 2) * algo->scale);
}

void	draw_view_stripe(t_raycast *algo, t_param *param, int *screen_buf)
{
	t_image	*texture;
	int		i;

	texture = &param->text.north + algo->wall_dir;
	define_texture_variables(algo, param, texture);
	i = 0;
	while (i < algo->start)
		screen_buf[i++] = param->ceiling;
	while (i < algo->end)
	{
		algo->tex_y = (int)(algo->tex_pos);
		algo->tex_pos += algo->scale;
		algo->color = texture->img_addr[algo->tex_y * texture->height +
			algo->tex_x];
		screen_buf[i++] = algo->color;
	}
	while (i < param->win.screen_height)
		screen_buf[i++] = param->floor;
}

void	draw_sprites(int **screen_buf, t_sprite *sp_algo, t_image *sp_tex,
	t_param *param)
{
	int stripe;
	int y;

	stripe = sp_algo->draw_start_x - 1;
	while (++stripe < sp_algo->draw_end_x)
	{
		sp_algo->tex_x = (int)(256 * (stripe - (-sp_algo->sp_w / 2 +
			sp_algo->sp_screen_x)) * sp_tex->width / sp_algo->sp_w) / 256;
		if (sp_algo->tsf_y > 0 && stripe > 0 && stripe < param->win.screen_width
			&& sp_algo->tsf_y < sp_algo->sp_max_dist[stripe])
		{
			y = sp_algo->draw_start_y - 1;
			while (++y < sp_algo->draw_end_y)
			{
				sp_algo->d = y * 256 - param->win.screen_height * 128 +
					sp_algo->sp_h * 128;
				sp_algo->tex_y = ((sp_algo->d * sp_tex->height) / sp_algo->sp_h)
					/ 256;
				sp_algo->color = sp_tex->img_addr[sp_algo->tex_y * sp_tex->width
					+ sp_algo->tex_x];
				if (sp_algo->color != -16777216)
					screen_buf[stripe][y] = sp_algo->color;
			}
		}
	}
}

void	draw_buffer(int **screen_buf, t_image *img_to_display)
{
	int i;
	int j;
	int *ptr;

	ptr = (int *)(img_to_display->img_addr);
	j = 0;
	while (j < img_to_display->height)
	{
		i = 0;
		while (i < img_to_display->width)
		{
			*ptr = screen_buf[i][j];
			ptr++;
			i++;
		}
		j++;
	}
}
