/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:54:11 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/06 02:18:54 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_hex(char *param_str, t_params *params)
{
	int		width;
	int		precise;
	char	*s;
	char	*res;

	s = ft_hex_check_zero_precise(param_str, params);
	if (!s)
		return (NULL);
	width = params->width;
	precise = params->precise;
	res = ft_format_hex_core(s, width, precise, params);
	free(s);
	return (res);
}

char	*ft_format_hex_core(char *s, int width, int precise, t_params *params)
{
	if (precise == -1)
	{
		if (width == -1)
			return (ft_strdup(s));
		else
			return (ft_format_hex_w(s, params));
	}
	else if (precise == -2)
	{
		if (width == -1)
			return (ft_strdup(s));
		else
			return (ft_format_hex_w(s, params));
	}
	else
	{
		if (width == -1)
			return (ft_format_hex_p(s, params));
		else
			return (ft_format_hex_wp(s, params));
	}
}

char	*ft_format_hex_w(char *param_str, t_params *params)
{
	int len;
	int len_pad;
	int flag;

	len = ft_strlen(param_str);
	if (len >= params->width)
		return (ft_strdup(param_str));
	else
	{
		len_pad = params->width - len;
		if ((params->flag_zero == 1) && (params->flag_minus == 0))
		{
			if (len > 0)
				return (ft_concat_padding(param_str, len_pad, '0', 0));
			else
				return (ft_strdup(param_str));
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
		return (ft_strdup(param_str));
	len_zero_pad = precise - len;
	if (len > 0)
		return (ft_concat_padding(param_str, len_zero_pad, '0', 0));
	else
		return (ft_strdup(param_str));
}

char	*ft_format_hex_wp(char *s, t_params *params)
{
	int		precise;
	int		len;
	int		flag;
	char	*tmp;
	char	*res;

	precise = params->precise;
	len = ft_strlen(s);
	if (len < precise)
		tmp = ft_concat_padding(s, precise - len, '0', 0);
	else
		tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	len = ft_strlen(tmp);
	if (params->width <= len)
		return (tmp);
	else
	{
		flag = params->flag_minus == 1;
		res = ft_concat_padding(tmp, params->width - len, ' ', flag);
		free(tmp);
		return (res);
	}
}
