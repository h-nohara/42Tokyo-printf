/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:08:13 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/18 02:15:36 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

static	bool	ft_atoi_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (true);
	if (c == '\f' || c == '\v' || c == ' ')
		return (true);
	return (false);
}

int				ft_atoi(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_atoi_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (sign * result > INT_MAX)
			return (-1);
		if (sign * result < INT_MIN)
			return (0);
		i++;
	}
	return (sign * result);
}
