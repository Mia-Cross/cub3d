/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:47 by lemarabe          #+#    #+#             */
/*   Updated: 2020/02/28 14:33:10 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
t_list			*ft_lstnew(void *content);
void			ft_lstclear(t_list **lst, void (*del)(void *));
int				add_malloc_to_list(t_list **list, void *ptr);
void			free_malloc_list(t_list **list);
void			free_one_element(t_list **list, void *to_free);
void			print_addr_list(t_list **list);
void			ft_del_ptr(t_list **lst, void *to_del);

#endif
