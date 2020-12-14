/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:26:39 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:36:17 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_len_info	*info_new(void)
{
	t_fmt_len_info *info;

	info = (t_fmt_len_info*)malloc(sizeof(t_fmt_len_info));
	info->len_all = 0;
	info->len_org = 0;
	info->len_org_conv = 0;
	info->len_zero_padding = 0;
	info->len_padding = 0;
	return (info);
}

char			*ft_format_str(char *param_str, t_plist *params)
{
	t_fmt_len_info	*info;
	char			*converted_org;
	char			*res;
	int				len_pad;

	info = info_new();
	info->len_org = ft_strlen(param_str);
	get_block_len_str(params, info);
	converted_org = convert_org_str(param_str, info);
	len_pad = info->len_padding;
	if (len_pad <= 0)
		return (converted_org);
	if (params->flag_minus == 1)
		res = ft_concat_padding(converted_org, (size_t)(len_pad), ' ', 1);
	else if (params->flag_zero == 1)
		res = ft_concat_padding(converted_org, (size_t)(len_pad), '0', 0);
	else
		res = ft_concat_padding(converted_org, (size_t)(len_pad), ' ', 0);
	return (res);
}

void			get_block_len_str(t_plist *params, t_fmt_len_info *info)
{
	int len_org;
	int width;
	int precise;

	len_org = info->len_org;
	width = params->width;
	precise = params->precise;
	width = (width == -1) ? 0 : width;
	if (precise == -1)
		precise = len_org;
	else if (precise == -2 && params->type == 's')
		precise = 0;
	else if (precise == -2 && (params->type == 'c' || params->type == '%'))
		precise = 1;
	info->len_org_conv = (precise > len_org) ? len_org : precise;
	if (info->len_org_conv >= width)
	{
		info->len_all = info->len_org_conv;
		info->len_zero_padding = 0;
		info->len_padding = 0;
	}
	else
	{
		info->len_all = width;
		info->len_zero_padding = 0;
		info->len_padding = info->len_all - info->len_org_conv;
	}
}
