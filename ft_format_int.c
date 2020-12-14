/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:30:35 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 16:30:44 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_int(char *param_str, t_plist *params)
{
	int width;
	int precise;

	param_str = ft_int_check_zero_precise(param_str, params);
	width = params->width;
	precise = params->precise;
	if (precise == -1)
	{
		if (width == -1)
			return (param_str);
		else
			return (ft_format_int_w(param_str, params));
	}
	if (precise == -2)
	{
		if (width == -1)
			return (param_str);
		else
			return (ft_format_int_w(param_str, params));
	}
	if (width == -1)
		return (ft_format_int_p(param_str, params));
	else
		return (ft_format_int_wp(param_str, params));
}

char	*ft_int_check_zero_precise(char *param_str, t_plist *params)
{
	if (params->precise == 0)
	{
		if (param_str[0] != '0')
			params->precise = 1;
		else
		{
			if (params->width == -1)
				return ("");
			else
			{
				params->precise = 1;
				return (" ");
			}
		}
	}
	else if (params->precise == -2 && param_str[0] == '0')
		return ("");
	return (param_str);
}

char	*ft_int_pad_zero(char *s, int len_zero_pad)
{
	if (ft_strlen(s) <= 0)
		return (s);
	if (*s == '-')
		return (ft_strjoin("-", ft_concat_padding(++s, len_zero_pad, '0', 0)));
	else
		return (ft_concat_padding(s, len_zero_pad, '0', 0));
}

char	*ft_format_int_w(char *param_str, t_plist *params)
{
	int len;
	int len_padding;
	int flag;

	len = ft_strlen(param_str);
	if (len >= params->width)
		return (param_str);
	else
	{
		len_padding = params->width - len;
		if ((params->flag_zero == 1) && (params->flag_minus == 0))
			return (ft_int_pad_zero(param_str, len_padding));
		flag = params->flag_minus;
		return (ft_concat_padding(param_str, len_padding, ' ', flag));
	}
}

char	*ft_format_int_p(char *param_str, t_plist *params)
{
	int precise;
	int len_base;
	int is_neg;
	int len_zero_pad;

	precise = params->precise;
	is_neg = *param_str == '-';
	len_base = is_neg ? ft_strlen(param_str) - 1 : ft_strlen(param_str);
	if (len_base >= precise)
		return (param_str);
	len_zero_pad = precise - len_base;
	return (ft_int_pad_zero(param_str, len_zero_pad));
}

char	*ft_format_int_wp(char *s, t_plist *p)
{
	int precise;
	int len;
	int l;
	int is_neg;

	precise = p->precise;
	is_neg = *s == '-';
	len = ft_strlen(s);
	l = is_neg ? len - 1 : len;
	if (l < precise)
	{
		if (is_neg == 1)
			s = ft_strjoin("-", ft_concat_padding(++s, precise - l, '0', 0));
		else
			s = ft_concat_padding(s, precise - len, '0', 0);
		len = ft_strlen(s);
	}
	if (p->width <= len)
		return (s);
	else
		return (ft_concat_padding(s, p->width - len, ' ', p->flag_minus == 1));
}
