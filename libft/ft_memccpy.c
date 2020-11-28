/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:23:40 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:16:28 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned	char	*u_src;
	unsigned	char	*u_dest;

	u_src = (unsigned char*)src;
	u_dest = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		u_dest[i] = u_src[i];
		if (u_src[i] == (unsigned char)c)
			return (u_dest + i + 1);
		++i;
	}
	return (NULL);
}
