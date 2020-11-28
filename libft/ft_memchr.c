/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:33:04 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:35:45 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned	char	*s1;
	unsigned	char	uc;

	s1 = (unsigned char*)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == uc)
			return (s1 + i);
		++i;
	}
	return (NULL);
}
