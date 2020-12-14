/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:54:11 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 16:08:26 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_hex(char *param_str, t_plist *params)
{
	int width;
	int precise;

	param_str = ft_hex_check_zero_precise(param_str, params);
	width = params->width;
	precise = params->precise;
	if (precise == -1)
	{
		if (width == -1)
			return (param_str);
		else
			return (ft_format_hex_w(param_str, params));
	}
	if (precise == -2)
	{
		if (width == -1)
			return (param_str);
		else
			return (ft_format_hex_w(param_str, params));
	}
	if (width == -1)
		return (ft_format_hex_p(param_str, params));
	else
		return (ft_format_hex_wp(param_str, params));
}

char *ft_hex_check_zero_precise(char *param_str, t_plist *params)
{
	int is_zero;

	is_zero = ft_hex_is_zero(param_str);
	if (params->precise == 0)
	{
		if (is_zero == 0)
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
	else if (params->precise == -2 && is_zero == 1)
		return ("");
	return (param_str);
}

char	*ft_hex_pad_zero(char *s, int len_zero_pad)
{
	if (ft_strlen(s) <= 0)
		return (s);
	return (ft_concat_padding(s, len_zero_pad, '0', 0));
}

char	*ft_format_hex_w(char *param_str, t_plist *params)
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
			return (ft_hex_pad_zero(param_str, len_padding));
		flag = params->flag_minus;
		return (ft_concat_padding(param_str, len_padding, ' ', flag));
	}
}

char	*ft_format_hex_p(char *param_str, t_plist *params)
{
	int precise;
	int len;
	int len_zero_pad;

	precise = params->precise;
	len = ft_strlen(param_str);
	if (len >= precise)
		return (param_str);
	len_zero_pad = precise - len;
	return (ft_hex_pad_zero(param_str, len_zero_pad));
}

char	*ft_format_hex_wp(char *s, t_plist *params)
{
	int precise;
	int len;

	precise = params->precise;
	len = ft_strlen(s);
	if (len < precise)
	{
		s = ft_concat_padding(s, precise - len, '0', 0);
		len = ft_strlen(s);
	}
	if (params->width <= len)
		return (s);
	else
		return (ft_concat_padding(s, params->width - len, ' ', params->flag_minus == 1));
}
