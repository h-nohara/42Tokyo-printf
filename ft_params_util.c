/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:44:35 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/03 18:44:42 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*ft_init_params(void)
{
	t_params *lst;

	lst = (t_params*)malloc(sizeof(t_params));
	if (!lst)
		return (NULL);
	lst->flag_zero = 0;
	lst->flag_minus = 0;
	lst->width = -1;
	lst->precise = -1;
	lst->type = 0;
	return (lst);
}
