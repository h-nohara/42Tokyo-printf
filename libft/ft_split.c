/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:06:40 by hnohara           #+#    #+#             */
/*   Updated: 2020/11/18 02:58:36 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_seps_skipped_index(char const *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] == sep)
		i++;
	return (i);
}

static	char	**create_empty_container(size_t len)
{
	char **emp_container;

	emp_container = malloc(sizeof(char *) * (len + 1));
	if (emp_container == NULL)
		return (NULL);
	emp_container[len] = NULL;
	return (emp_container);
}

static	char	*substr_first_word(const char *str, const char sep, size_t *len)
{
	*len = 0;
	while (str[*len] != '\0' && str[*len] != sep)
		(*len)++;
	return (ft_substr(str, 0, *len));
}

static	char	**ft_split_recursive(char const *str, char sep, size_t len)
{
	char			**arr;
	char			*split_word;
	size_t			len_split_word;
	size_t			i;

	i = get_seps_skipped_index(str, sep);
	if (str[i] == '\0')
		return (create_empty_container(len));
	split_word = substr_first_word(str + i, sep, &len_split_word);
	if (split_word == NULL)
		return (NULL);
	i += len_split_word;
	arr = ft_split_recursive(str + i, sep, len + 1);
	if (arr == NULL)
	{
		free(split_word);
		return (NULL);
	}
	arr[len] = split_word;
	return (arr);
}

char			**ft_split(char const *str, char c)
{
	if (str == NULL)
		return (NULL);
	if (*str == '\0' || c == '\0')
		return (create_empty_container(0));
	return (ft_split_recursive(str, c, 0));
}
