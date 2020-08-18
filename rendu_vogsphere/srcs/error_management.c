/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:35:52 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:58:32 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_error_msg_tab(char *msg[8])
{
	msg[0] = RES_ERR;
	msg[1] = N_KEY_ERR;
	msg[2] = SO_KEY_ERR;
	msg[3] = W_KEY_ERR;
	msg[4] = E_KEY_ERR;
	msg[5] = SP_KEY_ERR;
	msg[6] = FLOOR_ERR;
	msg[7] = CEIL_ERR;
}

void	build_dd_error_msg_tab(char *msg[8])
{
	msg[0] = DD_RES_ERR;
	msg[1] = DD_N_KEY_ERR;
	msg[2] = DD_SO_KEY_ERR;
	msg[3] = DD_W_KEY_ERR;
	msg[4] = DD_E_KEY_ERR;
	msg[5] = DD_SP_KEY_ERR;
	msg[6] = DD_FLOOR_ERR;
	msg[7] = DD_CEIL_ERR;
}

void	build_miss_error_msg_tab(char *msg[8])
{
	msg[0] = MISS_RES_ERR;
	msg[1] = MISS_N_KEY_ERR;
	msg[2] = MISS_SO_KEY_ERR;
	msg[3] = MISS_W_KEY_ERR;
	msg[4] = MISS_E_KEY_ERR;
	msg[5] = MISS_SP_KEY_ERR;
	msg[6] = MISS_FLOOR_ERR;
	msg[7] = MISS_CEIL_ERR;
}

void	check_param_validity(char check[9], t_param *param)
{
	char	*ref;
	char	*err_msg[8];
	char	*dd_msg[8];
	char	*miss_msg[8];
	int		i;

	if (check[8] == 'E')
		clean_and_exit(param, UNKNOWN_KEY_ERR, 0);
	ref = "rnsweSfc";
	build_error_msg_tab(err_msg);
	build_dd_error_msg_tab(dd_msg);
	build_miss_error_msg_tab(miss_msg);
	i = 0;
	while (i < 8)
	{
		if (check[i] == 'D')
			clean_and_exit(param, dd_msg[i], 0);
		else if (check[i] == 'M')
			clean_and_exit(param, miss_msg[i], 0);
		else if (check[i] != ref[i])
			clean_and_exit(param, err_msg[i], 0);
		i++;
	}
}
