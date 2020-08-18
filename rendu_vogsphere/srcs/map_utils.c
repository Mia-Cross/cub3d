/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:59:52 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/28 17:48:22 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_map_lines(char *path)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(path, O_RDONLY);
	count = 0;
	while (get_next_line(fd, &line))
	{
		if (line && (*line == '1' || *line == '0'))
			count++;
		free(line);
	}
	if (line && (*line == '1' || *line == '0'))
		count++;
	free(line);
	close(fd);
	return (count);
}

int	is_player(int i)
{
	if (i == 'N' || i == 'E' || i == 'S' || i == 'W')
		return (1);
	return (0);
}

int	is_invalid(int i)
{
	if (!(i == '0' || i == '1' || i == '2' || is_player(i)))
		return (1);
	return (0);
}

int	search_player(char **map)
{
	int i;
	int j;
	int player;

	i = 0;
	player = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (!player && is_player(map[i][j]))
				player = map[i][j];
			else if (is_invalid(map[i][j]))
				return (-2);
			else if (player && is_player(map[i][j]))
				return (-1);
		}
	}
	return (player);
}
