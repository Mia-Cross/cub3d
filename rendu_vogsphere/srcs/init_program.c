/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:53:12 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:57:38 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arguments(int ac, char **av, t_param *param)
{
	ft_bzero(param, sizeof(t_param));
	if (ac < 2)
		clean_and_exit(param, MISS_ARG_ERR, 0);
	if (ac > 3)
		clean_and_exit(param, MULT_ARGS_ERR, 0);
	if (!check_extension(av[1]))
		clean_and_exit(param, CUB_EXT_ERR, 0);
	if (av[2])
	{
		if (ft_strcmp(av[2], "--save"))
			clean_and_exit(param, SAVE_ARG_ERR, 0);
		param->create_bmp = 1;
	}
	if ((param->fd = open(av[1], O_RDONLY)) == -1)
		clean_and_exit(param, INVALID_FILE_ERR, 0);
	ft_memset(param->check, 'M', 9);
}

void	initialize_screen_buf(t_param *param)
{
	int i;

	if (!(param->screen_buf = (int **)malloc(sizeof(int *) *
	param->win.screen_width)))
		clean_and_exit(param, MALLOC_ERR, 1);
	add_malloc_to_list(&(param->malloc_list), param->screen_buf);
	i = 0;
	while (i < param->win.screen_width)
	{
		if (!(param->screen_buf[i++] = (int *)malloc(sizeof(int) *
			param->win.screen_height)))
			clean_and_exit(param, MALLOC_ERR, 1);
		add_malloc_to_list(&(param->malloc_list), param->screen_buf[i - 1]);
	}
}

void	initialize_vectors(t_raycast *algo, char **matrix)
{
	algo->player_dir = get_player_direction(matrix);
	algo->player_pos.x = get_player_pos_x(matrix) + 0.5;
	algo->player_pos.y = get_player_pos_y(matrix) + 0.5;
	algo->cam_plane.x = (double)(-FOV / 100.0 * algo->player_dir.y);
	algo->cam_plane.y = (double)(FOV / 100.0 * algo->player_dir.x);
}

void	initialize_mlx(t_param *param)
{
	param->mlx_ptr = NULL;
	param->mvt.move_speed = SPEED;
	param->mvt.cam_speed = CAM_SPEED;
	if (!(param->mlx_ptr = mlx_init()))
		clean_and_exit(param, MLX_INIT_ERR, 0);
	if (param->win.screen_width > 2560)
		param->win.screen_width = 2560;
	if (param->win.screen_height > 1440)
		param->win.screen_height = 1440;
	if (!(param->win.win_ptr = mlx_new_window(param->mlx_ptr,
	param->win.screen_width, param->win.screen_height, "cub3d")))
		clean_and_exit(param, WINDOW_ERR, 0);
	load_all_textures(param);
	initialize_screen_buf(param);
	set_sprites(&param->sprite, param);
	initialize_vectors(&param->algo, param->map);
}
