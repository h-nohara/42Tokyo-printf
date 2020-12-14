/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plist_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:28:45 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 16:29:32 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_plist	*ft_init_params(void)
{
	t_plist *lst;

	lst = (t_plist*)malloc(sizeof(t_plist));
	if (!lst)
		return (NULL);
	lst->flag_zero = 0;
	lst->flag_minus = 0;
	lst->width = -1;
	lst->precise = -1;
	lst->type = 0;
	return (lst);
}
