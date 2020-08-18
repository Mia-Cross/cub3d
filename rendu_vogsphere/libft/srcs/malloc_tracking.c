/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:42:57 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/29 15:54:36 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>
#include <unistd.h>

int		add_malloc_to_list(t_list **list, void *ptr)
{
	t_list *new_elem;

	new_elem = ft_lstnew(ptr);
	if (*list == NULL)
		*list = new_elem;
	else
		ft_lstadd_back(list, new_elem);
	return (1);
}

void	free_malloc_list(t_list **list)
{
	t_list *current;
	t_list *tmp;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		tmp = current->next;
		free(current->content);
		free(current);
		current = tmp;
	}
}

void	free_one_element(t_list **list, void *to_free)
{
	t_list *current;
	t_list *save_last;

	if (!list)
		return ;
	current = *list;
	save_last = current;
	while (current)
	{
		if (current->content == to_free)
		{
			free(current->content);
			if (current == *list)
				*list = current->next;
			else
				save_last->next = current->next;
			free(current);
			return ;
		}
		save_last = current;
		current = current->next;
	}
}

void	print_addr_list(t_list **list)
{
	t_list	*current;
	int		i;

	current = *list;
	i = 0;
	while (current)
	{
		printf("[%d]->%p\n", i++, current->content);
		current = current->next;
	}
}
