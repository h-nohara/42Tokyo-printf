/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:23:21 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 17:47:45 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	int		ft_strnstr_memcmp(const void *s1, const void *s2, size_t n)
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

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t l2;

	l2 = 0;
	while (s2[l2])
		++l2;
	if (!l2)
		return (char *)s1;
	while (len >= l2)
	{
		len--;
		if (!ft_strnstr_memcmp(s1, s2, l2))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
