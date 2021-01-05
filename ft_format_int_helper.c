/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:57:35 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/15 20:57:38 by hnohara          ###   ########.fr       */
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
