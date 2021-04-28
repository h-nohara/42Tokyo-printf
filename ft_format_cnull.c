/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_cnull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:41:13 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/03 18:50:07 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_cnull(t_params *params)
{
	int width;
	int flag_minus;
	int flag_zero;

	width = params->width;
	if (width <= 0)
		width = 1;
	if (width == 1)
		return (ft_ctos(0));
	flag_minus = params->flag_minus;
	flag_zero = params->flag_zero;
	return (ft_concat_padding_cnull(width, flag_minus, flag_zero));
}

char	*ft_concat_padding_cnull(int width, int is_left, int is_zero)
{
	char	*res;
	int		i;
	char	c;

	i = 0;
	res = (char*)malloc(sizeof(char) * (width + 1));
	if (!res)
		return (NULL);
	if (is_left)
	{
		res[i++] = 0;
		while (i < width)
			res[i++] = ' ';
	}
	else
	{
		c = is_zero ? '0' : ' ';
		while (i < width - 1)
			res[i++] = c;
		res[i++] = 0;
	}
	res[i] = '\0';
	return (res);
}
