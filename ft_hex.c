/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:30:57 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:35:08 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		get_hex_len(long n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 16;
		++i;
	}
	return (i);
}

char			*ft_convert_to_hex(long n, int is_upper)
{
	char	*hex_ord;
	char	*res;
	int		i;
	int		size;

	if (is_upper == 0)
		hex_ord = "0123456789abcdef";
	else
		hex_ord = "0123456789ABCDEF";
	size = get_hex_len(n) + 1;
	res = (char*)malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	i = size - 1;
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i--] = hex_ord[n % 16];
		n /= 16;
	}
	return (res);
}
