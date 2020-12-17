/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:54:11 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:34:31 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_hex(char *param_str, t_params *params)
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

char	*ft_hex_check_zero_precise(char *param_str, t_params *params)
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

char	*ft_format_hex_w(char *param_str, t_params *params)
{
	int len;
	int len_pad;
	int flag;

	len = ft_strlen(param_str);
	if (len >= params->width)
		return (param_str);
	else
	{
		len_pad = params->width - len;
		if ((params->flag_zero == 1) && (params->flag_minus == 0))
		{
			if (len > 0)
				return (ft_concat_padding(param_str, len_pad, '0', 0));
			else
				return (param_str);
		}
		flag = params->flag_minus;
		return (ft_concat_padding(param_str, len_pad, ' ', flag));
	}
}

char	*ft_format_hex_p(char *param_str, t_params *params)
{
	int precise;
	int len;
	int len_zero_pad;

	precise = params->precise;
	len = ft_strlen(param_str);
	if (len >= precise)
		return (param_str);
	len_zero_pad = precise - len;
	if (len > 0)
		return (ft_concat_padding(param_str, len_zero_pad, '0', 0));
	else
		return (param_str);
}

char	*ft_format_hex_wp(char *s, t_params *params)
{
	int precise;
	int len;
	int flag;

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
	{
		flag = params->flag_minus == 1;
		return (ft_concat_padding(s, params->width - len, ' ', flag));
	}
}
