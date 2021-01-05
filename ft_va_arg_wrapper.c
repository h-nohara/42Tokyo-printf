/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:04 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/15 20:59:06 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_va_arg_s(va_list *args)
{
	char *s;

	s = va_arg(*args, char*);
	if (!s)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(s));
}

char	*ft_va_arg_p(va_list *args)
{
	void	*p;

	p = va_arg(*args, void*);
	if (p == NULL)
		return (ft_strdup("0"));
	else
		return (ft_convert_to_hex((int64_t)p, 0));
}
