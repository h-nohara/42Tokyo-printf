/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:12:09 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/11 12:23:19 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned nobj, unsigned size)
{
	unsigned	int	i;
	unsigned		nb;
	char			*p;

	i = 0;
	nb = size * nobj;
	p = (char*)malloc(nb);
	if (!p)
		return (NULL);
	while (i < nb)
		p[i++] = 0;
	return ((void*)p);
}
