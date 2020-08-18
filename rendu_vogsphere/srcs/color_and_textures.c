/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:48:32 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:59:00 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_valid_color(int i)
{
	if (i < 0 || i > 255)
		return (0);
	return (1);
}

int		parse_color(char *line, char *indic, char id)
{
	int i;
	int j;
	int rgb[4];
	int color;

	i = 1;
	j = -1;
	ft_memset(rgb, -1, 16);
	color = -1;
	while (line[i] && ++j < 4)
	{
		i = ft_atoi_ptr(line, i, &rgb[j]);
		if (line[i] && line[i] == ',')
			i++;
	}
	if (is_valid_color(rgb[0]) && is_valid_color(rgb[1]) &&
	is_valid_color(rgb[2]) && rgb[3] == -1)
		color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	if (*indic == id || *indic == 'D')
		*indic = 'D';
	else if (color == -1)
		*indic = 'E';
	else
		*indic = id;
	return (color);
}

char	*get_path(t_param *param, char *line, char *indic, char id)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 2;
	path = NULL;
	while (line[i] == ' ')
		i++;
	if (*indic != id && *indic != 'D')
	{
		tmp = new_str_from(line, i);
		path = ft_strtrim(tmp, " ");
		free(tmp);
		add_malloc_to_list(&(param->malloc_list), path);
	}
	else
		*indic = 'D';
	if (!(*indic == id || *indic == 'D'))
		*indic = id;
	return (path);
}

void	load_single_texture(t_image *texture, t_param *param)
{
	if (!(texture->img_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
		texture->path, &texture->width, &texture->height)))
		clean_and_exit(param, XPM_ERR, 0);
	if (!(texture->img_addr = (int *)mlx_get_data_addr(texture->img_ptr,
		&texture->b_p_p, &texture->size_line, &texture->endian)))
		clean_and_exit(param, DATA_ADDR_ERR, 0);
}

void	load_all_textures(t_param *param)
{
	load_single_texture(&param->text.north, param);
	load_single_texture(&param->text.east, param);
	load_single_texture(&param->text.south, param);
	load_single_texture(&param->text.west, param);
	load_single_texture(&param->text.sprite, param);
}
