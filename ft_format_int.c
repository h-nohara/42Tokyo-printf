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
	if (precise == -1)
	{
		if (width == -1)
			res = ft_strdup(zero_checked_str);
		else
			res = ft_format_int_w(zero_checked_str, params);
	}
	else if (precise == -2)
	{
		if (width == -1)
			res = ft_strdup(zero_checked_str);
		else
			res = ft_format_int_w(zero_checked_str, params);
	}
	else if (width == -1)
		res = ft_format_int_p(zero_checked_str, params);
	else
		res = ft_format_int_wp(zero_checked_str, params);
	free(zero_checked_str);
	return (res);
}

char	*ft_int_check_zero_precise(char *param_str, t_params *params)
{
	if (params->precise == 0)
	{
		if (param_str[0] != '0')
			params->precise = 1;
		else
		{
			if (params->width == -1)
				return (ft_strdup(""));
			else
			{
				params->precise = 1;
				return (ft_strdup(" "));
			}
		}
	}
	else if (params->precise == -2 && param_str[0] == '0')
		return (ft_strdup(""));
	return (ft_strdup(param_str));
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

char	*ft_format_int_wp(char *s, t_params *p)
{
	int		precise;
	int		len;
	int		l;
	int		is_neg;
	char	*tmp;
	char	*res;
	char	*res2;

	precise = p->precise;
	is_neg = *s == '-';
	len = ft_strlen(s);
	l = is_neg ? len - 1 : len;
	if (l < precise)
	{
		if (is_neg == 1)
		{
			tmp = ft_concat_padding(++s, precise - l, '0', 0);
			if (!tmp)
				return (NULL);
			res = ft_strjoin("-", tmp);
			free(tmp);
		}
		else
			res = ft_concat_padding(s, precise - len, '0', 0);
		if (!res)
			return (NULL);
		len = ft_strlen(res);
	}
	else
	{
		res = ft_strdup(s);
		if (!res)
			return (NULL);
	}
	if (p->width <= len)
		return (res);
	else
	{
		res2 = ft_concat_padding(res, p->width - len, ' ', p->flag_minus == 1);
		free(res);
		return (res2);
	}
}
