/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:31:29 by hnohara           #+#    #+#             */
/*   Updated: 2021/04/04 12:14:08 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = 0;
	while (*fmt)
	{
		if ((fmt = ft_detect_percent(fmt, &count)) == NULL)
			return (-1);
		if (!(*fmt))
			break ;
		if ((fmt = ft_proc_format(fmt, &args, &count)) == NULL)
			return (-1);
	}
	va_end(args);
	return (count);
}

char	*ft_proc_format(char *s, va_list *args, int *count)
{
	t_params	*params;
	int			count_add;

	if (*s != '%')
		return (NULL);
	params = ft_init_params();
	if (!params)
		return (NULL);
	++s;
	s = ft_detect_flag(s, params);
	s = ft_detect_width(s, params, args);
	s = ft_detect_precise(s, params, args);
	if (ft_is_format_code(*s))
		params->type = *(s++);
	else
		return (s);
	count_add = ft_getarg_format_print(params, args);
	free(params);
	if (count_add == -1)
		return (NULL);
	else
	{
		*count += count_add;
		return (s);
	}
}

int		ft_getarg_format_print(t_params *params, va_list *args)
{
	char	*param_str;
	int		has_null;
	int		count;

	has_null = 0;
	param_str = ft_get_arg(params->type, args, &has_null);
	if (!param_str)
		return (-1);
	count = ft_format(param_str, params, has_null);
	free(param_str);
	return (count);
}

int		ft_format(char *param_str, t_params *params, int is_cnull)
{
	char	type;
	char	*res;
	int		count;

	count = 0;
	type = params->type;
	res = ft_format_core(type, &param_str, &params, is_cnull);
	if (!res)
		return (-1);
	ft_print_nonnull_result(res, is_cnull, &count);
	free(res);
	return (count);
}

char	*ft_format_core(char type, char **s, t_params **p, int is_cnull)
{
	char		*res;
	char		*param_str;
	t_params	*params;

	param_str = *s;
	params = *p;
	if (is_cnull == 1)
		res = ft_format_cnull(params);
	else if (type == 's' || type == '%' || type == 'c')
		res = ft_format_str(param_str, params);
	else
	{
		if (params->precise == -2 && params->flag_zero)
			params->flag_zero = 0;
		if (type == 'd' || type == 'i' || type == 'u')
			res = ft_format_int(param_str, params);
		else if (type == 'x' || type == 'X')
			res = ft_format_hex(param_str, params);
		else if (type == 'p')
			res = ft_format_ptr(param_str, params);
		else
			res = ft_strdup("");
	}
	return (res);
}
