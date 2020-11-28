/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:25:46 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:22:07 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned	char	uc;
	unsigned	char	*us;

	us = s;
	uc = c;
	i = 0;
	while (i < n)
		us[i++] = uc;
	return (s);
}
