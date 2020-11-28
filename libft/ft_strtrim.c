/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:02:19 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:49:07 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_trim_contain(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static	int	ft_trim_get_head(char const *s1, char const *set)
{
	int start;

	start = 0;
	while (s1[start])
	{
		if (ft_trim_contain(s1[start], set) == 0)
			break ;
		++start;
	}
	return (start);
}

static	int	ft_trim_get_tail(char const *s1, char const *set)
{
	int end;

	end = 0;
	while (s1[end])
		++end;
	--end;
	while (end >= 0)
	{
		if (ft_trim_contain(s1[end], set) == 0)
			break ;
		--end;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;
	int		j;

	start = ft_trim_get_head(s1, set);
	end = ft_trim_get_tail(s1, set);
	if (end < start)
		p = (char*)malloc(sizeof(char));
	else
		p = (char*)malloc(sizeof(char) * (end - start + 2));
	if (!p)
		return (NULL);
	j = 0;
	while (start <= end)
		p[j++] = s1[start++];
	p[j] = '\0';
	return (p);
}
