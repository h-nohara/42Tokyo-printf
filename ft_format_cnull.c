#include "ft_printf.h"

char	*ft_format_cnull(char *param_str, t_params *params)
{
	int width;

	width = params->width;
	if (width <= 0)
		width = 1;
	if (width == 1)
		return (ft_strdup(param_str));
	return (ft_concat_padding_cnull(width, params->flag_minus, params->flag_zero));
}

char	*ft_concat_padding_cnull(int width, int is_left, int is_zero)
{
	char	*res;
	int		i;
	char	c;

	i = 0;
	res = (char*)malloc(sizeof(char) * (width + 1));
	if (!res)
		return (NULL);
	if (is_left)
	{
		res[i++] = 0;
		while (i < width)
			res[i++] = ' ';
	}
	else
	{
		c = is_zero ? '0' : ' ';
		while (i < width - 1)
			res[i++] = c;
		res[i++] = 0;
	}
	res[i] = '\0';
	return (res);
}
