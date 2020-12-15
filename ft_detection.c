/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:32:09 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 18:31:15 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_detect_percent(char *s, t_list **lst)
{
	char *start;
	char *tmp;

	start = s;
	while (*s && *s != '%')
		++s;
	if (start != s)
	{
		tmp = ft_substr(start, 0, s - start);
		if (ft_lst_append(lst, tmp) == -1)
			return (NULL);
	}
	return (s);
}

char	*ft_detect_flag(char *s, t_plist *params)
{
	while (*s == '0' || *s == '-')
	{
		if (*s == '0')
			params->flag_zero = 1;
		else
			params->flag_minus = 1;
		++s;
	}
	return (s);
}

char	*ft_detect_width(char *s, t_plist *params, va_list *args)
{
	char *start;

	if (*s == '*')
	{
		params->width = va_arg(*args, int);
		if (params->width < 0)
		{
			params->width = -(params->width);
			params->flag_minus = 1;
		}
		++s;
	}
	start = s;
	while (ft_isdigit(*s))
		++s;
	if (s != start)
		params->width = ft_atoi(ft_substr(start, 0, s - start));
	return (s);
}

char	*ft_detect_precise(char *s, t_plist *params, va_list *args)
{
	char	*start;
	int		found;

	found = 0;
	if (*s == '.')
	{
		++s;
		if (*s == '*')
		{
			params->precise = va_arg(*args, int);
			if (params->precise < 0)
				params->precise = -1;
			found = 1;
			++s;
		}
		start = s;
		while (ft_isdigit(*s))
			++s;
		if (s == start && found == 0)
			params->precise = -2;
		else if (s != start)
			params->precise = ft_atoi(ft_substr(start, 0, s - start));
	}
	return (s);
}
