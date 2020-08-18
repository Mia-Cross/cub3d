/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:39:34 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:55:51 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprites(t_sprite *sprite, t_param *param)
{
	if (!(param->sprite.sp_max_dist = (double *)malloc(sizeof(double) *
		param->win.screen_width)))
		clean_and_exit(param, MALLOC_ERR, 1);
	add_malloc_to_list(&(param->malloc_list), param->sprite.sp_max_dist);
	sprite->sp_count = count_sprites(param->map);
	if (!(sprite->sp_order = (int *)malloc(sizeof(int) * sprite->sp_count)))
		clean_and_exit(param, MALLOC_ERR, 1);
	add_malloc_to_list(&(param->malloc_list), sprite->sp_order);
	if (!(sprite->sp_dist = (double *)malloc(sizeof(double) *
		sprite->sp_count)))
		clean_and_exit(param, MALLOC_ERR, 1);
	add_malloc_to_list(&(param->malloc_list), sprite->sp_dist);
	if (!(sprite->sprite_pos = (t_coord *)malloc(sizeof(t_coord) *
		sprite->sp_count)))
		clean_and_exit(param, MALLOC_ERR, 1);
	add_malloc_to_list(&(param->malloc_list), sprite->sprite_pos);
	get_sprites_pos(param->map, sprite);
}

void	sort_sprites(t_sprite *sp, t_raycast *algo)
{
	int i;

	i = -1;
	while (++i < sp->sp_count)
	{
		sp->sp_order[i] = i;
		sp->sp_dist[i] = pow((algo->player_pos.x - sp->sprite_pos[i].x), 2)
			+ pow((algo->player_pos.y - sp->sprite_pos[i].y), 2);
	}
	ft_sort_double_tab_index(sp->sp_dist, sp->sp_order, sp->sp_count);
}

void	detect_sprites(t_sprite *sp_algo, t_param *param, int i)
{
	sort_sprites(sp_algo, &param->algo);
	sp_algo->sprite_x = sp_algo->sprite_pos[sp_algo->sp_order[i]].x -
		param->algo.player_pos.x;
	sp_algo->sprite_y = sp_algo->sprite_pos[sp_algo->sp_order[i]].y -
		param->algo.player_pos.y;
	sp_algo->inv_det = 1.0 / (param->algo.cam_plane.x * param->algo.player_dir.y
		- param->algo.player_dir.x * param->algo.cam_plane.y);
	sp_algo->tsf_x = sp_algo->inv_det * (param->algo.player_dir.y *
		sp_algo->sprite_x - param->algo.player_dir.x * sp_algo->sprite_y);
	sp_algo->tsf_y = sp_algo->inv_det * (-param->algo.cam_plane.y *
		sp_algo->sprite_x + param->algo.cam_plane.x * sp_algo->sprite_y);
	sp_algo->sp_screen_x = (int)((param->win.screen_width / 2) * (1 +
		sp_algo->tsf_x / sp_algo->tsf_y));
	sp_algo->sp_h = abs((int)(param->win.screen_height
		/ sp_algo->tsf_y));
}

void	set_sprite_line(t_sprite *sp_algo, t_param *param)
{
	sp_algo->draw_start_y = -sp_algo->sp_h / 2 +
		param->win.screen_height / 2;
	if (sp_algo->draw_start_y < 0)
		sp_algo->draw_start_y = 0;
	sp_algo->draw_end_y = sp_algo->sp_h / 2 +
		param->win.screen_height / 2;
	if (sp_algo->draw_end_y >= param->win.screen_height)
		sp_algo->draw_end_y = param->win.screen_height - 1;
	sp_algo->sp_w = abs((int)(param->win.screen_height
		/ sp_algo->tsf_y));
	sp_algo->draw_start_x = -sp_algo->sp_w / 2 +
		sp_algo->sp_screen_x;
	if (sp_algo->draw_start_x < 0)
		sp_algo->draw_start_x = 0;
	sp_algo->draw_end_x = sp_algo->sp_w / 2 +
		sp_algo->sp_screen_x;
	if (sp_algo->draw_end_x >= param->win.screen_width)
		sp_algo->draw_end_x = param->win.screen_width - 1;
}

void	sprite_caster(t_param *param, int **screen_buf)
{
	int i;

	i = -1;
	while (++i < param->sprite.sp_count)
	{
		detect_sprites(&param->sprite, param, i);
		set_sprite_line(&param->sprite, param);
		draw_sprites(screen_buf, &param->sprite, &param->text.sprite,
			param);
	}
}
