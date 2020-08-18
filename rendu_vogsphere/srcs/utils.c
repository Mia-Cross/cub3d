/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:35:53 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:56:07 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_double_tab_index(double *values, int *index, int size)
{
	int i;

	if (!values || !index)
		return ;
	i = 0;
	while (i < size - 1)
	{
		while (values[i] < values[i + 1])
		{
			ft_swap_double(&values[i], &values[i + 1]);
			ft_swap(&index[i], &index[i + 1]);
			ft_sort_double_tab_index(values, index, size);
		}
		i++;
	}
}

int		rgb_to_int(int r, int g, int b)
{
	int result;

	result = 0;
	result += pow(16, 5) * (r / 16);
	result += pow(16, 4) * (r % 16);
	result += pow(16, 3) * (g / 16);
	result += pow(16, 2) * (g % 16);
	result += pow(16, 1) * (b / 16);
	result += pow(16, 0) * (b % 16);
	return (result);
}

int		check_extension(char *path)
{
	int len;

	len = ft_strlen(path);
	if (path[len - 4] != '.')
		return (0);
	if (path[len - 3] != 'c')
		return (0);
	if (path[len - 2] != 'u')
		return (0);
	if (path[len - 1] != 'b')
		return (0);
	return (1);
}

int		check_string(char *line)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || ft_isspace(line[i])))
			return (0);
		i++;
	}
	return (1);
}
