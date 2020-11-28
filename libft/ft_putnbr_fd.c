/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:50:52 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/22 13:46:05 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_put_a_nbr(int fd, int n)
{
	char c;

	c = n + '0';
	write(fd, &c, 1);
}

static	void	ft_put_pos_nbr(long n, int fd)
{
	if (n >= 10)
		ft_put_pos_nbr(n / 10, fd);
	ft_put_a_nbr(fd, n % 10);
}

void			ft_putnbr_fd(int n, int fd)
{
	long ln;

	ln = (long)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	ft_put_pos_nbr(ln, fd);
}
