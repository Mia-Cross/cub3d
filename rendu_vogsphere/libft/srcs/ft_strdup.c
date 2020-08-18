/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:49:11 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/27 17:05:31 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

char		*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (copy);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
