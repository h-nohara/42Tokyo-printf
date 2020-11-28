/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:02:57 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/11 17:26:17 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	copy(char *dest, char *start_at, char *end_before)
{
	while (start_at < end_before)
	{
		*dest = *start_at;
		start_at++;
		dest++;
	}
	*dest = 0;
}

static	int		get_count(char const *str, char c)
{
	int res;

	res = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str && *str != c)
				str++;
			res++;
		}
		str++;
	}
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		n;
	char	*start_at;

	n = get_count(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start_at = (char*)s;
			while (*s && *s != c)
				s++;
			arr[i] = (char *)malloc(sizeof(char) * (s - start_at + 1));
			if (!arr[i])
				return (NULL);
			copy((char*)arr[i++], (char*)start_at, (char*)s);
		}
		s++;
	}
	arr[i] = 0;
	return (arr);
}
