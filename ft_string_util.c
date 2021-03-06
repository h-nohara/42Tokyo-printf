/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:30:12 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 16:30:25 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nonnull_result(char *res, int is_cnull, int *count)
{
	ft_putstr_fd(res, 1);
	*count += ft_strlen(res);
	if (is_cnull == 1)
	{
		ft_putchar_fd(0, 1);
		ft_putstr_fd(res + ft_strlen(res) + 1, 1);
		*count += 1 + ft_strlen(res + ft_strlen(res) + 1);
	}
}

char	ft_is_format_code(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

char	*ft_ctos(char c)
{
	char *s;

	s = (char*)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*ft_concat_padding(char *param_str, size_t len, char c, int pad_right)
{
	char *additional_str;
	char *res;

	additional_str = (char*)malloc(sizeof(char) * (len + 1));
	if (!additional_str)
		return (NULL);
	additional_str = ft_memset(additional_str, c, len);
	additional_str[len] = '\0';
	if (pad_right == 0)
		res = ft_strjoin(additional_str, param_str);
	else
		res = ft_strjoin(param_str, additional_str);
	free(additional_str);
	if (res)
		return (res);
	else
		return (NULL);
}

int		ft_hex_is_zero(char *s)
{
	if (*s == '0' && ft_strlen(s) == 1)
		return (1);
	else
		return (0);
}
