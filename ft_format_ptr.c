/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:32:29 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/05 15:59:45 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptr_pad_zero(char *s, int len_zero_pad)
{
	char *tmp;
	char *res;

	if (ft_strlen(s) <= 0 || len_zero_pad <= 0)
		return (ft_strdup(s));
	else
	{
		tmp = ft_concat_padding(s, len_zero_pad, '0', 0);
		if (!tmp)
			return (NULL);
		res = ft_strjoin("0x", tmp);
		free(tmp);
		return (res);
	}
}

char	*ft_format_ptr(char *param_str, t_params *params)
{
	int		width;
	int		len;
	int		flag;
	char	*base_str;
	char	*res;

	width = params->width;
	base_str = ft_get_base_ptr_str(param_str, params->precise);
	if (!base_str)
		return (NULL);
	len = ft_strlen(base_str);
	if (len >= width)
		res = ft_strdup(base_str);
	else
	{
		flag = params->flag_minus;
		res = ft_concat_padding(base_str, width - len, ' ', flag);
	}
	free(base_str);
	return (res);
}

char	*ft_get_base_ptr_str(char *param_str, int precise)
{
	int len;

	if (ft_strlen(param_str) == 1 && param_str[0] == '0')
	{
		if (precise == -2 || precise == 0)
			return (ft_strdup("0x"));
		else if (precise == -1)
			return (ft_strdup("0x0"));
		else
			return (ft_concat_padding("0x", precise, '0', 1));
	}
	else
	{
		len = ft_strlen(param_str);
		if (precise > len)
			return (ft_ptr_pad_zero(param_str, precise - len));
		else
			return (ft_strjoin("0x", param_str));
	}
	return (ft_strdup(param_str));
}
