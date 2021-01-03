/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:43:13 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/03 18:43:54 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_lst	*ft_strlst_new(char *s, int has_null)
{
	t_str_lst *lst;

	lst = (t_str_lst*)malloc(sizeof(t_str_lst));
	if (!lst)
		return (NULL);
	lst->s = s;
	lst->has_null = has_null;
	lst->next = NULL;
	return (lst);
}

t_str_lst	*ft_strlst_last(t_str_lst *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		ft_strlst_add_back(t_str_lst **lst, t_str_lst *new)
{
	t_str_lst *last;

	if (!lst || !new)
		return ;
	last = ft_strlst_last(*lst);
	last->next = new;
}

void		ft_strlst_clear(t_str_lst **lst, void (*del)(void*))
{
	t_str_lst *tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst);
		(*del)((*lst)->s);
		*lst = (*lst)->next;
		free(tmp);
	}
}
