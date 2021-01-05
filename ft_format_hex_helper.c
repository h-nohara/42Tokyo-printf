#include "ft_printf.h"

char	*ft_hex_check_zero_precise(char *param_str, t_params *params)
{
	int is_zero;

	is_zero = ft_hex_is_zero(param_str);
	if (params->precise == 0)
	{
		if (is_zero == 0)
			params->precise = 1;
		else
		{
			if (params->width == -1)
				return (ft_strdup(""));
			else
			{
				params->precise = 1;
				return (ft_strdup(" "));
			}
		}
	}
	else if (params->precise == -2 && is_zero == 1)
		return (ft_strdup(""));
	return (ft_strdup(param_str));
}
