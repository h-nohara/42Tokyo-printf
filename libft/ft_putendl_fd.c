/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:46:16 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/22 15:02:49 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t len;

	if (!s)
		return ;
	len = ft_strlen((const char*)s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
