/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:05:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 12:12:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back_gnl(t_strlist **alst, t_strlist *new)
{
	t_strlist	*tmp;

	if (!new || !alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_strlist	*ft_lstnew_gnl(char *content)
{
	t_strlist	*elt;
	int			i;

	if (!content)
		return (NULL);
	elt = (t_strlist *)malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(elt->content))
	{
		free(elt);
		return (NULL);
	}
	i = -1;
	while (++i < BUFFER_SIZE)
		(elt->content)[i] = content[i];
	while (i < BUFFER_SIZE)
		(elt->content)[i++] = 0;
	elt->next = NULL;
	return (elt);
}

void	ft_lstclear_gnl(t_strlist **lst)
{
	t_strlist	*tmpb;

	if (!lst)
		return ;
	if (!*lst)
	{
		lst = NULL;
		return ;
	}
	while (*lst)
	{
		tmpb = *lst;
		*lst = (*lst)->next;
		free((tmpb)->content);
		free(tmpb);
	}
	*lst = NULL;
}

char	*return_error(t_strlist *list, char *buffer, int sz, int cleanbuff)
{
	if (cleanbuff == 1)
		ft_buffmove(buffer, sz);
	ft_lstclear_gnl(&list);
	return (NULL);
}
