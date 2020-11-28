/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:37:39 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 17:25:53 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static		long	ft_pow(unsigned int a, unsigned int n)
{
	long res;

	res = 1;
	while (n > 0)
	{
		res *= a;
		n--;
	}
	return (res);
}

static		int		ft_get_rank(long n)
{
	int rank;

	rank = 0;
	while (ft_pow(10, rank + 1) <= n)
		++rank;
	return (rank);
}

static		void	ft_itoa_putstr(long n, int rank, char *dest, int is_neg)
{
	long	base;
	int		i;

	i = 0;
	if (is_neg == 1)
	{
		n *= -1;
		dest[i++] = '-';
	}
	base = ft_pow(10, rank);
	while (base > 0)
	{
		if (n == 0)
			dest[i++] = '0';
		else
		{
			dest[i++] = '0' + n / base;
			n = n % base;
		}
		base = base / 10;
	}
	dest[i] = '\0';
}

char				*ft_itoa(int n)
{
	int		rank;
	long	ln;
	char	*res;
	int		size;

	ln = (long)n;
	rank = ft_get_rank(ln >= 0 ? ln : -ln);
	size = ln >= 0 ? rank + 2 : rank + 3;
	res = (char*)malloc(size);
	if (!res)
		return (NULL);
	ft_itoa_putstr(ln, rank, res, ln >= 0 ? 0 : 1);
	return (res);
}
