/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:57:35 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/05 17:33:36 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int_pad_zero(char *s, int len_zero_pad)
{
	char *tmp;
	char *res;

	if (ft_strlen(s) <= 0)
		return (ft_strdup(s));
	if (*s == '-')
	{
		tmp = ft_concat_padding(++s, len_zero_pad, '0', 0);
		if (!tmp)
			return (NULL);
		res = ft_strjoin("-", tmp);
		free(tmp);
		return (res);
	}
	else
		return (ft_concat_padding(s, len_zero_pad, '0', 0));
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

char	*ft_format_int_wp(char *s, t_params *p)
{
	int		len;
	int		is_neg;
	char	*res;
	char	*res2;

	is_neg = *s == '-';
	len = ft_strlen(s);
	res = ft_format_int_wp_core(s, &len, p->precise, is_neg);
	if (p->width <= len)
		return (res);
	else
	{
		res2 = ft_concat_padding(res, p->width - len, ' ', p->flag_minus == 1);
		free(res);
		return (res2);
	}
}

char	*ft_format_int_wp_core(char *s, int *len, int precise, int is_neg)
{
	int		len_digit;
	char	*tmp;
	char	*res;

	len_digit = is_neg ? *len - 1 : *len;
	if (len_digit < precise)
	{
		if (is_neg == 1)
		{
			tmp = ft_concat_padding(++s, precise - len_digit, '0', 0);
			if (!tmp)
				return (NULL);
			res = ft_strjoin("-", tmp);
			free(tmp);
		}
		else
			res = ft_concat_padding(s, precise - *len, '0', 0);
		if (!res)
			return (NULL);
		*len = ft_strlen(res);
		return (res);
	}
	else
		return (ft_strdup(s));
}
