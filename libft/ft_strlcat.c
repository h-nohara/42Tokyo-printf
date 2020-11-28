/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:15:29 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 15:48:13 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_init(unsigned int *i, unsigned int *j, int *res)
{
	*i = 0;
	*j = 0;
	*res = -1;
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned	int	i;
	unsigned	int	j;
	unsigned	int	len_src;
	int				res;

	ft_init(&i, &j, &res);
	len_src = 0;
	while (src[len_src])
		len_src++;
	while (dest[j] && j < size)
		j++;
	if (j + 1 > size)
		return (size + len_src);
	if (j + 1 <= size && size <= j + len_src)
		res = j + len_src;
	while (src[i] && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (res != -1)
		return (res);
	return (j);
}
