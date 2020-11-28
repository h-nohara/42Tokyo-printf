/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:45:00 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/11 13:53:38 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n1;
	int		n2;
	char	*p;

	n1 = 0;
	while (s1[n1])
		++n1;
	n2 = 0;
	while (s2[n2++])
		++n1;
	p = (char*)malloc(sizeof(char) * (n1 + 1));
	if (!p)
		return (NULL);
	n1 = -1;
	while (s1[++n1])
		p[n1] = s1[n1];
	n2 = -1;
	while (s2[++n2])
		p[n1++] = s2[n2];
	p[n1] = '\0';
	return (p);
}
