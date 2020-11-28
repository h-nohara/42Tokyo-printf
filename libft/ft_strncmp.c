/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:56:08 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 16:01:04 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	i = 0;
	while (us1[i] != '\0' && us2[i] != '\0' && i < n && us1[i] == us2[i])
		i++;
	if (i == n)
		return (0);
	return (us1[i] - us2[i]);
}
