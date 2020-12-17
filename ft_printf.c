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
	t_list		*lst;
	t_list		*has_null;

	va_start(args, fmt);
	lst = ft_lstnew(ft_strdup(""));
	has_null = ft_lstnew(ft_strdup("n"));
	if (!lst || !has_null)
		return (-1);
	while (1)
	{
		if ((fmt = ft_detect_percent(fmt, &lst)) == NULL)
			break ;
		if (ft_lst_append(&has_null, "n") == -1)
			break ;
		if ((fmt = ft_proc_format(fmt, &lst, &args, &has_null)) == NULL)
			break ;
	}
	return (ft_print_iter(lst, has_null));
}

char	ft_is_format_code(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

char	*ft_proc_format(char *s, t_list **lst, va_list *args, t_list **has_null)
{
	char	*tmp;
	t_params	*params;
	char	*null_yn;

	if (*s != '%')
		return (NULL);
	params = ft_init_params();
	++s;
	s = ft_detect_flag(s, params);
	s = ft_detect_width(s, params, args);
	s = ft_detect_precise(s, params, args);
	if (ft_is_format_code(*s))
		params->type = *(s++);
	else
		return (s);
	null_yn = ft_strdup("n");
	tmp = ft_get_arg(params->type, args, null_yn);
	tmp = ft_format(tmp, params);
	if (ft_lst_append(lst, tmp) == -1 || ft_lst_append(has_null, null_yn))
		return (NULL);
	return (s);
}

char	*ft_format(char *param_str, t_params *params)
{
	char type;

	type = params->type;
	if (type == 's' || type == '%' || type == 'c')
		return (ft_format_str(param_str, params));
	else if (type == 'd' || type == 'i' || type == 'u')
		return (ft_format_int(param_str, params));
	else if (type == 'x' || type == 'X')
		return (ft_format_hex(param_str, params));
	else if (type == 'p')
		return (ft_format_ptr(param_str, params));
	return (param_str);
}

char	*ft_get_arg(char type, va_list *args, char *is_contain_null)
{
	char	*param_str;
	int		c;

	if (type == 's')
		param_str = ft_va_arg_s(args);
	else if (type == 'c')
	{
		c = va_arg(*args, int);
		if (c == 0)
			*is_contain_null = 'y';
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
