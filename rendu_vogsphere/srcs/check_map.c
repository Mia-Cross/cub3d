/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:13:51 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:59:24 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_and_last_line(char **map, t_param *param)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			clean_and_exit(param, N_SIDE_ERR, 0);
		i++;
	}
	i = 0;
	while (map[param->map_height - 1][i])
	{
		if (map[param->map_height - 1][i] != '1')
			clean_and_exit(param, S_SIDE_ERR, 0);
		i++;
	}
}

void	check_first_column(char **map, t_param *param)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			clean_and_exit(param, W_SIDE_ERR, 0);
		i++;
	}
}

int		check_line_diff(char *str, int diff)
{
	while (diff)
	{
		if (str[ft_strlen(str) - diff] != '1')
			return (0);
		diff--;
	}
	return (1);
}

void	check_last_column(char **map, t_param *param)
{
	int i;
	int j;
	int diff;
	int ret;

	i = 0;
	j = 0;
	ret = -1;
	while (map[++i] && *map[i] == '1')
	{
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			clean_and_exit(param, E_SIDE_ERR, 0);
		diff = ft_strlen(map[i]) - ft_strlen(map[i - 1]);
		if (diff > 0)
			ret = check_line_diff(map[i], diff);
		else if (diff < 0)
			ret = check_line_diff(map[i - 1], -diff);
		if (ret == 0)
			clean_and_exit(param, E_SIDE_ERR, 0);
	}
}

void	check_borders(char **map, t_param *param)
{
	int ret;

	if (!map)
		return ;
	check_first_and_last_line(map, param);
	check_first_column(map, param);
	check_last_column(map, param);
	if ((ret = search_player(map)) > 0)
		return ;
	else if (ret == 0)
		clean_and_exit(param, NO_PLAYER_ERR, 0);
	else if (ret == -2)
		clean_and_exit(param, INVALID_CHAR_ERR, 0);
	else if (ret == -1)
		clean_and_exit(param, MULT_PLAYER_ERR, 0);
}
