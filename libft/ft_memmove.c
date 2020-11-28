/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:59:26 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/16 17:39:07 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned	int	i;
	char			*dest1;
	char			*src1;
	int				to_copy_reverse;

	if ((dest == NULL && src == NULL) || (dest == src))
		return (dest);
	dest1 = (char*)dest;
	src1 = (char*)src;
	to_copy_reverse = src1 < dest1 ? 1 : 0;
	i = -1;
	while (++i < n)
	{
		if (to_copy_reverse == 0)
			dest1[i] = src1[i];
		else
			dest1[n - 1 - i] = src1[n - 1 - i];
	}
	return (dest);
}
