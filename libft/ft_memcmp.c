/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:43:58 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/07 18:55:03 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	int		i;
	unsigned	char	*us1;
	unsigned	char	*us2;

	if (n == 0)
		return (0);
	i = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (us1[i] - us2[i]);
}
