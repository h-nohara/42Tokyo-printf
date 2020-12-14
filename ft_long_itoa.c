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

#include "ft_printf.h"

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
	{
		++rank;
		if (ft_pow(10, rank) > LONG_MAX / 10)
			break ;
	}
	return (rank);
}

static		void	ft_itoa_putstr(long n, int rank, char *dest, int is_neg)
{
	long	base;
	int		i;

	i = 0;
	if (is_neg == 1)
		dest[i++] = '-';
	else
		n *= -1;
	base = ft_pow(10, rank);
	while (base > 0)
	{
		if (n == 0)
			dest[i++] = '0';
		else
		{
			dest[i++] = '0' + (n / base) * -1;
			n = n % base;
		}
		base = base / 10;
	}
	dest[i] = '\0';
}

char				*ft_long_itoa(long n)
{
	int		rank;
	char	*res;
	int		size;

	if (n == 0)
		return ("0");
	if (n > 0)
		rank = ft_get_rank(n);
	else
		rank = ft_get_rank((n / 10) * -1) + 1;
	size = n > 0 ? rank + 2 : rank + 3;
	res = (char*)malloc(size);
	if (!res)
		return (NULL);
	ft_itoa_putstr(n, rank, res, n < 0);
	return (res);
}
