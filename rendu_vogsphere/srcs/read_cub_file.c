/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:54:08 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 16:02:58 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(char *line, t_param *param, char *indic, char id)
{
	int i;
	int res[3];
	int j;

	i = 1;
	j = -1;
	ft_memset(res, -1, 12);
	if (!check_string(line))
	{
		*indic = 'E';
		return ;
	}
	while (line[i] && ++j < 3)
		i = ft_atoi_ptr(line, i, &res[j]);
	if (*indic == id || *indic == 'D')
		*indic = 'D';
	else if (res[0] > 0 && res[1] > 0 && res[2] == -1)
	{
		param->win.screen_width = res[0];
		param->win.screen_height = res[1];
		*indic = id;
	}
	else
		*indic = 'E';
}

void	file_to_param(char *line, t_param *param, int map)
{
	if (map)
		clean_and_exit(param, EMPTY_LINE_ERR, 0);
	if (!ft_strncmp(line, "R ", 2))
		get_resolution(line, param, &param->check[0], 'r');
	else if (!ft_strncmp(line, "NO ", 3))
		param->text.north.path = get_path(param, line, &param->check[1], 'n');
	else if (!ft_strncmp(line, "SO ", 3))
		param->text.south.path = get_path(param, line, &param->check[2], 's');
	else if (!ft_strncmp(line, "WE ", 3))
		param->text.west.path = get_path(param, line, &param->check[3], 'w');
	else if (!ft_strncmp(line, "EA ", 3))
		param->text.east.path = get_path(param, line, &param->check[4], 'e');
	else if (!ft_strncmp(line, "S ", 2))
		param->text.sprite.path = get_path(param, line, &param->check[5], 'S');
	else if (!ft_strncmp(line, "F ", 2))
		param->floor = parse_color(line, &param->check[6], 'f');
	else if (!ft_strncmp(line, "C ", 2))
		param->ceiling = parse_color(line, &param->check[7], 'c');
	else if (ft_strlen(line))
		param->check[8] = 'E';
	free(line);
}

void	add_new_map_line(t_param *param, int i, char *line, int *map)
{
	if (!(param->map[i] = trim_spaces(line)))
		clean_and_exit(param, MALLOC_ERR, 0);
	add_malloc_to_list(&(param->malloc_list), param->map[i]);
	free(line);
	*map = 1;
}

void	close_and_check_map(t_param *param, int i)
{
	if (i == 0)
		clean_and_exit(param, MISS_MAP_ERR, 0);
	param->map[i] = 0;
	close(param->fd);
	param->fd = -42;
	check_borders(param->map, param);
}

void	read_cub_file(char *path, t_param *param)
{
	char	*line;
	int		i;
	int		map;

	param->map_height = count_map_lines(path);
	if (!(param->map = (char **)malloc(sizeof(char *) *
		(param->map_height + 1))))
		clean_and_exit(param, MALLOC_ERR, 0);
	if (!add_malloc_to_list(&(param->malloc_list), param->map))
		clean_and_exit(param, MALLOC_ERR, 0);
	i = 0;
	map = 0;
	while (get_next_line(param->fd, &line) > 0)
	{
		if (*line == '1' || *line == '0')
			add_new_map_line(param, i++, line, &map);
		else
			file_to_param(line, param, map);
	}
	if (*line == '1' || *line == '0')
		add_new_map_line(param, i++, line, &map);
	else
		free(line);
	check_param_validity(param->check, param);
	close_and_check_map(param, i);
}
