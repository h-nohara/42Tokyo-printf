/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:31:29 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/03 18:45:53 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list		args;
	int count;

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

char	ft_is_format_code(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

char	*ft_proc_format(char *s, va_list *args, int *count)
{
	char		*tmp;
	t_params	*params;
	int			has_null;
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
	has_null = 0;
	tmp = ft_get_arg(params->type, args, &has_null);
	if (!tmp)
		return (NULL);
	count_add = ft_format(tmp, params, has_null);
	free(tmp);
	if (count_add == -1)
		return (NULL);
	else
	{
		*count += count_add;
		return (s);
	}
}

int	ft_format(char *param_str, t_params *params, int is_cnull)
{
	char type;
	char *res;
	int count;

	count = 0;
	if (is_cnull == 1)
		res = ft_format_cnull(params);
	type = params->type;
	if (type == 's' || type == '%' || type == 'c')
		res = ft_format_str(param_str, params);
	else if (type == 'd' || type == 'i' || type == 'u')
		res = ft_format_int(param_str, params);
	else if (type == 'x' || type == 'X')
		res = ft_format_hex(param_str, params);
	else if (type == 'p')
		res = ft_format_ptr(param_str, params);
	if (!res)
		return (-1);
	ft_putstr_fd(res, 1);
	count += ft_strlen(res);
	if (is_cnull == 1)
	{
		ft_putchar_fd('\0', 1);
		res += ft_strlen(res) + 1;
		ft_putstr_fd(res, 1);
		count += 1 + ft_strlen(res);
	}
	free(res);
	return (count);
}

char	*ft_get_arg(char type, va_list *args, int *has_null)
{
	char	*param_str;
	int		c;

	if (type == 's')
		param_str = ft_va_arg_s(args);
	else if (type == 'c')
	{
		c = va_arg(*args, int);
		if (c == 0)
			*has_null = 1;
		param_str = ft_ctos((char)c);
	}
	else if (type == 'd' || type == 'i')
		param_str = ft_itoa(va_arg(*args, int));
	else if (type == 'u')
		param_str = ft_long_itoa(va_arg(*args, unsigned int));
	else if (type == 'x' || type == 'X')
		param_str = ft_convert_to_hex(va_arg(*args, long), type == 'X');
	else if (type == 'p')
		param_str = ft_va_arg_p(args);
	else if (type == '%')
		param_str = ft_strdup("%");
	else
		param_str = ft_strdup("");
	return (param_str);
}
