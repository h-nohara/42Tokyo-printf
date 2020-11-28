/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:03:03 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:27:41 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		++s;
	}
	if (*s == c)
		return ((char*)s);
	return (last);
}
