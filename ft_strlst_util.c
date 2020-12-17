/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlist_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:31:48 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:37:19 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_one(void *content)
{
	if (!content)
		return ;
}

void	ft_free_strlist(t_str_lst *lst)
{
	ft_strlst_clear(&lst, &ft_free_one);
}

int		ft_strlst_append(t_str_lst **lst, char *s, int has_null)
{
	t_str_lst *new_lst;

	new_lst = ft_strlst_new(s, has_null);
	if (!new_lst)
		return (-1);
	ft_strlst_add_back(lst, new_lst);
	return (0);
}

int		ft_print_iter(t_str_lst *lst)
{
	int		n;
	char	*s;
	int		len;

	n = 0;
	while (lst)
	{
		s = (char*)(lst->s);
		ft_putstr_fd(s, 1);
		len = ft_strlen(lst->s);
		n += len;
		if (lst->has_null == 1)
		{
			ft_putchar_fd('\0', 1);
			n += 1;
			s += len + 1;
			ft_putstr_fd(s, 1);
			n += ft_strlen(s);
		}
		lst = lst->next;
	}
	return (n);
}
