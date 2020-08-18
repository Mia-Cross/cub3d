/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:20:00 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:51:37 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_buffer(int **screen_buf, int width)
{
	int i;

	i = -1;
	if (!screen_buf)
		return ;
	if (*screen_buf)
	{
		while (++i < width)
			free(screen_buf[i]);
	}
	free(screen_buf);
}

void	clean_and_exit(t_param *param, char *msg, int to_clean)
{
	int		output;

	if (to_clean == 1)
	{
		mlx_clear_window(param->mlx_ptr, param->win.win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win.win_ptr);
	}
	free_malloc_list(&(param->malloc_list));
	system("leaks cub3D");
	output = 1;
	if (!(msg == EXIT_MSG || msg == BMP_EXIT_MSG))
	{
		ft_putendl_fd("Error", 1);
		output = 2;
	}
	ft_putendl_fd(msg, output);
	exit(0);
}
