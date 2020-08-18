/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:32:51 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/28 15:10:17 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_param param;

	check_arguments(ac, av, &param);
	read_cub_file(av[1], &param);
	initialize_mlx(&param);
	ray_caster(&param);
	if (!param.create_bmp)
	{
		mlx_put_image_to_window(param.mlx_ptr, param.win.win_ptr,
		param.img_to_display.img_ptr, 0, 0);
		mlx_destroy_image(param.mlx_ptr, param.img_to_display.img_ptr);
	}
	else
		save_view_as_bmp(&param);
	mlx_do_key_autorepeatoff(param.mlx_ptr);
	mlx_hook(param.win.win_ptr, KEY_PRESS, (1L << 0), &key_press, &param);
	mlx_hook(param.win.win_ptr, KEY_RELEASE, (1L << 1), &key_release, &param);
	mlx_hook(param.win.win_ptr, CLOSE_BUTTON_EVENT, 0, &click_to_quit,
	&param);
	mlx_loop_hook(param.mlx_ptr, &key_loop, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
