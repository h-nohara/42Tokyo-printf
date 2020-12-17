/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:32:29 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:33:23 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptr_pad_zero(char *s, int len_zero_pad)
{
	if (ft_strlen(s) <= 0 || len_zero_pad <= 0)
		return (s);
	s = ft_concat_padding(s, len_zero_pad, '0', 0);
	s = ft_strjoin("0x", s);
	return (s);
}

char	*ft_format_ptr(char *param_str, t_params *params)
{
	int width;
	int len;
	int flag;

	width = params->width;
	param_str = ft_get_base_ptr_str(param_str, params->precise);
	len = ft_strlen(param_str);
	if (len >= width)
		return (param_str);
	else
	{
		flag = params->flag_minus;
		return (ft_concat_padding(param_str, width - len, ' ', flag));
	}
}

char	*ft_get_base_ptr_str(char *param_str, int precise)
{
	int len;

	if (ft_strlen(param_str) == 1 && param_str[0] == '0')
	{
		if (precise == -2 || precise == 0)
			return ("0x");
		else if (precise == -1)
			return ("0x0");
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
	return (param_str);
}
