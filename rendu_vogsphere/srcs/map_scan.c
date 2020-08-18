/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:38:52 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/20 14:56:23 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_coord	get_player_direction(char **matrix)
{
	t_coord result;
	int		player;

	player = search_player(matrix);
	if (player == 'N' || player == 'S')
	{
		result.x = 0;
		result.y = 1;
		if (player == 'N')
			result.y = -1;
	}
	else
	{
		result.x = 1;
		result.y = 0;
		if (player == 'W')
			result.x = -1;
	}
	return (result);
}

int		get_player_pos_x(char **map)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (is_player(map[y][x]))
				return (x);
		}
	}
	return (-1);
}

int		get_player_pos_y(char **map)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (is_player(map[y][x]))
				return (y);
		}
	}
	return (-1);
}

void	get_sprites_pos(char **map, t_sprite *sp)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
			{
				sp->sprite_pos[k].x = j + 0.5;
				sp->sprite_pos[k].y = i + 0.5;
				k++;
			}
		}
	}
}

int		count_sprites(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
				count++;
		}
	}
	return (count);
}
