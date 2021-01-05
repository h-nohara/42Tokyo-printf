/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:26:39 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/05 17:32:33 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_len_info	*info_new(void)
{
	t_fmt_len_info *info;

	info = (t_fmt_len_info*)malloc(sizeof(t_fmt_len_info));
	if (!info)
		return (NULL);
	info->len_all = 0;
	info->len_org = 0;
	info->len_org_conv = 0;
	info->len_zero_padding = 0;
	info->len_padding = 0;
	return (info);
}

char			*ft_format_str(char *param_str, t_params *params)
{
	t_fmt_len_info	*info;
	char			*converted_org;
	char			*res;
	int				len_pad;

	if (!(info = info_new()))
		return (NULL);
	info->len_org = ft_strlen(param_str);
	ft_get_len_s(params, info);
	converted_org = convert_org_str(param_str, info);
	if (!converted_org)
	{
		free(info);
		return (NULL);
	}
	len_pad = info->len_padding;
	if (len_pad <= 0)
		res = ft_strdup(converted_org);
	else if (params->flag_minus == 1)
		res = ft_concat_padding(converted_org, (size_t)(len_pad), ' ', 1);
	else if (params->flag_zero == 1)
		res = ft_concat_padding(converted_org, (size_t)(len_pad), '0', 0);
	else
		res = ft_concat_padding(converted_org, (size_t)(len_pad), ' ', 0);
	free(info);
	free(converted_org);
	return (res);
}

void			ft_get_len_s(t_params *p, t_fmt_len_info *info)
{
	int len_org;
	int width;
	int precise;

	len_org = info->len_org;
	width = p->width;
	precise = p->precise;
	width = (width == -1) ? 0 : width;
	if (precise == -1)
		precise = len_org;
	else if (precise == -2 && p->type == 's')
		precise = 0;
	else if (precise == -2 && (p->type == 'c' || p->type == '%'))
		precise = 1;
	info->len_org_conv = (precise > len_org) ? len_org : precise;
	if (info->len_org_conv >= width)
	{
		info->len_all = info->len_org_conv;
		info->len_zero_padding = 0;
		info->len_padding = 0;
		return ;
	}
	info->len_all = width;
	info->len_zero_padding = 0;
	info->len_padding = info->len_all - info->len_org_conv;
}

char			*convert_org_str(char *s, t_fmt_len_info *info)
{
	int len_org;
	int len_org_conv;

	len_org = info->len_org;
	len_org_conv = info->len_org_conv;
	if (len_org_conv == len_org)
		return (ft_strdup(s));
	else if (len_org_conv < len_org)
		return (ft_substr(s, 0, info->len_org_conv));
	else
		return (ft_concat_padding(s, info->len_zero_padding, '0', 0));
}
