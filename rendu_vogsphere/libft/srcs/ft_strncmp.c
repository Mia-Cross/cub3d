/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:21:53 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 19:59:02 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	unsigned char	*u1;
	unsigned char	*u2;

	if (!s1 || !s2)
		return (-1);
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (u1[i] != '\0' && u2[i] != '\0' && u1[i] == u2[i] && i < (n - 1))
		i++;
	if (u1[i] != u2[i])
		return (u1[i] - u2[i]);
	else if (i == (n - 1))
		return (0);
	else
		return (-1);
}
