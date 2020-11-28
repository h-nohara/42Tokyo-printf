/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:37:11 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 17:07:38 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	original_len;
	char	*p;
	size_t	i;

	if (!*s)
		return (ft_strdup(""));
	original_len = 0;
	while (s[original_len])
		++original_len;
	if (len <= 0 || start >= original_len)
		len = 0;
	if (original_len - (size_t)start < len)
		len = original_len - (size_t)start;
	p = (char*)malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
