/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:20:42 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/22 13:47:50 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	int	i;
	char			*p;

	i = 0;
	while (s[i])
		++i;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		++i;
	}
	p[i] = 0;
	return (p);
}
