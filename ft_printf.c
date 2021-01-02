/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:31:29 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:39:17 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list		args;
	t_str_lst		*lst;

	va_start(args, fmt);
	lst = ft_strlst_new("", 0);
	if (!lst)
		return (-1);
	while (1)
	{
		if ((fmt = ft_detect_percent(fmt, &lst)) == NULL)
			break ;
		if ((fmt = ft_proc_format(fmt, &lst, &args)) == NULL)
			break ;
	}
	return (ft_print_iter(lst));
}

char	ft_is_format_code(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

char	*ft_proc_format(char *s, t_str_lst **lst, va_list *args)
{
	char	*tmp;
	t_params	*params;
	int	has_null;

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
	tmp = ft_format(tmp, params, has_null);
	if (tmp == NULL)
		return (NULL);
	if (ft_strlst_append(lst, tmp, has_null) == -1)
		return (NULL);
	return (s);
}

char	*ft_format(char *param_str, t_params *params, int is_cnull)
{
	char type;

	type = params->type;
	if (type == 's' || type == '%' || type == 'c')
		return (ft_format_str(param_str, params, is_cnull));
	else if (type == 'd' || type == 'i' || type == 'u')
		return (ft_format_int(param_str, params));
	else if (type == 'x' || type == 'X')
		return (ft_format_hex(param_str, params));
	else if (type == 'p')
		return (ft_format_ptr(param_str, params));
	return (param_str);
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
