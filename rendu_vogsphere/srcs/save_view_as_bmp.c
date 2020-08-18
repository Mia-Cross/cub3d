/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_view_as_bmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:00:27 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 18:54:46 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void	mlx_image_to_bmp(t_param *param, t_bmp *bmp)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	while (++j < param->win.screen_height)
	{
		i = -1;
		while (++i < param->win.screen_width)
		{
			x = i;
			y = param->win.screen_height - 1 - j;
			bmp->color = param->img_to_display.img_addr[x + y *
			param->win.screen_width];
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (param->win.screen_width * 3) % 4) % 4)
			write(bmp->fd, &bmp->pad, 1);
	}
}

void	file_info_to_header(t_param *param, t_bmp *bmp)
{
	int i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	bmp->info[12] = 1;
	bmp->info[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->header[2], bmp->size);
	set_header(&bmp->info[4], param->win.screen_width);
	set_header(&bmp->info[8], param->win.screen_height);
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void	save_view_as_bmp(t_param *param)
{
	t_bmp	bmp;
	int		img_size;

	img_size = 3 * param->win.screen_width * param->win.screen_height;
	bmp.size = 54 + img_size;
	bmp.img_ptr = ft_calloc(img_size, sizeof(char));
	bmp.fd = open("first_view.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	file_info_to_header(param, &bmp);
	mlx_image_to_bmp(param, &bmp);
	free(bmp.img_ptr);
	close(bmp.fd);
	clean_and_exit(param, BMP_EXIT_MSG, 1);
}
