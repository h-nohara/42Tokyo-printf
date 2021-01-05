/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:30:35 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/05 15:59:10 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_int(char *param_str, t_params *params)
{
	char	*zero_checked_str;
	int		width;
	int		precise;
	char	*res;

	zero_checked_str = ft_int_check_zero_precise(param_str, params);
	if (!zero_checked_str)
		return (NULL);
	width = params->width;
	precise = params->precise;
	res = ft_format_int_core(zero_checked_str, width, precise, params);
	free(zero_checked_str);
	return (res);
}

char	*ft_format_int_core(char *s, int width, int precise, t_params *params)
{
	char *res;

	if (precise == -1)
	{
		if (width == -1)
			res = ft_strdup(s);
		else
			res = ft_format_int_w(s, params);
	}
	else if (precise == -2)
	{
		if (width == -1)
			res = ft_strdup(s);
		else
			res = ft_format_int_w(s, params);
	}
	else if (width == -1)
		res = ft_format_int_p(s, params);
	else
		res = ft_format_int_wp(s, params);
	return (res);
}

char	*ft_format_int_w(char *param_str, t_params *params)
{
	int len;
	int len_padding;
	int flag;

	len = ft_strlen(param_str);
	if (len >= params->width)
		return (ft_strdup(param_str));
	else
	{
		len_padding = params->width - len;
		if ((params->flag_zero == 1) && (params->flag_minus == 0))
			return (ft_int_pad_zero(param_str, len_padding));
		else
		{
			flag = params->flag_minus;
			return (ft_concat_padding(param_str, len_padding, ' ', flag));
		}
	}
}

char	*ft_format_int_p(char *param_str, t_params *params)
{
	int precise;
	int len_base;
	int is_neg;
	int len_zero_pad;

	precise = params->precise;
	is_neg = *param_str == '-';
	len_base = is_neg ? ft_strlen(param_str) - 1 : ft_strlen(param_str);
	if (len_base >= precise)
		return (ft_strdup(param_str));
	len_zero_pad = precise - len_base;
	return (ft_int_pad_zero(param_str, len_zero_pad));
}
